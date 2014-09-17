#ifndef HEARTBEAT_H
#define HEARTBEAT_H

#include <rviz/display_context.h>

#include <rviz/display.h>
#include <rviz/properties/tf_frame_property.h>
#include <rviz/properties/vector_property.h>
#include <rviz/properties/int_property.h>
#include <rviz/properties/float_property.h>
#include <rviz/properties/color_property.h>
#include <rviz/properties/ros_topic_property.h>

#include "ros/ros.h"
#include <cstdlib>
#include "std_srvs/Empty.h"

namespace estop
{

class Heartbeat: public rviz::Display
{
    Q_OBJECT
public:
    Heartbeat();
    virtual ~Heartbeat();

protected:
    virtual void update(float wall_dt, float ros_dt);
    virtual void onInitialize();
    virtual void onEnable();
    virtual void onDisable();

    //Add slots here

private:
    

};


}

#endif

