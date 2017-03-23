#include "onestringobject.h"
OneStringObject::OneStringObject() :
    m_myString("Initial content")
{
}

QString OneStringObject::getMyString() const
{
    return m_myString;
}

void OneStringObject::setMyString(const QString input)
{
    m_myString = input;
    emit myStringChanged();
}
