/****************************************************************************
** Meta object code from reading C++ file 'GraySTUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GraySTUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GraySTUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GrayST_t {
    QByteArrayData data[7];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GrayST_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GrayST_t qt_meta_stringdata_GrayST = {
    {
QT_MOC_LITERAL(0, 0, 6), // "GrayST"
QT_MOC_LITERAL(1, 7, 18), // "fileOpenActionSlot"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 18), // "helpOpenActionSlot"
QT_MOC_LITERAL(4, 46, 17), // "openGrayscaleSlot"
QT_MOC_LITERAL(5, 64, 12), // "traslateSlot"
QT_MOC_LITERAL(6, 77, 13) // "saveImageSlot"

    },
    "GrayST\0fileOpenActionSlot\0\0"
    "helpOpenActionSlot\0openGrayscaleSlot\0"
    "traslateSlot\0saveImageSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GrayST[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GrayST::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GrayST *_t = static_cast<GrayST *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fileOpenActionSlot(); break;
        case 1: _t->helpOpenActionSlot(); break;
        case 2: _t->openGrayscaleSlot(); break;
        case 3: _t->traslateSlot(); break;
        case 4: _t->saveImageSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GrayST::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GrayST.data,
      qt_meta_data_GrayST,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GrayST::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GrayST::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GrayST.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int GrayST::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE