#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <std_msgs/Float32.h>

class ImageConverter
{
  ros::NodeHandle nh_;
  image_transport::ImageTransport it_;
  image_transport::Subscriber image_sub_;
  ros::Publisher centerx_pub_,centery_pub_,angle_pub_;
  cv_bridge::CvImagePtr cv_ptr;
  cv_bridge::CvImagePtr original_ptr;
  int thresh = 75;
  bool IsRect=0;
  int AreaThreshMin = 6000;
  int AreaThreshMax = 9000;	
  std::vector<std::vector<cv::Point> > contours;
  cv::Point2f vtx[4];
  std_msgs::Float32 centerx,centery,angle;
  char TrackbarName[50];
  const int slider_max = 500;

public:
  ImageConverter()
    : it_(nh_)
  {
    // Subscribe to input video feed and publish output video feed
    //image_sub_ = it_.subscribe("/camera/color/image_raw", 1,&ImageConverter::imageCb, this); //For Actual Hardware
    image_sub_ = it_.subscribe("/my_gen3/camera/image_raw", 1,&ImageConverter::imageCb, this); //For Gazebo Simulation
    centerx_pub_ = nh_.advertise<std_msgs::Float32>("/opencv/centerx", 1000);
    centery_pub_ = nh_.advertise<std_msgs::Float32>("/opencv/centery", 1000);
    angle_pub_ = nh_.advertise<std_msgs::Float32>("/opencv/angle", 1000);

    cv::namedWindow("Original Image with Overlay");
    cv::namedWindow("Binary Image - Canny Edge Detection");
    
    cv::createTrackbar("Canny threshold","Binary Image - Canny Edge Detection", &thresh, slider_max, NULL);
  }

  ~ImageConverter()
  {
    cv::destroyWindow("Original Image with Overlay");
    cv::destroyWindow("Binary Image - Canny Edge Detection");
  }

  void imageCb(const sensor_msgs::ImageConstPtr& msg)
  {
    try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
      original_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }
    
    cv::cvtColor(cv_ptr->image, cv_ptr->image, cv::COLOR_BGR2GRAY);
    
    cv::medianBlur(cv_ptr->image, cv_ptr->image, 9);

    cv::Canny(cv_ptr->image, cv_ptr->image, thresh, thresh * 2);    

    cv::imshow("Binary Image - Canny Edge Detection", cv_ptr->image); 
    
    cv::findContours(cv_ptr->image, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    
    
    if (contours.size() > 0)
    {
	    std::vector<std::vector<cv::Point> > contours_poly(contours.size());
	    cv::RotatedRect boundRect;
	    
            IsRect = 0;
	    for (size_t i = 0; i < contours.size(); i++)
	    {

		cv::approxPolyDP(contours[i], contours_poly[i], 3, true);
		boundRect = cv::minAreaRect(contours_poly[i]);

		//ROS_INFO("Area = %f", ((boundRect.size.height)*(boundRect.size.width)));
		if (((boundRect.size.height)*(boundRect.size.width)) > AreaThreshMin && ((boundRect.size.height)*(boundRect.size.width)) < AreaThreshMax)
		{		
			IsRect = 1;
			break;
		}	
	    }
	    
            if (IsRect)
            {
		    // Draw lines only for the original object
		    boundRect.points(vtx);
		    cv::Mat drawing = cv::Mat::zeros(cv_ptr->image.size(), CV_8UC3);
		    for (size_t i = 0; i < 4; i++)
			cv::line(original_ptr->image, vtx[i], vtx[(i + 1) % 4], cv::Scalar(0, 0, 255), 3, cv::LINE_AA);
		    
		    
		    if (boundRect.size.width > boundRect.size.height)
		    {
			    boundRect.angle = -180-boundRect.angle;
		    }
		    else
		    {
			    boundRect.angle = -90-boundRect.angle;
		    }

		    centerx.data = boundRect.center.y;
		    centery.data = boundRect.center.x;
		    angle.data = boundRect.angle;	

		    // Output modified video stream
		    centerx_pub_.publish(centerx);
		    centery_pub_.publish(centery);
		    angle_pub_.publish(angle);
		    
		     
		    ROS_INFO("y = %f x = %f angle = %f", boundRect.center.y,boundRect.center.x,boundRect.angle);
            }
    }
    
    // Update GUI Window
    cv::imshow("Original Image with Overlay", original_ptr->image);
    cv::waitKey(100);		
  }
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "detect_object");
  ImageConverter ic;
  ros::spin();
  return 0;
}
