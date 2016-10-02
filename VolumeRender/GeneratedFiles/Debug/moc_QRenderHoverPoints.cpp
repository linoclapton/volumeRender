/****************************************************************************
** Meta object code from reading C++ file 'QRenderHoverPoints.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QRenderHoverPoints.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QRenderHoverPoints.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QRenderHoverPoints_t {
    QByteArrayData data[8];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QRenderHoverPoints_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QRenderHoverPoints_t qt_meta_stringdata_QRenderHoverPoints = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QRenderHoverPoints"
QT_MOC_LITERAL(1, 19, 13), // "pointsChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 13), // "oneDTFChanged"
QT_MOC_LITERAL(4, 48, 10), // "setEnabled"
QT_MOC_LITERAL(5, 59, 7), // "enabled"
QT_MOC_LITERAL(6, 67, 11), // "setDisabled"
QT_MOC_LITERAL(7, 79, 8) // "disabled"

    },
    "QRenderHoverPoints\0pointsChanged\0\0"
    "oneDTFChanged\0setEnabled\0enabled\0"
    "setDisabled\0disabled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QRenderHoverPoints[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    0,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   38,    2, 0x0a /* Public */,
       6,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPolygonF,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void QRenderHoverPoints::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QRenderHoverPoints *_t = static_cast<QRenderHoverPoints *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pointsChanged((*reinterpret_cast< QPolygonF(*)>(_a[1]))); break;
        case 1: _t->oneDTFChanged(); break;
        case 2: _t->setEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setDisabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QRenderHoverPoints::*_t)(QPolygonF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QRenderHoverPoints::pointsChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (QRenderHoverPoints::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QRenderHoverPoints::oneDTFChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject QRenderHoverPoints::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QRenderHoverPoints.data,
      qt_meta_data_QRenderHoverPoints,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QRenderHoverPoints::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QRenderHoverPoints::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QRenderHoverPoints.stringdata0))
        return static_cast<void*>(const_cast< QRenderHoverPoints*>(this));
    return QWidget::qt_metacast(_clname);
}

int QRenderHoverPoints::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QRenderHoverPoints::pointsChanged(QPolygonF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QRenderHoverPoints::oneDTFChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
