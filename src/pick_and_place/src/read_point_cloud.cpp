#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/point_cloud2_iterator.h>

void pointCloudCallback(const sensor_msgs::PointCloud2ConstPtr& msg) {
    // Create an iterator for the point cloud data
    sensor_msgs::PointCloud2Iterator<float> iter_x(*msg, "x");
    sensor_msgs::PointCloud2Iterator<float> iter_y(*msg, "y");
    sensor_msgs::PointCloud2Iterator<float> iter_z(*msg, "z");

    // Iterate through the points and process them
    for (size_t i = 0; i < msg->width * msg->height; ++i, ++iter_x, ++iter_y, ++iter_z) {
        float x = *iter_x;
        float y = *iter_y;
        float z = *iter_z;

        ROS_INFO("Point: x=%.2f, y=%.2f, z=%.2f", x, y, z);
        // Process the point cloud data here (e.g., filtering, clustering, etc.)
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "point_cloud_subscriber");
    ros::NodeHandle nh;

    // Subscribe to the point cloud topic
    ros::Subscriber sub = nh.subscribe("/camera/depth/points", 10, pointCloudCallback);

    ros::spin();
    return 0;
}
