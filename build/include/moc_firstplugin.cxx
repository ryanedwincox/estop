/****************************************************************************
** Meta object code from reading C++ file 'firstplugin.h'
**
** Created: Mon Apr 28 15:28:43 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/firstplugin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'firstplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rviz_plugin_template__FirstPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      35,   34,   34,   34, 0x08,
      64,   34,   34,   34, 0x08,
      89,   34,   34,   34, 0x08,
     116,   34,   34,   34, 0x08,
     140,   34,   34,   34, 0x08,
     166,   34,   34,   34, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rviz_plugin_template__FirstPlugin[] = {
    "rviz_plugin_template::FirstPlugin\0\0"
    "rosTopicPropertyHasChanged()\0"
    "boolPropertyHasChanged()\0"
    "stringPropertyHasChanged()\0"
    "intPropertyHasChanged()\0"
    "colorPropertyHasChanged()\0"
    "floatPropertyHasChanged()\0"
};

void rviz_plugin_template::FirstPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FirstPlugin *_t = static_cast<FirstPlugin *>(_o);
        switch (_id) {
        case 0: _t->rosTopicPropertyHasChanged(); break;
        case 1: _t->boolPropertyHasChanged(); break;
        case 2: _t->stringPropertyHasChanged(); break;
        case 3: _t->intPropertyHasChanged(); break;
        case 4: _t->colorPropertyHasChanged(); break;
        case 5: _t->floatPropertyHasChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rviz_plugin_template::FirstPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rviz_plugin_template::FirstPlugin::staticMetaObject = {
    { &rviz::Display::staticMetaObject, qt_meta_stringdata_rviz_plugin_template__FirstPlugin,
      qt_meta_data_rviz_plugin_template__FirstPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rviz_plugin_template::FirstPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rviz_plugin_template::FirstPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rviz_plugin_template::FirstPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rviz_plugin_template__FirstPlugin))
        return static_cast<void*>(const_cast< FirstPlugin*>(this));
    typedef rviz::Display QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int rviz_plugin_template::FirstPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef rviz::Display QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
