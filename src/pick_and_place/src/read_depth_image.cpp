#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

void depthImageCallback(const sensor_msgs::ImageConstPtr& msg) {
    try {
        // Convert the ROS image message to an OpenCV image (CV_32FC1 for depth in meters)
        cv::Mat depth_image = cv_bridge::toCvShare(msg, "32FC1")->image;

        // Display the depth image
        cv::imshow("Depth Image", depth_image);
        cv::waitKey(1);
    } catch (cv_bridge::Exception& e) {
        ROS_ERROR("CvBridge Error: %s", e.what());
    }
}

int main(int argc, char** argv) {
    // Initialize the ROS node
    ros::init(argc, argv, "depth_image_subscriber");

    ros::NodeHandle nh;

    // Subscribe to the depth image topic
    ros::Subscriber sub = nh.subscribe("/camera/depth/image_raw", 10, depthImageCallback);

    // Start the ROS event loop
    ros::spin();

    // Close OpenCV windows when the node exits
    cv::destroyAllWindows();

    return 0;
}
