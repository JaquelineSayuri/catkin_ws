#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from geometry_msgs.msg import PoseStamped
from poses import get_poses
from sensor_msgs.msg import PointCloud2, JointState
import sensor_msgs.point_cloud2 as pc2
import tf

class Robot:
    """
    Docstring: A brief description of the class.
    """

    def __init__(self):#, arg1, arg2):
        """
        Constructor: Initializes the object's attributes.
        """
        self.target_pose_pub = rospy.Publisher('/cartesian_impedance_example_controller/equilibrium_pose', PoseStamped, queue_size=10)

    def move_to_pose(self, pose_msg):
        """
        Method: Publish a pose into the /cartesian_impedance_example_controller/equilibrium_pose topic to move the robot
        """
        rospy.loginfo(f"Moving to pose: {self.format_pose(pose_msg)}")
        self.target_pose_pub.publish(pose_msg)

        while not self.reached_target_pose():
            rospy.sleep(0.25)

        rospy.loginfo(f"Sucessfully moved to pose: {self.format_pose(pose_msg)}")

    def format_pose(self, pose_msg):
        """
        Formats the position and orientation of a Pose message.

        Args:
            pose: A geometry_msgs/PoseStamped message.
        """
        position_str = (
            f"position: {pose_msg.pose.position.x:.2f} "
            f"{pose_msg.pose.position.y:.2f} "
            f"{pose_msg.pose.position.z:.2f}"
        )
        orientation_str = (
            f"orientation: {pose_msg.pose.orientation.x:.2f} "
            f"{pose_msg.pose.orientation.y:.2f} "
            f"{pose_msg.pose.orientation.z:.2f} "
            f"{pose_msg.pose.orientation.w:.2f}"
        )
        return f"{position_str} {orientation_str}"

    def open_gripper(self):#, arg1, arg2):
        """
        Method: Performs another action on the object.
        """
        rospy.loginfo("Opening gripper")
        rospy.loginfo("Sucessfully opened gripper")
        pass

    def close_gripper(self):#, arg1, arg2):
        """
        Method: Performs another action on the object.
        """
        rospy.loginfo("Closing gripper")
        rospy.loginfo("Sucessfully closed gripper")
        pass

    def get_camera_pose(self):
        """
        Method: Performs another action on the object.
        """
        rospy.loginfo("Getting camera pose")
        # Create a TransformListener object
        listener = tf.TransformListener()

        # Wait for the transform to become available
        listener.waitForTransform('/world', '/camera_link', rospy.Time(), rospy.Duration(4.0))

        try:
            # Get the transformation between '/world' and '/camera_frame' (replace with your frames)
            (trans, rot) = listener.lookupTransform('/world', '/camera_link', rospy.Time(0))

            rospy.loginfo("Translation: %s", str(trans))  # Translation (x, y, z)
            rospy.loginfo("Rotation (Quaternion): %s", str(rot))  # Rotation (x, y, z, w)
            rospy.loginfo("Sucessfully got camera pose")

            return (trans, rot)

        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            rospy.logerr("Transformation not available")
            rospy.loginfo("Could not get camera pose")

            return None
        
    def get_velocity(self):
        """
        Method: Performs another action on the object.
        """
        #rospy.loginfo("Getting velocity")
        joint_states_sub = rospy.Subscriber("/franka_state_controller/joint_states", JointState, self.joint_states_callback) 
        rospy.wait_for_message("/franka_state_controller/joint_states", JointState, timeout=5)
        #rospy.loginfo("Sucessfully got velocity")

    def joint_states_callback(self, data):
        self.velocity = data.velocity

    def reached_target_pose(self):
        """
        Method: Performs another action on the object.
        """
        self.get_velocity()
        for vel in self.velocity:
            if vel > 0.01:
                return False

        return True


class VisionSystem:
    """
    Docstring: A brief description of the class.
    """

    def __init__(self):#, arg1, arg2):
        """
        Constructor: Initializes the object's attributes.
        """
        self.point_cloud = None

    def get_rgb_image(self):#, arg1, arg2):
        """
        Method: Performs a specific action on the object.
        """
        rospy.loginfo("Getting RGB image")
        rospy.loginfo("Sucessfully got RGB image")
        pass

    def get_depth_image(self):#, arg1, arg2):
        """
        Method: Performs another action on the object.
        """
        rospy.loginfo("Getting depth image")
        rospy.loginfo("Sucessfully got depth image")
        pass

    def get_point_cloud(self):
        """
        Method: Performs another action on the object.
        """
        rospy.loginfo("Getting depth image")
        point_cloud_sub = rospy.Subscriber("/camera/depth/points", PointCloud2, self.point_cloud_callback) 
        rospy.wait_for_message("/camera/depth/points", PointCloud2, timeout=5)  # Wait for a message
        rospy.loginfo("Sucessfully got depth image")
        
        return self.point_cloud

    def point_cloud_callback(self, data):
        self.point_cloud = pc2.read_points(data, field_names=("x", "y", "z"), skip_nans=True)


def main():
    robot = Robot()
    vision_system = VisionSystem()

    rospy.init_node('main_node')

    rate = rospy.Rate(0.5)

    poses = get_poses()

    while not rospy.is_shutdown():
        for pose in poses[:3]:

            pose_msg = PoseStamped()
            pose_msg.header.stamp = rospy.Time.now()
            pose_msg.header.frame_id = pose["frame_id"]
            pose_msg.pose.position.x = pose["position"]["x"]
            pose_msg.pose.position.y = pose["position"]["y"]
            pose_msg.pose.position.z = pose["position"]["z"]
            pose_msg.pose.orientation.x = pose["orientation"]["x"]
            pose_msg.pose.orientation.y = pose["orientation"]["y"]
            pose_msg.pose.orientation.z = pose["orientation"]["z"]
            pose_msg.pose.orientation.w = pose["orientation"]["w"]

            robot.move_to_pose(pose_msg)

            #read and store point cloud
            point_cloud = vision_system.get_point_cloud()

            #read and store camera pose
            cam_pose = robot.get_camera_pose()

            rate.sleep()

if __name__ == '__main__':
    main()