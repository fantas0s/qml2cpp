#include "tst_filenamestest.h"
#include "../application/cppfromqmlgenerator.h"
#include <QtTest>

FilenamesTest::FilenamesTest()
{
}

void FilenamesTest::testHeaderAndSourceFileForEmptyObject()
{
    const QString emptyQMLObjectFilePath = QString(SRCDIR)+"/qml/EmptyObject.qml";
    CppFromQMLGenerator generator(emptyQMLObjectFilePath);
    QString headerName = generator.getHeaderFilename();
    QCOMPARE(headerName, QString("emptyobject.h"));
    QString sourceName = generator.getSourceFilename();
    QCOMPARE(sourceName, QString("emptyobject.cpp"));
}

void FilenamesTest::testHeaderAndSourceFileForMultiplePropertiesObject()
{
    const QString emptyQMLObjectFilePath = QString(SRCDIR)+"/qml/MultiplePropertiesObject.qml";
    CppFromQMLGenerator generator(emptyQMLObjectFilePath);
    QString headerName = generator.getHeaderFilename();
    QCOMPARE(headerName, QString("multiplepropertiesobject.h"));
    QString sourceName = generator.getSourceFilename();
    QCOMPARE(sourceName, QString("multiplepropertiesobject.cpp"));
}
