#include "tst_objectswithpropertiestest.h"
#include "../application/cppfromqmlgenerator.h"
#include <QtTest>

ObjectsWithPropertiesTest::ObjectsWithPropertiesTest()
{
}

QFile* ObjectsWithPropertiesTest::sourceFileOpen(const QString fileName)
{
    const QString fullFilePath = QString(SRCDIR)+fileName;
    QFile* fileToOpen = new QFile(fullFilePath);
    fileToOpen->open(QIODevice::ReadOnly|QIODevice::Text);
    return fileToOpen;
}

void ObjectsWithPropertiesTest::convertQMLObjectWithOneStringProperty()
{
    QFile* cppHeader = sourceFileOpen("/cpp/onestringobject.h");
    // Generate
    const QString oneStringQMLObjectFilePath = QString(SRCDIR)+"/qml/OneStringObject.qml";
    CppFromQMLGenerator generator(oneStringQMLObjectFilePath);
    QString generatedHeader = generator.generateHeader();
    // Compare results
    QTextStream compareStream(cppHeader);
    QCOMPARE(generatedHeader, compareStream.readAll());
    delete cppHeader;
}

void ObjectsWithPropertiesTest::convertQMLObjectWithMultipleProperties()
{
    QFile* cppHeader = sourceFileOpen("/cpp/multiplepropertiesobject.h");
    // Generate
    const QString multiplePropertiesQMLObjectFilePath = QString(SRCDIR)+"/qml/MultiplePropertiesObject.qml";
    CppFromQMLGenerator generator(multiplePropertiesQMLObjectFilePath);
    QString generatedHeader = generator.generateHeader();
    // Compare results
    QTextStream compareStream(cppHeader);
    QCOMPARE(generatedHeader, compareStream.readAll());
    delete cppHeader;
}
