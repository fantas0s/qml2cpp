#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include "../application/cppfromqmlgenerator.h"

class EmptyObjectTest : public QObject
{
    Q_OBJECT

public:
    EmptyObjectTest();

private Q_SLOTS:
    void convertEmptyQMLObject();
    void convertQMLObjectWithOneStringProperty();
    void convertQMLObjectWithMultipleProperties();
};

EmptyObjectTest::EmptyObjectTest()
{
}

void EmptyObjectTest::convertEmptyQMLObject()
{
    // Open file with expected output.
    const QString emptyCppObjectHeaderFilePath = QString(SRCDIR)+"/cpp/emptyobject.h";
    QFile cppHeader(emptyCppObjectHeaderFilePath);
    const bool headerFileOpenSuccesful = cppHeader.open(QIODevice::ReadOnly|QIODevice::Text);
    QVERIFY2(headerFileOpenSuccesful, "Failed to open .h file");
    // Generate
    const QString emptyQMLObjectFilePath = QString(SRCDIR)+"/qml/EmptyObject.qml";
    CppFromQMLGenerator generator(emptyQMLObjectFilePath);
    QString generatedHeader = generator.generateHeader();
    // Compare results
    QTextStream compareStream(&cppHeader);
    QCOMPARE(generatedHeader, compareStream.readAll());
}

void EmptyObjectTest::convertQMLObjectWithOneStringProperty()
{
    // Open file with expected output.
    const QString oneStringCppObjectHeaderFilePath = QString(SRCDIR)+"/cpp/onestringobject.h";
    QFile cppHeader(oneStringCppObjectHeaderFilePath);
    const bool headerFileOpenSuccesful = cppHeader.open(QIODevice::ReadOnly|QIODevice::Text);
    QVERIFY2(headerFileOpenSuccesful, "Failed to open .h file");
    // Generate
    const QString oneStringQMLObjectFilePath = QString(SRCDIR)+"/qml/OneStringObject.qml";
    CppFromQMLGenerator generator(oneStringQMLObjectFilePath);
    QString generatedHeader = generator.generateHeader();
    // Compare results
    QTextStream compareStream(&cppHeader);
    QCOMPARE(generatedHeader, compareStream.readAll());
}

void EmptyObjectTest::convertQMLObjectWithMultipleProperties()
{
    // Open file with expected output.
    const QString multiplePropertiesCppObjectHeaderFilePath = QString(SRCDIR)+"/cpp/multiplepropertiesobject.h";
    QFile cppHeader(multiplePropertiesCppObjectHeaderFilePath);
    const bool headerFileOpenSuccesful = cppHeader.open(QIODevice::ReadOnly|QIODevice::Text);
    QVERIFY2(headerFileOpenSuccesful, "Failed to open .h file");
    // Generate
    const QString multiplePropertiesQMLObjectFilePath = QString(SRCDIR)+"/qml/MultiplePropertiesObject.qml";
    CppFromQMLGenerator generator(multiplePropertiesQMLObjectFilePath);
    QString generatedHeader = generator.generateHeader();
    // Compare results
    QTextStream compareStream(&cppHeader);
    QCOMPARE(generatedHeader, compareStream.readAll());
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    EmptyObjectTest tc;
    QTEST_SET_MAIN_SOURCE_PATH
    return QTest::qExec(&tc, argc, argv);
}

#include "tst_emptyobjecttest.moc"
