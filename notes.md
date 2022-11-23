# Some useful notes

## Launch turn_on_wheeltec_robot

To start running basic robot functions, i.e. to move around.

SSH into the wheeltec robot.

```
roslaunch turn_on_wheeltec_robot turn_on_wheeltec_robot.launch
```

To start controlling the robot with keyboard operations in another ssh session.

```
roslaunch wheeltec_robot_rc keyboard_teleop.launch
```

## Launch rplidar ld_14

To turn on the rplidar, and start sending sensor_msgs/LaserScan messages to /scan topic.

```
# ssh into wheeltec robot
roslaunch turn_on_wheeltec_robot wheeltec_lidar.launch
```

Run rviz with `laser_scan_manual.rviz` config.

```
rosrun rviz rviz -d rviz_configs/laser_scan_manual.rviz
```

