#include "firstplugin.h"
#include <std_msgs/Float64MultiArray.h>

namespace rviz_plugin_template
{

FirstPlugin::FirstPlugin() : rviz::Display()
{
    sampleRosTopicProperty = new rviz::RosTopicProperty("My Topic",
                                                        "/default_value",
                                                        QString::fromStdString(ros::message_traits::datatype<std_msgs::Float64MultiArray>()),//Looks for topics only with this type
                                                        "description",
                                                        this,
                                                        SLOT ( rosTopicPropertyHasChanged() ));

    sampleBoolProperty = new rviz::BoolProperty("My boolean",
                                                false,
                                                "description",
                                                this,
                                                SLOT ( boolPropertyHasChanged() ));

    sampleStringProperty = new rviz::StringProperty("My string",
                                                    "default string",
                                                    "description",
                                                    this,
                                                    SLOT ( stringPropertyHasChanged() ));

    sampleFloatProperty = new rviz::FloatProperty("My float",
                                                  1.23,
                                                  "description",
                                                  this,
                                                  SLOT ( floatPropertyHasChanged() ));

    sampleIntProperty = new rviz::IntProperty("My integer",
                                              123,
                                              "description",
                                              this,
                                              SLOT ( intPropertyHasChanged() ));
    //Add additional properties here

    //And more
}

FirstPlugin::~FirstPlugin()
{
    //destructor, clear all allocated memory if any
}

void FirstPlugin::onInitialize()
{
    //When plugin is loaded
}

void FirstPlugin::onEnable()
{
    //When plugin is enabled
}

void FirstPlugin::onDisable()
{
    //When plugin is disabled
}

void FirstPlugin::update(float wall_dt, float ros_dt)
{
    //The main graphics loop updating ~30-60hz. Use if need to to something each time this occurs.
}

void FirstPlugin::rosTopicPropertyHasChanged()
{
    std::string str = sampleRosTopicProperty->getStdString();
    //do something;
}

void FirstPlugin::boolPropertyHasChanged()
{
    bool val = sampleBoolProperty->getBool();
    //do something;
}

void FirstPlugin::stringPropertyHasChanged()
{
    std::string str = sampleStringProperty->getStdString();
    //do something;
}

void FirstPlugin::floatPropertyHasChanged()
{
    float f = sampleFloatProperty->getFloat();
    //do something;
}

void FirstPlugin::intPropertyHasChanged()
{
    int i = sampleIntProperty->getInt();
    //do something;
}

void FirstPlugin::colorPropertyHasChanged()
{
    //do something;
}



} //end namespace

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(rviz_plugin_template::FirstPlugin,rviz::Display)


