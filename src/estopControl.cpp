// Creates RViz plugin to control the estop switch

#include "estopControl.h"
#include <std_msgs/Float64MultiArray.h>
#include "estop/estopSignal.h"

using namespace std;
namespace estop
{

ros::ServiceClient clientE;
estop::estopSignal srvE;
bool estop;
bool run = false;
int i = 0;

EstopControl::EstopControl() : rviz::Display()
{
    sampleRosTopicProperty = new rviz::RosTopicProperty("My Topic",
                                                        "/default_value",
                                                        QString::fromStdString(ros::message_traits::datatype<std_msgs::Float64MultiArray>()),//Looks for topics only with this type
                                                        "description",
                                                        this,
                                                        SLOT ( rosTopicPropertyHasChanged() ));

    ESTOPProperty = new rviz::BoolProperty("ESTOP",
                                                false,
                                                "description",
                                                this,
                                                SLOT ( ESTOPPropertyHasChanged() ));

    RunProperty = new rviz::BoolProperty("Run",
                                                false,
                                                "description",
                                                this,
                                                SLOT ( RunPropertyHasChanged() ));



    //And more
}

EstopControl::~EstopControl()
{
    //destructor, clear all allocated memory if any
}

void EstopControl::onInitialize()
{
    clientE = threaded_nh_.serviceClient<estop::estopSignal>("estop_control");
}

void EstopControl::onEnable()
{
    //When plugin is enabled
//    srvE.request.message = 3;
//    ROS_INFO("sending %d", 3);
    //clientE.call(srvE);
}

void EstopControl::onDisable()
{
    //When plugin is disabled
}

void callEstopService()
{
    clientE.call(srvE);
    ROS_INFO("Message Sent");
}

void EstopControl::update(float wall_dt, float ros_dt)
{
    if (estop) // engauge estop
    {
        srvE.request.message = 1;
        ROS_INFO("sending %d", 1);
    }
    else if (!estop && !run) // estop reset
    {
         srvE.request.message = 2;
         ROS_INFO("sending %d", 2);
    }
    //else if (~estop && run) // run
    else
    {
         srvE.request.message = 3;
         ROS_INFO("sending %d", 3);
    }

    if (i == 50)//  This loop slows down the service call rate so some buffer does not fill up
    {
        callEstopService();
        i = 0;
    }
    i++;

//    if (clientE.call(srvE))
//    {
//      ROS_INFO("Recieved handshake: %d", (bool)srvE.response.handshake);
//    }
//    else
//    {
//      ROS_ERROR("Failed to call service estop_control");
//    }
}

void EstopControl::rosTopicPropertyHasChanged()
{
    std::string str = sampleRosTopicProperty->getStdString();
    //do something;
}

void EstopControl::ESTOPPropertyHasChanged()
{
    estop = ESTOPProperty->getBool();
}

void EstopControl::RunPropertyHasChanged()
{
    run = RunProperty->getBool();
}


} //end namespace

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(estop::EstopControl,rviz::Display)


