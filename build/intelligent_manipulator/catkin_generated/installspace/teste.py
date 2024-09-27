from gazebo_msgs.srv import SpawnModel
import rospy
from geometry_msgs.msg import Pose
rospy.init_node('insert_object',log_level=rospy.INFO)
spawn_model_client = rospy.ServiceProxy('/gazebo/spawn_sdf_model', SpawnModel)
spawn_model_client(
    model_name='ground_plane',
    model_xml=open('/usr/share/gazebo-9/models/ground_plane/model.sdf', 'r').read(),
    robot_namespace='/foo',
    initial_pose=Pose(),
    reference_frame='world'
)