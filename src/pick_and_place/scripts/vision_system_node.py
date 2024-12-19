import rospy
from std_msgs.msg import String

class VisionSystem:
    """
    Docstring: A brief description of the class.
    """

    def __init__(self):#, arg1, arg2):
        """
        Constructor: Initializes the object's attributes.
        """
        #self.attribute1 = arg1
        #self.attribute2 = arg2 
        print("Setting attribute 1")
        print("Setting attribute 2")

    def get_rgb_image(self):#, arg1, arg2):
        """
        Method: Performs a specific action on the object.
        """
        print("Getting RGB image")
        pass

    def get_depth_image(self):#, arg1, arg2):
        """
        Method: Performs another action on the object.
        """
        print("Getting depth image")
        pass

    def get_point_cloud(self):#, arg1, arg2):
        """
        Method: Performs another action on the object.
        """
        print("Getting point cloud")
        pass


class VisionSystemNode:
    def __init__(self):
        rospy.init_node('vision_system_node')
        self.vision_system = VisionSystem()  # Create an instance of your VisionSystem class
        self.subscriber = rospy.Subscriber('/vision_system_commands', String, self.command_callback)

    def command_callback(self, data):
        if data.data == 'get_rgb_image':
            self.vision_system.get_rgb_image()
        elif data.data == 'get_depth_image':
            self.vision_system.get_depth_image()
        elif data.data == 'get_point_cloud':
            self.vision_system.get_point_cloud()

if __name__ == '__main__':
    node = VisionSystemNode()
    rospy.spin() 