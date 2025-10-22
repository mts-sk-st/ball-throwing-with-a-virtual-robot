# Ball Throwing with a Virtual Robot
This repository contains the source code for a  project allowing a ball throwing game to be played with a virtual robot within Virtual Reality.
The project was developed within the Unreal Engine on version 4.19 for use the HTC VIVE system.

![project picture](project_picture.png)

## Development
This project was developed using a combination of the Blueprints Visual Scripting language for the Virtual Reality interactions, and C++ for the attempts at Robot Operating System (ROS) integration.

The robot model was created as a URDF file, and an appropriate representation was created within the Unreal Engine.

Currently robot manipulation is done using Blueprints to move the robot body, however implementation of the Orocos Kinematics and Dynamics Library (KDL) and it's kinematics solvers are being explored for use.

## How to use
- Clone or download the project source
- Configure and start SteamVR
- If using the ros-ik-integration branch, right click the development.uproject file and 'Generate Visaul Studio project files'
- Open the development.uproject file in the Unreal Engine project browser
- Ensure the "World" level is open, and play in the VR Preview

## Controls
Both motion controllers are programmed to have the same behaviour allowing the same functionality for both left-handed and right-handed users.

![vive controller layout guide](VIVE_controller.png)

- The trackpad can be used to teleport around the starting room
  - Simply point the motion controller in the direction you wish to move and touch the touchpad to teleport
- The trigger controls can be used to pick up and drop a ball
  - The motion controller will shake when in reach of the ball, at this point hold the trigger to pick up a ball, and release the trigger to throw the ball in the direction of the motion controller
  - The ball will travel with the velocity of the motion controller on release, so an actual throwing motion is required
