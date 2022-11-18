//
// Created by Sean Chok on 11/17/22.
//

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "cmd_wheeltec");
    ros::NodeHandle n;
    ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
    ros::Rate loop_rate(0.5);

    geometry_msgs::Twist stop;
    stop.linear.x = 0;
    stop.linear.y = 0;
    stop.linear.z = 0;
    stop.angular.x = 0;
    stop.angular.y = 0;
    stop.angular.z = 0;

    geometry_msgs::Twist move;
    move.linear.x = 0.2;
    // move.angular.z = 0.1;

    while (ros::ok())
    {
        ROS_INFO("linear x: %.2f", move.linear.x);
        cmd_vel_pub.publish(move);
        ros::spinOnce();
        loop_rate.sleep();
        cmd_vel_pub.publish(stop);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
