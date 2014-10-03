// Creates RViz plugin to control the estop switch

#include "estopControl.h"
#include <std_msgs/Float64MultiArray.h>
#include "estop/estopSignal.h"

using namespace std;
namespace estop
{

// Initialize ros variables
ros::ServiceClient clientE;
estop::estopSignal srvE;
std_srvs::Empty srv;
ros::ServiceClient client;
bool estop;
bool run = false;
bool heart;
int i = 0;

EstopControl::EstopControl() : rviz::Display()
{
    RosTopicProperty = new rviz::RosTopicProperty("My Topic",
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

    HeartbeatProperty = new rviz::BoolProperty("Heartbeat",
                                                false,
                                                "description",
                                                this,
                                                SLOT ( HeartbeatPropertyHasChanged() ));
}

EstopControl::~EstopControl()
{
}

void EstopControl::onInitialize()
{
}

void EstopControl::onEnable()
{
    clientE = threaded_nh_.serviceClient<estop::estopSignal>("estop_control");
    client = threaded_nh_.serviceClient<std_srvs::Empty>("heartbeat");
}

void EstopControl::onDisable()
{
    clientE.shutdown();
}

void callEstopService()
{
    clientE.call(srvE);
}

void callHearbeatService()
{
    client.call(srv);
}

void EstopControl::update(float wall_dt, float ros_dt)
{
    const char* msg;
    if (estop) // engauge estop
    {
        srvE.request.message = 1;
        msg = "stop";
    }
    else if (!estop && !run) // estop reset
    {
         srvE.request.message = 2;
         msg = "reset";
    }
    //else if (~estop && run) // run
    else
    {
         srvE.request.message = 3;
         msg = "run";
    }

    setStatus( rviz::StatusProperty::Ok, "Message",   QString("%1").arg(msg));

    callEstopService();

    if (heart)
    {
        callHearbeatService();
        setStatus( rviz::StatusProperty::Ok, "Heartbeat Status",   QString("beating"));
    } else {
        setStatus( rviz::StatusProperty::Ok, "Heartbeat Status",   QString("stopped"));
    }
}

void EstopControl::rosTopicPropertyHasChanged()
{
    std::string str = RosTopicProperty->getStdString();
}

void EstopControl::ESTOPPropertyHasChanged()
{
    estop = ESTOPProperty->getBool();
}

void EstopControl::RunPropertyHasChanged()
{
    run = RunProperty->getBool();
}

void EstopControl::HeartbeatPropertyHasChanged()
{
    heart = HeartbeatProperty->getBool();
}

} //end namespace

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(estop::EstopControl,rviz::Display)


