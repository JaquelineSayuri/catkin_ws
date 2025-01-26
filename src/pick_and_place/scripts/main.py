#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from geometry_msgs.msg import PoseStamped
from poses import get_poses
from sensor_msgs.msg import PointCloud2, JointState, PointField
import sensor_msgs.point_cloud2 as pc2
import tf2_ros
import tf
from tf2_sensor_msgs.tf2_sensor_msgs import do_transform_cloud
import numpy as np
from scipy.spatial import KDTree

class Robot:
    """
    Docstring: A brief description of the class.
    """

    def __init__(self):#, arg1, arg2):
        """
        Constructor: Initializes the object's attributes.
        """
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer)

        self.trials = 0

        self.target_pose_pub = rospy.Publisher('/cartesian_impedance_example_controller/equilibrium_pose', PoseStamped, queue_size=10)

        self.joint_st_sub = rospy.Subscriber("/franka_state_controller/joint_states", JointState, self.joint_states_callback)
        rospy.wait_for_message("/franka_state_controller/joint_states", JointState, timeout=5)

        self.joint_st_desired_sub = rospy.Subscriber("/franka_state_controller/joint_states_desired", JointState, self.joint_states_desired_callback)
        rospy.wait_for_message("/franka_state_controller/joint_states_desired", JointState, timeout=5)


    def get_transform(self, target_frame, source_frame, stamp):
        """
        Method: Get the transform between the source and target frames
        """
        transform = self.tf_buffer.lookup_transform(
            target_frame=target_frame,
            source_frame=source_frame,
            time=stamp,
            timeout=rospy.Duration(1.0)
        )
    
        return transform

    def move_to_pose(self, pose_msg):
        """
        Method: Publish a pose into the /cartesian_impedance_example_controller/equilibrium_pose topic to move the robot
        """
        rospy.loginfo(f"Moving to pose: {self.format_pose(pose_msg)}")
        self.target_pose_pub.publish(pose_msg)

        while not self.started_moving():
            self.target_pose_pub.publish(pose_msg)
            rospy.sleep(0.2)

        while not self.reached_target_pose():
            rospy.sleep(0.2)

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
        listener.waitForTransform('/world', '/camera_depth_link', rospy.Time(), rospy.Duration(4.0))

        try:
            # Get the transformation between '/world' and '/camera_frame' (replace with your frames)
            (trans, rot) = listener.lookupTransform('/world', '/camera_depth_link', rospy.Time(0))

            rospy.loginfo("Translation: %s", str(trans))  # Translation (x, y, z)
            rospy.loginfo("Rotation (Quaternion): %s", str(rot))  # Rotation (x, y, z, w)
            rospy.loginfo("Sucessfully got camera pose")

            return (trans, rot)

        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            rospy.logerr("Transformation not available")
            rospy.loginfo("Could not get camera pose")

            return None

    def joint_states_callback(self, data):
        self.joint_states = data

    def joint_states_desired_callback(self, data):
        self.joint_states_desired = data

    def started_moving(self):
        """
        Method: Performs another action on the object.
        """
        for vel in self.joint_states.velocity:
            if abs(vel) > 0.1:
                #print("Moving", self.joint_states.velocity)
                return True
            
        self.trials += 1
        if self.trials > 5:
            #print("Timeout", self.joint_states.velocity)
            self.trials = 0
            return True
        
        #print("Not moving", self.joint_states.velocity)
        return False

    def reached_target_pose(self):
        """
        Method: Performs another action on the object.
        """
        for vel in self.joint_states.velocity:
            if abs(vel) > 0.01:
                #print("Didnt reach pose", self.joint_states.velocity)
                return False

        #print("Reach pose", self.joint_states.velocity)
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
        rospy.loginfo("Getting point cloud")
        point_cloud_sub = rospy.Subscriber("/camera/depth/points", PointCloud2, self.point_cloud_callback) 
        rospy.wait_for_message("/camera/depth/points", PointCloud2, timeout=5)  # Wait for a message
        rospy.loginfo("Sucessfully got point cloud")
        
        return self.point_cloud_msg

    def point_cloud_callback(self, data):
        self.point_cloud_msg = data
        self.point_cloud = pc2.read_points(data, field_names=("x", "y", "z"), skip_nans=True)
        #for point in self.point_cloud:
        #    x, y, z = point
        #    print('x y z:', x, y, z)

    def transform_point_cloud(self, point_cloud_msg, transform, tf_buffer):
        """
        Calculates the Euclidean distance between two 3D points.

        Args:
            p1: First point as a tuple (x, y, z).
            p2: Second point as a tuple (x, y, z).

        Returns:
            The Euclidean distance between the two points.
        """
        rospy.loginfo("Transforming point cloud")
        try:
            transformed_cloud = do_transform_cloud(point_cloud_msg, transform)
        except Exception as e:
            rospy.logerr("Could not transform point cloud: {}".format(e))
            return None
        
        self.tf_point_cloud_msg = transformed_cloud
        self.tf_point_cloud = pc2.read_points(transformed_cloud, field_names=("x", "y", "z"), skip_nans=True)
        rospy.loginfo("Sucessfully transformed point cloud")

        return self.tf_point_cloud_msg
    
    def merge_point_clouds(self, cloud_list):
        """
        Segments a PointCloud2 message using Euclidean distance with optimizations.

        Args:
            cloud_msg: The input PointCloud2 message.
            distance_threshold: The maximum distance between points in the same cluster.

        Returns:
            A list of PointCloud2 messages, each representing a segmented cluster.
        """
        rospy.loginfo("Merging point clouds")

        if not cloud_list:
            rospy.logerr("Empty cloud list. Cannot merge.")
            return None

        # Initialize merged cloud with the first cloud in the list
        merged_cloud = cloud_list[0] 

        # Determine the number of points in each cloud
        num_points_list = []
        for cloud in cloud_list:
            num_points_list.append(len(list(pc2.read_points(cloud, skip_nans=True))))

        # Calculate the total number of points
        total_points = sum(num_points_list)

        # Create a numpy array to store the merged points
        merged_points = np.zeros((total_points, 4), dtype=np.float32)  # Assuming x, y, z, rgb

        # Fill the merged points array
        offset = 0
        for i, cloud in enumerate(cloud_list):
            for point in pc2.read_points(cloud, field_names=("x", "y", "z", "rgb"), skip_nans=True):
                merged_points[offset] = point
                offset += 1

        # Create a new PointCloud2 message
        header = merged_cloud.header 
        header.stamp = rospy.Time.now()  # Update timestamp
        merged_cloud = pc2.create_cloud_xyz32(header, merged_points[:, :3])  # Create cloud with x, y, z
        merged_cloud.fields.append(PointField(
            name='rgb', offset=12, datatype=PointField.FLOAT32, count=1)) 
        merged_cloud.point_step = 16  # 4 floats * 4 bytes/float
        merged_cloud.is_bigendian = False 
        merged_cloud.data = np.asarray(merged_points, np.float32).tobytes() 

        rospy.loginfo("Sucessfully merged point clouds")

        return merged_cloud

    def segment_point_cloud(self, cloud_msg, distance_threshold):
        """
        Segments a PointCloud2 message using Euclidean distance and scipy.spatial.KDTree.

        Args:
            cloud_msg: The input PointCloud2 message.
            distance_threshold: The maximum distance between points in the same cluster.

        Returns:
            A list of PointCloud2 messages, each representing a segmented cluster.
        """
        rospy.loginfo("Segmenting point cloud")

        points = np.array(list(pc2.read_points(cloud_msg, field_names=("x", "y", "z"), skip_nans=True)))
        num_points = points.shape[0]

        # Initialize cluster labels
        labels = np.full(num_points, -1, dtype=np.int32) 

        current_label = 0

        # Create a KD-Tree for efficient nearest neighbor search
        tree = KDTree(points)

        for i in range(num_points):
            if labels[i] != -1:  # Point already assigned to a cluster
                continue

            labels[i] = current_label 

            # Find neighboring points within the distance threshold
            neighbor_indices = tree.query_ball_point(points[i], distance_threshold) 
            labels[neighbor_indices] = current_label

            current_label += 1

        # Create a list of segmented point clouds
        segmented_clouds = []
        for label in set(labels):
            cluster_points = points[labels == label]
            if len(cluster_points) > 0: 
                cluster_cloud = self.create_point_cloud_msg(cluster_points, cloud_msg.header)
                segmented_clouds.append(cluster_cloud)

        rospy.loginfo("Sucessfully segmented point cloud")

        return segmented_clouds

    def create_point_cloud_msg(self, points, header):
        """
        Creates a PointCloud2 message from a list of points.

        Args:
            points: A NumPy array of points (N x 3).
            header: The header for the PointCloud2 message.

        Returns:
            The created PointCloud2 message.
        """
        cloud_msg = pc2.create_cloud_xyz32(header, points) 
        
        return cloud_msg

