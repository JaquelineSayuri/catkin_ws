#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void imageCallback(const sensor_msgs::ImageConstPtr& msg) {
    try {
        // Convert the ROS Image message to an OpenCV image
        cv_bridge::CvImagePtr cv_image_ptr = cv_bridge::toCvCopy(msg, "bgr8");
        cv::Mat cv_image = cv_image_ptr->image;

        // Display the image using OpenCV
        cv::imshow("Camera Image", cv_image);
        cv::waitKey(1);
    } catch (cv_bridge::Exception& e) {
        ROS_ERROR("CvBridge Error: %s", e.what());
        return;
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "image_subscriber_node");
    ros::NodeHandle nh;

    // Subscribe to the image topic
    std::string image_topic = "/camera/rgb/image_raw";  // Replace with your actual topic name
    ros::Subscriber sub = nh.subscribe(image_topic, 10, imageCallback);

    // Spin to keep the node running
    ros::spin();

    // Clean up OpenCV windows
    cv::destroyAllWindows();

    return 0;
}
