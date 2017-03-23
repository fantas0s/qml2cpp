#include "multiplepropertiesobject.h"
MultiplePropertiesObject::MultiplePropertiesObject() :
    m_myText("Hello World!"),
    m_aNumber(42),
    m_dasColor("#008000"),
    m_anotherText("Bye bye cruel world!"),
    m_doubleDareNumber(0.56),
    m_aRealNumber(3.14159),
    m_thisIsFalse(true),
    m_bNumber(99),
    m_backgroundColor("#cccc9966"),
    m_doubleAgain(66),
    m_notSoRealNumber(5),
    m_thisIsTrue(false)
{
}

QString MultiplePropertiesObject::getMyText() const
{
    return m_myText;
}

int MultiplePropertiesObject::getANumber() const
{
    return m_aNumber;
}

QColor MultiplePropertiesObject::getDasColor() const
{
    return m_dasColor;
}

QString MultiplePropertiesObject::getAnotherText() const
{
    return m_anotherText;
}

double MultiplePropertiesObject::getDoubleDareNumber() const
{
    return m_doubleDareNumber;
}

double MultiplePropertiesObject::getARealNumber() const
{
    return m_aRealNumber;
}

bool MultiplePropertiesObject::getThisIsFalse() const
{
    return m_thisIsFalse;
}

int MultiplePropertiesObject::getBNumber() const
{
    return m_bNumber;
}

QColor MultiplePropertiesObject::getBackgroundColor() const
{
    return m_backgroundColor;
}

double MultiplePropertiesObject::getDoubleAgain() const
{
    return m_doubleAgain;
}

double MultiplePropertiesObject::getNotSoRealNumber() const
{
    return m_notSoRealNumber;
}

bool MultiplePropertiesObject::getThisIsTrue() const
{
    return m_thisIsTrue;
}

void MultiplePropertiesObject::setMyText(const QString input)
{
    m_myText = input;
    emit myTextChanged();
}

void MultiplePropertiesObject::setANumber(const int input)
{
    m_aNumber = input;
    emit aNumberChanged();
}

void MultiplePropertiesObject::setDasColor(const QColor input)
{
    m_dasColor = input;
    emit dasColorChanged();
}

void MultiplePropertiesObject::setAnotherText(const QString input)
{
    m_anotherText = input;
    emit anotherTextChanged();
}

void MultiplePropertiesObject::setDoubleDareNumber(const double input)
{
    m_doubleDareNumber = input;
    emit doubleDareNumberChanged();
}

void MultiplePropertiesObject::setARealNumber(const double input)
{
    m_aRealNumber = input;
    emit aRealNumberChanged();
}

void MultiplePropertiesObject::setThisIsFalse(const bool input)
{
    m_thisIsFalse = input;
    emit thisIsFalseChanged();
}

void MultiplePropertiesObject::setBNumber(const int input)
{
    m_bNumber = input;
    emit bNumberChanged();
}

void MultiplePropertiesObject::setBackgroundColor(const QColor input)
{
    m_backgroundColor = input;
    emit backgroundColorChanged();
}

void MultiplePropertiesObject::setDoubleAgain(const double input)
{
    m_doubleAgain = input;
    emit doubleAgainChanged();
}

void MultiplePropertiesObject::setNotSoRealNumber(const double input)
{
    m_notSoRealNumber = input;
    emit notSoRealNumberChanged();
}

void MultiplePropertiesObject::setThisIsTrue(const bool input)
{
    m_thisIsTrue = input;
    emit thisIsTrueChanged();
}
