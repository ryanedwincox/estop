#ifndef FIRST_PLUGIN_H
#define FIRST_PLUGIN_H

#include <rviz/display_context.h>

#include <rviz/display.h>
#include <rviz/properties/vector_property.h>
#include <rviz/properties/int_property.h>
#include <rviz/properties/float_property.h>
#include <rviz/properties/color_property.h>
#include <rviz/properties/ros_topic_property.h>

namespace rviz_plugin_template
{

class FirstPlugin: public rviz::Display
{
    Q_OBJECT
public:
    FirstPlugin();
    virtual ~FirstPlugin();

protected:
    virtual void update(float wall_dt, float ros_dt);
    virtual void onInitialize();
    virtual void onEnable();
    virtual void onDisable();

private Q_SLOTS:
    void rosTopicPropertyHasChanged();
    void boolPropertyHasChanged();
    void stringPropertyHasChanged();
    void intPropertyHasChanged();
    void colorPropertyHasChanged();
    void floatPropertyHasChanged();
    //Add more slots here

private:
    rviz::RosTopicProperty* sampleRosTopicProperty;
    rviz::BoolProperty* sampleBoolProperty;
    rviz::StringProperty* sampleStringProperty;
    rviz::FloatProperty* sampleFloatProperty;
    rviz::IntProperty* sampleIntProperty;
    rviz::ColorProperty* sampleColorProperty;
};


}

#endif

