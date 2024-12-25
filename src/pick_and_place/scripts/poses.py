from geometry_msgs.msg import PoseStamped

def get_poses():
    """
    Returns a list of pre-defined PoseStamped objects to read the point clouds.
    """
    poses = [
        # left white section
        {
            "position": {"x": 0.1, "y": 0.45, "z": 0.5},
            "orientation": {"x": -0.71, "y": -0.71, "z": 0.0, "w": 0.0},
            "frame_id": "gripper"
        },
        {
            "position": {"x": 0.23, "y": 0.58, "z": 0.4},
            "orientation": {"x": -0.69, "y": -0.65, "z": 0.27, "w": -0.15},
            "frame_id": "gripper"
        },
        {
            "position": {"x": 0.1, "y": 0.4, "z": 0.5},
            "orientation": {"x": -0.71, "y": -0.7, "z": -0.11, "w": 0.0},
            "frame_id": "gripper"
        },

        # yellow section
        {
            "position": {"x": 0.1, "y": 0.0, "z": 0.615},
            "orientation": {"x": 0.0, "y": 0.0, "z": 0.0, "w": 0.0},
            "frame_id": "gripper"
        },
        {
            "position": {"x": 0.2, "y": -0.1, "z": 0.615},
            "orientation": {"x": 0.0, "y": 0.0, "z": 0.0, "w": 0.0},
            "frame_id": "gripper"
        },
        {
            "position": {"x": 0.2, "y": 0.1, "z": 0.59},
            "orientation": {"x": 0.0, "y": 0.0, "z": 0.0, "w": 0.0},
            "frame_id": "gripper"
        },

        # red section
        {
            "position": {"x": 0.1, "y": 0.0, "z": 0.615},
            "orientation": {"x": 0.0, "y": 0.0, "z": 0.0, "w": 0.0},
            "frame_id": "gripper"
        },
        {
            "position": {"x": 0.2, "y": -0.1, "z": 0.615},
            "orientation": {"x": 0.0, "y": 0.0, "z": 0.0, "w": 0.0},
            "frame_id": "gripper"
        },
        {
            "position": {"x": 0.2, "y": 0.1, "z": 0.59},
            "orientation": {"x": 0.0, "y": 0.0, "z": 0.0, "w": 0.0},
            "frame_id": "gripper"
        },

        # blue section
        {
            "position": {"x": 0.1, "y": 0.0, "z": 0.615},
            "orientation": {"x": 0.0, "y": 0.0, "z": 0.0, "w": 0.0},
            "frame_id": "gripper"
        },
        {
            "position": {"x": 0.2, "y": -0.1, "z": 0.615},
            "orientation": {"x": 0.0, "y": 0.0, "z": 0.0, "w": 0.0},
            "frame_id": "gripper"
        },
        {
            "position": {"x": 0.2, "y": 0.1, "z": 0.59},
            "orientation": {"x": 0.0, "y": 0.0, "z": 0.0, "w": 0.0},
            "frame_id": "gripper"
        },

        # right white section
        {
            "position": {"x": 0.1, "y": 0.0, "z": 0.615},
            "orientation": {"x": 0.0, "y": 0.0, "z": 0.0, "w": 0.0},
            "frame_id": "gripper"
        },
        {
            "position": {"x": 0.2, "y": -0.1, "z": 0.615},
            "orientation": {"x": 0.0, "y": 0.0, "z": 0.0, "w": 0.0},
            "frame_id": "gripper"
        },
        {
            "position": {"x": 0.2, "y": 0.1, "z": 0.59},
            "orientation": {"x": 0.0, "y": 0.0, "z": 0.0, "w": 0.0},
            "frame_id": "gripper"
        }
    ]

    return poses