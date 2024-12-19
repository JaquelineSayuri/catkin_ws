#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <control_msgs/GripperCommandAction.h>

void gripperClient() {
    // Create an action client
    actionlib::SimpleActionClient<control_msgs::GripperCommandAction> client("/franka_gripper/gripper_action", true);

    // Wait for the action server to start
    ROS_INFO("Waiting for the action server to start...");
    client.waitForServer();

    // Create a goal to send to the action server
    control_msgs::GripperCommandGoal goal;
    goal.command.position = 0.04;  // 4 cm gripper width
    goal.command.max_effort = 50.0;  // Maximum effort

    // Send the goal and wait for result
    ROS_INFO("Sending goal to gripper...");
    client.sendGoal(goal);
    client.waitForResult();

    // Print the result
    if (client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
        ROS_INFO("Gripper action succeeded.");
    } else {
        ROS_WARN("Gripper action failed: %s", client.getState().toString().c_str());
    }
}

int main(int argc, char** argv) {
    // Initialize the ROS node
    ros::init(argc, argv, "franka_gripper_client");

    try {
        gripperClient();
    } catch (const ros::Exception& e) {
        ROS_ERROR("ROS Exception: %s", e.what());
    }

    return 0;
}
