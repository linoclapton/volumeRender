/****************************************************************************
** Meta object code from reading C++ file 'TransferFunction1DWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TransferFunction1DWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TransferFunction1DWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TransferFunction1DWidget_t {
    QByteArrayData data[7];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TransferFunction1DWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TransferFunction1DWidget_t qt_meta_stringdata_TransferFunction1DWidget = {
    {
QT_MOC_LITERAL(0, 0, 24), // "TransferFunction1DWidget"
QT_MOC_LITERAL(1, 25, 12), // "ValueChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 19), // "OnViewWindowChanged"
QT_MOC_LITERAL(4, 59, 12), // "window_level"
QT_MOC_LITERAL(5, 72, 12), // "window_width"
QT_MOC_LITERAL(6, 85, 19) // "OnHoverPointChanged"

    },
    "TransferFunction1DWidget\0ValueChanged\0"
    "\0OnViewWindowChanged\0window_level\0"
    "window_width\0OnHoverPointChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TransferFunction1DWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   30,    2, 0x0a /* Public */,
       6,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    4,    5,
    QMetaType::Void,

       0        // eod
};

void TransferFunction1DWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TransferFunction1DWidget *_t = static_cast<TransferFunction1DWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ValueChanged(); break;
        case 1: _t->OnViewWindowChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->OnHoverPointChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TransferFunction1DWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TransferFunction1DWidget::ValueChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject TransferFunction1DWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TransferFunction1DWidget.data,
      qt_meta_data_TransferFunction1DWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TransferFunction1DWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TransferFunction1DWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TransferFunction1DWidget.stringdata0))
        return static_cast<void*>(const_cast< TransferFunction1DWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int TransferFunction1DWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void TransferFunction1DWidget::ValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