def main():
    rospy.init_node('main_node')

    rate = rospy.Rate(0.5)

    robot = Robot()
    vision_system = VisionSystem()

    poses = get_poses()
    tf_point_cloud_msgs = []
    cam_poses = []

    #while not rospy.is_shutdown():
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
        point_cloud_msg = vision_system.get_point_cloud()
        transform = robot.get_transform("world", "camera_depth_link", point_cloud_msg.header.stamp)
        tf_point_cloud_msg = vision_system.transform_point_cloud(point_cloud_msg, transform, robot.tf_buffer)
        tf_point_cloud_msgs.append(tf_point_cloud_msg)

        #read and store camera pose
        cam_poses.append(robot.get_camera_pose())

        rate.sleep()

    merged_cloud = vision_system.merge_point_clouds(tf_point_cloud_msgs)
    segmented_clouds = vision_system.segment_point_cloud(merged_cloud, 0.15)
    #print(len(segmented_clouds))

    #publish point clouds
    '''
    i = 1
    for cloud in segmented_clouds:
        print(f"point cloud {i}")
        sg_point_cloud_pub = rospy.Publisher('/sg_point_cloud', PointCloud2, queue_size=10)
        sg_point_cloud_pub.publish(cloud)
    
        input("Press enter to continue...")
        rate.sleep()

        i += 1
    '''

    #create meshes ??


if __name__ == '__main__':
    main()