#!/usr/bin/env python

import rospy
from geometry_msgs.msg import PoseStamped

def move_end_effector():
    # Initialize the ROS node
    rospy.init_node('move_end_effector_node', anonymous=True)

    # Create a publisher for the equilibrium_pose topic
    pub = rospy.Publisher('/cartesian_impedance_example_controller/equilibrium_pose', PoseStamped, queue_size=10)

    # Define the rate (10 Hz)
    rate = rospy.Rate(10)

    # Create the PoseStamped message
    equilibrium_pose = PoseStamped()

    # Fill in the header information
    equilibrium_pose.header.stamp = rospy.Time.now()
    equilibrium_pose.header.frame_id = "gripper"  # Use the correct reference frame

    # Set the desired position of the end-effector (x, y, z)
    equilibrium_pose.pose.position.x = 0.5
    equilibrium_pose.pose.position.y = 0.0
    equilibrium_pose.pose.position.z = 0.4

    # Set the desired orientation (quaternion)
    equilibrium_pose.pose.orientation.x = 0.0
    equilibrium_pose.pose.orientation.y = 0.0
    equilibrium_pose.pose.orientation.z = 0.0
    equilibrium_pose.pose.orientation.w = 1.0

    # Allow time for connections
    rospy.sleep(1)

    # Publish the pose continuously
    while not rospy.is_shutdown():
        # Update the timestamp
        equilibrium_pose.header.stamp = rospy.Time.now()

        # Publish the PoseStamped message
        pub.publish(equilibrium_pose)
        rospy.loginfo("Published equilibrium pose: %s", equilibrium_pose)

        # Sleep to maintain the desired rate
        rate.sleep()

if __name__ == '__main__':
    try:
        move_end_effector()
    except rospy.ROSInterruptException:
        pass
