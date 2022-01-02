#include "ros/ros.h"              // ROS basic header
#include "std_msgs/String.h"      // std_msgs package

int main(int argc, char **argv)
{
  ros::init(argc, argv, "seminar_pub");     //initialize name of node
  ros::NodeHandle nh;                       //Declare node handle for communication with ROS system

  ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("messages", 1000);  // Declare Publisher
                                                                                  // topic name : messages
                                                                                  // queue size : 1000
  ros::Rate loop_rate(10);    // operate 10HZ
  while (ros::ok())
  {
    std_msgs::String msg;     // declare message for publish
    msg.data = "hello world"; // contents of message

    ROS_INFO("Publish Msgs");//print to console

    chatter_pub.publish(msg); // publish messages

    loop_rate.sleep();  // sleep for operation frequency
  }

  return 0;
}
