/****************************************************************************
** Meta object code from reading C++ file 'screenshot.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../screenshot/screenshot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screenshot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Screenshot_t {
    const uint offsetsAndSize[16];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Screenshot_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Screenshot_t qt_meta_stringdata_Screenshot = {
    {
QT_MOC_LITERAL(0, 10), // "Screenshot"
QT_MOC_LITERAL(11, 11), // "SCREENSHOT_"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 13), // "newScreenshot"
QT_MOC_LITERAL(38, 14), // "saveScreenshot"
QT_MOC_LITERAL(53, 11), // "shootScreen"
QT_MOC_LITERAL(65, 14), // "updateCheckBox"
QT_MOC_LITERAL(80, 5) // "scale"

    },
    "Screenshot\0SCREENSHOT_\0\0newScreenshot\0"
    "saveScreenshot\0shootScreen\0updateCheckBox\0"
    "scale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Screenshot[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    1,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QPixmap, QMetaType::QPixmap,    2,

       0        // eod
};

void Screenshot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Screenshot *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SCREENSHOT_(); break;
        case 1: _t->newScreenshot(); break;
        case 2: _t->saveScreenshot(); break;
        case 3: _t->shootScreen(); break;
        case 4: _t->updateCheckBox(); break;
        case 5: { QPixmap _r = _t->scale((*reinterpret_cast< std::add_pointer_t<QPixmap>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject Screenshot::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Screenshot.offsetsAndSize,
    qt_meta_data_Screenshot,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Screenshot_t
, QtPrivate::TypeAndForceComplete<Screenshot, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPixmap, std::false_type>, QtPrivate::TypeAndForceComplete<QPixmap, std::false_type>


>,
    nullptr
} };


const QMetaObject *Screenshot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Screenshot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Screenshot.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Screenshot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
