#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <control_msgs/GripperCommandAction.h>

void gripperClient() {
    // Initialize the ROS node
    ros::NodeHandle nh;
    ROS_INFO("Starting the gripper client...");

    // Create an action client
    actionlib::SimpleActionClient<control_msgs::GripperCommandAction> client("/franka_gripper/gripper_action", true);

    // Wait for the action server to be available
    ROS_INFO("Waiting for the action server to start...");
    client.waitForServer();

    // Create a goal to send to the action server
    control_msgs::GripperCommandGoal goal;
    goal.command.position = 0.0;  // 0 m (fully closed gripper width)
    goal.command.max_effort = 50.0;  // Maximum effort in N

    // Send the goal and wait for the result
    ROS_INFO("Sending goal to gripper...");
    client.sendGoal(goal);

    // Wait for the action to complete
    client.waitForResult();

    // Check the result
    if (client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
        ROS_INFO("Gripper action succeeded.");
    } else {
        ROS_WARN("Gripper action failed: %s", client.getState().toString().c_str());
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "franka_gripper_client");

    try {
        gripperClient();
    } catch (const ros::Exception& e) {
        ROS_ERROR("ROS Exception: %s", e.what());
    }

    return 0;
}
