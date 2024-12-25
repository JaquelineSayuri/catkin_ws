#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from geometry_msgs.msg import PoseStamped

class Robot:
    """
    Docstring: A brief description of the class.
    """

    def __init__(self):#, arg1, arg2):
        """
        Constructor: Initializes the object's attributes.
        """
        self.target_pose_pub = rospy.Publisher('/cartesian_impedance_example_controller/equilibrium_pose', PoseStamped, queue_size=10)
        self.target_pose = None
        print("Setting target_pose:", self.target_pose)

    def move_to_pose(self, pose):
        """
        Method: Publish a pose into the /cartesian_impedance_example_controller/equilibrium_pose topic to move the robot
        """
        print("Moving to pose")
        self.target_pose = pose
        self.target_pose_pub.publish(self.target_pose)
        rospy.loginfo("Published pose: %s", self.target_pose)

    def open_gripper(self):#, arg1, arg2):
        """
        Method: Performs another action on the object.
        """
        print("Opening gripper")
        pass

    def close_gripper(self):#, arg1, arg2):
        """
        Method: Performs another action on the object.
        """
        print("Closing gripper")
        pass

    def get_camera_pose(self):#, arg1, arg2):
        """
        Method: Performs another action on the object.
        """
        print("Getting camera pose")
        pass

class RobotNode:
    def __init__(self):
        rospy.init_node('robot_node')
        self.robot = Robot()  # Create an instance of your Robot class
        self.pose_subscriber = rospy.Subscriber('/robot_goal_pose', PoseStamped, self.pose_callback)
        self.command_subscriber = rospy.Subscriber('/robot_commands', String, self.command_callback)
        
    def pose_callback(self, data):
        self.target_pose = data

    def command_callback(self, data):
        if data.data == 'move_to_pose':
            self.robot.move_to_pose(self.target_pose)
        elif data.data == 'open_gripper':
            self.robot.open_gripper()
        elif data.data == 'close_gripper':
            self.robot.close_gripper()
        elif data.data == 'get_camera_pose':
            self.robot.get_camera_pose()

if __name__ == '__main__':
    node = RobotNode()
    rospy.spin() 