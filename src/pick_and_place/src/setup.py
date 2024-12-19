from setuptools import setup

setup(
    name='pick_and_place_package', 
    version='0.1', 
    packages=['pick_and_place_package'],  # Replace with the actual package name
    package_dir={'': 'src'}, 
    scripts=['scripts/main.py', 'scripts/robot_node.py', 
             'scripts/vision_system_node.py', 'scripts/pick_and_place_node.py'] 
)