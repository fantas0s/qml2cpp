#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include "../application/cppfromqmlgenerator.h"

class EmptyObjectTest : public QObject
{
    Q_OBJECT

public:
    EmptyObjectTest();
    QFile* sourceFileOpen(const QString fileName);

private Q_SLOTS:
    void convertEmptyQMLObject();
    void convertQMLObjectWithOneStringProperty();
    void convertQMLObjectWithMultipleProperties();
};

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

void EmptyObjectTest::convertQMLObjectWithOneStringProperty()
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

void EmptyObjectTest::convertQMLObjectWithMultipleProperties()
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

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    EmptyObjectTest tc;
    QTEST_SET_MAIN_SOURCE_PATH
    return QTest::qExec(&tc, argc, argv);
}

#include "tst_emptyobjecttest.moc"
