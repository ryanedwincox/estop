#include "secondplugin.h"

namespace rviz_plugin_template
{

SecondPlugin::SecondPlugin() : rviz::Display()
{
    //Add additional properties here
}

SecondPlugin::~SecondPlugin()
{

}

void SecondPlugin::onInitialize()
{

}

void SecondPlugin::onEnable()
{

}

void SecondPlugin::onDisable()
{

}

void SecondPlugin::update(float wall_dt, float ros_dt)
{

}


} //end namespace

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(rviz_plugin_template::SecondPlugin,rviz::Display)


