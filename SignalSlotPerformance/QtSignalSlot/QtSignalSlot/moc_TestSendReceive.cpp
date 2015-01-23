/****************************************************************************
** Meta object code from reading C++ file 'TestSendReceive.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "C:\Users\zou\Documents\GitHub\sandbox\SignalSlotPerformance\QtSignalSlot\QtSignalSlot\TestSendReceive.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestSendReceive.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestSendThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   16,   15,   15, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_TestSendThread[] = {
    "TestSendThread\0\0i\0send(int)\0"
};

void TestSendThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TestSendThread *_t = static_cast<TestSendThread *>(_o);
        switch (_id) {
        case 0: _t->send((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TestSendThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TestSendThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TestSendThread,
      qt_meta_data_TestSendThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestSendThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestSendThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestSendThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestSendThread))
        return static_cast<void*>(const_cast< TestSendThread*>(this));
    return QObject::qt_metacast(_clname);
}

int TestSendThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void TestSendThread::send(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_TestReceiveThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   19,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TestReceiveThread[] = {
    "TestReceiveThread\0\0i\0onReceived(int)\0"
};

void TestReceiveThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TestReceiveThread *_t = static_cast<TestReceiveThread *>(_o);
        switch (_id) {
        case 0: _t->onReceived((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TestReceiveThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TestReceiveThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TestReceiveThread,
      qt_meta_data_TestReceiveThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestReceiveThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestReceiveThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestReceiveThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestReceiveThread))
        return static_cast<void*>(const_cast< TestReceiveThread*>(this));
    return QObject::qt_metacast(_clname);
}

int TestReceiveThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
