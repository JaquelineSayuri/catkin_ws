#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from geometry_msgs.msg import PoseStamped

def main():
    rospy.init_node('main_node')
    robot_commands_publisher = rospy.Publisher('/robot_commands', String, queue_size=1)
    vision_commands_publisher = rospy.Publisher('/vision_system_commands', String, queue_size=1)
    pose_publisher = rospy.Publisher('/robot_goal_pose', PoseStamped, queue_size=1)

    rate = rospy.Rate(10)

    pose1 = PoseStamped()
    pose1.header.stamp = rospy.Time.now()
    pose1.header.frame_id = "gripper" 

    # Set the desired position of the end-effector (x, y, z)
    pose1.pose.position.x = 0.1
    pose1.pose.position.y = 0.0
    pose1.pose.position.z = 0.615

    # Set the desired orientation (quaternion)
    pose1.pose.orientation.x = 0.0
    pose1.pose.orientation.y = 0.0
    pose1.pose.orientation.z = 0.0
    pose1.pose.orientation.w = 0.0

    pose2 = PoseStamped()
    pose2.header.stamp = rospy.Time.now()
    pose2.header.frame_id = "gripper" 

    # Set the desired position of the end-effector (x, y, z)
    pose2.pose.position.x = 0.2
    pose2.pose.position.y = -0.1
    pose2.pose.position.z = 0.615

    # Set the desired orientation (quaternion)
    pose2.pose.orientation.x = 0.0
    pose2.pose.orientation.y = 0.0
    pose2.pose.orientation.z = 0.0
    pose2.pose.orientation.w = 0.0

    pose3 = PoseStamped()
    pose3.header.stamp = rospy.Time.now()
    pose3.header.frame_id = "gripper" 

    # Set the desired position of the end-effector (x, y, z)
    pose3.pose.position.x = 0.2
    pose3.pose.position.y = 0.1
    pose3.pose.position.z = 0.59

    # Set the desired orientation (quaternion)
    pose3.pose.orientation.x = 0.0
    pose3.pose.orientation.y = 0.0
    pose3.pose.orientation.z = 0.0
    pose3.pose.orientation.w = 0.0

    while not rospy.is_shutdown():
        for pose in (pose1, pose2, pose3):
            pose_publisher.publish(pose)

            command = "move_to_pose"
            robot_commands_publisher.publish(String(data=command))

            rospy.loginfo(f"Published command: {command}")
            rospy.loginfo(f"Published pose: {pose}")

            rospy.sleep(1)

            #read and store point cloud
            command = "get_point_cloud"
            vision_commands_publisher.publish(String(data=command))

            rospy.loginfo(f"Published command: {command}")
            
            rospy.sleep(1)

            #read and store camera pose
            #command = "get_camera_pose"
            #command_publisher.publish(String(data=command))

            #rospy.loginfo(f"Published command: {command}")

            #rate.sleep()

if __name__ == '__main__':
    main()