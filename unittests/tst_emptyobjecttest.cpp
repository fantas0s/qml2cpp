#include "tst_emptyobjecttest.h"
#include "../application/cppfromqmlgenerator.h"
#include <QtTest>

EmptyObjectTest::EmptyObjectTest()
{
}

QFile* EmptyObjectTest::sourceFileOpen(const QString fileName)
{
    const QString fullFilePath = QString(SRCDIR)+fileName;
    QFile* fileToOpen = new QFile(fullFilePath);
    fileToOpen->open(QIODevice::ReadOnly|QIODevice::Text);
    return fileToOpen;
}

void EmptyObjectTest::convertEmptyQMLObject()
{
    const QString emptyQMLObjectFilePath = QString(SRCDIR)+"/qml/EmptyObject.qml";
    CppFromQMLGenerator generator(emptyQMLObjectFilePath);
    // Generate header
    QString generatedHeader = generator.generateHeader();
    QFile* cppHeader = sourceFileOpen("/cpp/emptyobject.h");
    QTextStream headerCompareStream(cppHeader);
    QCOMPARE(generatedHeader, headerCompareStream.readAll());
    delete cppHeader;
    // Generate source
    QString generatedSource = generator.generateSource();
    QFile* cppSource = sourceFileOpen("/cpp/emptyobject.cpp");
    QTextStream sourceCompareStream(cppSource);
    QCOMPARE(generatedSource, sourceCompareStream.readAll());
    delete cppSource;
}
