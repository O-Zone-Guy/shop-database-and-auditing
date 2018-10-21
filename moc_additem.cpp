/****************************************************************************
** Meta object code from reading C++ file 'additem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "additem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'additem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddItem_t {
    QByteArrayData data[9];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddItem_t qt_meta_stringdata_AddItem = {
    {
QT_MOC_LITERAL(0, 0, 7), // "AddItem"
QT_MOC_LITERAL(1, 8, 11), // "newCatAdded"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "addedItem"
QT_MOC_LITERAL(4, 31, 21), // "on_toolButton_clicked"
QT_MOC_LITERAL(5, 53, 14), // "updateCombobox"
QT_MOC_LITERAL(6, 68, 30), // "on_mainCats_currentTextChanged"
QT_MOC_LITERAL(7, 99, 4), // "arg1"
QT_MOC_LITERAL(8, 104, 8) // "accepted"

    },
    "AddItem\0newCatAdded\0\0addedItem\0"
    "on_toolButton_clicked\0updateCombobox\0"
    "on_mainCats_currentTextChanged\0arg1\0"
    "accepted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void AddItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddItem *_t = static_cast<AddItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newCatAdded(); break;
        case 1: _t->addedItem(); break;
        case 2: _t->on_toolButton_clicked(); break;
        case 3: _t->updateCombobox(); break;
        case 4: _t->on_mainCats_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->accepted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddItem::newCatAdded)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AddItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddItem::addedItem)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject AddItem::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddItem.data,
      qt_meta_data_AddItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddItem.stringdata0))
        return static_cast<void*>(const_cast< AddItem*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void AddItem::newCatAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void AddItem::addedItem()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
