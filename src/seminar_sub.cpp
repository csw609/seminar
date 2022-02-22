#include "ros/ros.h"
#include "std_msgs/String.h"

//Callback function that works when a message is received.
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("%s", msg->data.c_str());  //print a message to console
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "seminar_sub");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("messages", 1000, chatterCallback);  //declare subscriber

  ros::spin(); // Function waits to receive a message.
               // When a message is received, the callback function is called.

  return 0;
}
