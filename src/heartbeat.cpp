// Creates RViz plugin that controls a heartbeat service

#include "heartbeat.h"

namespace estop
{

Heartbeat::Heartbeat() : rviz::Display()
{
    //Add additional properties here
}

Heartbeat::~Heartbeat()
{

}

// Initialize ros variables
std_srvs::Empty srv;
ros::ServiceClient client;

// Creates service
void Heartbeat::onInitialize()
{
    client = threaded_nh_.serviceClient<std_srvs::Empty>("heartbeat");

}

void Heartbeat::onEnable()
{

}

void Heartbeat::onDisable()
{

}

void Heartbeat::update(float wall_dt, float ros_dt)
{
    client.call(srv);
//    if (client.call(srv))  // sends heartbeat
//    {
//      ROS_INFO("alive");
//    }
}


} //end namespace

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(estop::Heartbeat,rviz::Display)


