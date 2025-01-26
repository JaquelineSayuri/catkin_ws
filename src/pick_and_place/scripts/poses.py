from geometry_msgs.msg import PoseStamped

def get_poses():
    """
    Returns a list of pre-defined PoseStamped objects to read the point clouds.
    """
    poses = [
        # left white section
        {
            "position": {"x": 0.1, "y": 0.0, "z": 0.4},
            "orientation": {"x": -0.9396926, "y": 0.0, "z": -0.3420201, "w": 0.0},
            "frame_id": "gripper"
        },
        {
            "position": {"x": 0.5, "y": 0.25, "z": 0.45},
            "orientation": {"x": -0.9076734, "y": 0.0885213, "z": 0.3303661, "w": -0.2432103},
            "frame_id": "gripper"
        },
        {
            "position": {"x": 0.5, "y": -0.25, "z": 0.45},
            "orientation": {"x": -0.9076734, "y": -0.0885213, "z": 0.3303661, "w": 0.2432103},
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