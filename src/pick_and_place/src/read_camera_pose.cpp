#include <ros/ros.h>
#include <tf/transform_listener.h>

void getCameraPose() {
    // Initialize the ROS node
    ros::NodeHandle nh;

    // Create a TransformListener object
    tf::TransformListener listener;

    // Wait for the transform to become available
    ros::Duration(4.0).sleep();  // Ensure the transform is available before proceeding

    try {
        // Get the transformation between '/world' and '/camera_link'
        tf::StampedTransform transform;
        listener.lookupTransform("/world", "/camera_link", ros::Time(0), transform);

        // Print the translation and rotation
        ROS_INFO("Translation: [%f, %f, %f]", transform.getOrigin().x(), transform.getOrigin().y(), transform.getOrigin().z());
        ROS_INFO("Rotation (Quaternion): [%f, %f, %f, %f]", transform.getRotation().x(), transform.getRotation().y(), transform.getRotation().z(), transform.getRotation().w());
    } catch (tf::TransformException& ex) {
        ROS_ERROR("Transformation not available: %s", ex.what());
    }
}

int main(int argc, char** argv) {
    // Initialize the ROS node
    ros::init(argc, argv, "get_camera_pose_node");

    // Run the function to get the camera pose
    getCameraPose();

    return 0;
}
