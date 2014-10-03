#ifndef ESTOP_CONTROL_H
#define ESOPT_CONTROL_H

#include <rviz/display_context.h>

#include <rviz/display.h>
#include <rviz/properties/vector_property.h>
#include <rviz/properties/int_property.h>
#include <rviz/properties/float_property.h>
#include <rviz/properties/color_property.h>
#include <rviz/properties/ros_topic_property.h>
#include <iostream>

#include "ros/ros.h"
#include <cstdlib>
#include "std_srvs/Empty.h"

using namespace std;
namespace estop
{

class EstopControl: public rviz::Display
{
    Q_OBJECT
public:
    EstopControl();
    virtual ~EstopControl();

protected:
    virtual void update(float wall_dt, float ros_dt);
    virtual void onInitialize();
    virtual void onEnable();
    virtual void onDisable();

private Q_SLOTS:
    void rosTopicPropertyHasChanged();
    void ESTOPPropertyHasChanged();
    void RunPropertyHasChanged();
    void HeartbeatPropertyHasChanged();

private:
    rviz::RosTopicProperty* RosTopicProperty;
    rviz::BoolProperty* ESTOPProperty;
    rviz::BoolProperty* RunProperty;
    rviz::BoolProperty* HeartbeatProperty;
};


}

#endif

