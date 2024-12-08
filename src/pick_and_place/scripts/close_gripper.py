#!/usr/bin/env python
import rospy
import actionlib
from control_msgs.msg import GripperCommandAction, GripperCommandGoal

def gripper_client():
    # Initialize the ROS node
    rospy.init_node('franka_gripper_client')

    # Create an action client
    client = actionlib.SimpleActionClient('/franka_gripper/gripper_action', GripperCommandAction)

    # Wait for the action server to be available
    rospy.loginfo("Waiting for the action server to start...")
    client.wait_for_server()

    # Create a goal to send to the action server
    goal = GripperCommandGoal()
    goal.command.position = 0   # 4 cm gripper width
    goal.command.max_effort = 50.0  # Maximum effort

    # Send the goal and wait for result
    rospy.loginfo("Sending goal to gripper...")
    client.send_goal(goal)
    client.wait_for_result()

    # Print the result
    result = client.get_result()
    rospy.loginfo("Gripper action result: %s", result)

if __name__ == '__main__':
    try:
        gripper_client()
    except rospy.ROSInterruptException:
        pass
