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

## Launch rrt exploration

To start rrt exploration for single robot.

```
# ssh into wheeltec robot
roslaunch turn_on_wheeltec_robot rrt_slam.launch
```

Run rviz with `rrt_exploration.rviz` config.

```
rosrun rviz rviz -d rviz_configs/rrt_exploration.rviz
```

In rviz, use the "Publish Point" tool to publish 5 points to the `/clicked_point` topic. The first 4 points define a rectangular region for the robot to explore. The last point defines the origin of the RRT in the global and local frontier detectors.

### Save map

To save a map to disk in `map.pgm` and `map.yaml` formats with `map_server`.

```
rosrun map_server map_saver [--occ <threshold_occupied>] [--free <threshold_free>] [-f <mapname>] map:=/your/costmap/topic

# simple example
rosrun map_server map_saver -f new_map
```

