/*
 * Disclaimer Note:
 * Code was taken from http://wiki.ros.org/ROS/Tutorials/WritingServiceClient%28c%2B%2B%29
 */

#include <ros/ros.h>
#include <basic_demo/AddTwoInts.h>

bool add(basic_demo::AddTwoInts::Request  &req, basic_demo::AddTwoInts::Response &res ) {
  res.sum = req.a + req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);

  return true;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "add_two_ints_server");
  ros::NodeHandle n;
  ros::ServiceServer service = n.advertiseService("add_two_ints", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}
