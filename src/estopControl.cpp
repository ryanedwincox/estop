// Creates RViz plugin to control the estop switch

#include "estopControl.h"
#include <std_msgs/Float64MultiArray.h>
#include "estop/estopSignal.h"

using namespace std;
namespace estop
{

// Initialize ros variables
ros::ServiceClient clientEstop;
ros::ServiceClient clientHeartbeat;
estop::estopSignal srvEStop;
std_srvs::Empty srvEmpty;
bool estopButton = false;
bool runButton = false;  // Set to true to start running on startup
bool heartButton;
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
    clientEstop = threaded_nh_.serviceClient<estop::estopSignal>("/estop_control");
    clientHeartbeat = threaded_nh_.serviceClient<std_srvs::Empty>("/heartbeat");
}

void EstopControl::onDisable()
{
    clientEstop.shutdown();
}

void callEstopService()
{
    clientEstop.call(srvEStop);
}

void callHearbeatService()
{
    clientHeartbeat.call(srvEmpty);
}

void EstopControl::update(float wall_dt, float ros_dt)
{
    const char* msg;
    if (estopButton) // engauge estop
    {
        srvEStop.request.message = 1;
        msg = "stop";
    }
    else if (!estopButton && !runButton) // estop reset
    {
         srvEStop.request.message = 2;
         msg = "reset";
    }
    else
    {
         srvEStop.request.message = 3;
         msg = "run";
    }

    setStatus( rviz::StatusProperty::Ok, "Message",   QString("%1").arg(msg));

    callEstopService();

    if (heartButton)
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
    estopButton = ESTOPProperty->getBool();
}

void EstopControl::RunPropertyHasChanged()
{
    runButton = RunProperty->getBool();
}

void EstopControl::HeartbeatPropertyHasChanged()
{
    heartButton = HeartbeatProperty->getBool();
}

} //end namespace

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(estop::EstopControl,rviz::Display)


