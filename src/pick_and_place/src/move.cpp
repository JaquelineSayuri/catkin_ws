#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>

void moveEndEffector() {
    // Initialize the ROS node
    ros::NodeHandle nh;
    ROS_INFO("Starting the move end effector node...");

    // Create a publisher for the equilibrium_pose topic
    ros::Publisher pub = nh.advertise<geometry_msgs::PoseStamped>("/cartesian_impedance_example_controller/equilibrium_pose", 10);

    // Set the loop rate (10 Hz)
    ros::Rate rate(10);

    // Create the PoseStamped message
    geometry_msgs::PoseStamped equilibrium_pose;

    // Fill in the header information
    equilibrium_pose.header.frame_id = "gripper";  // Use the correct reference frame
    equilibrium_pose.header.stamp = ros::Time::now();

    // Set the desired position of the end-effector (x, y, z)
    equilibrium_pose.pose.position.x = 0.5;
    equilibrium_pose.pose.position.y = 0.0;
    equilibrium_pose.pose.position.z = 0.4;

    // Set the desired orientation (quaternion)
    equilibrium_pose.pose.orientation.x = 0.0;
    equilibrium_pose.pose.orientation.y = 0.0;
    equilibrium_pose.pose.orientation.z = 0.0;
    equilibrium_pose.pose.orientation.w = 1.0;  // Use 1.0 for a neutral orientation (no rotation)

    // Allow time for connections
    ros::Duration(1).sleep();

    // Publish the pose continuously
    while (ros::ok()) {
        // Update the timestamp
        equilibrium_pose.header.stamp = ros::Time::now();

        // Publish the PoseStamped message
        pub.publish(equilibrium_pose);
        ROS_INFO("Published equilibrium pose: [%f, %f, %f]", 
                  equilibrium_pose.pose.position.x,
                  equilibrium_pose.pose.position.y,
                  equilibrium_pose.pose.position.z);

        // Sleep to maintain the desired rate
        rate.sleep();
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "move_end_effector_node");

    try {
        moveEndEffector();
    } catch (const ros::Exception& e) {
        ROS_ERROR("ROS Exception: %s", e.what());
    }

    return 0;
}