#include <QString>
#include <QtTest>
#include "../application/cppfromqmlgenerator.h"

class EmptyObjectTest : public QObject
{
    Q_OBJECT

public:
    EmptyObjectTest();

private Q_SLOTS:
    void convertEmptyQMLObject();
};

EmptyObjectTest::EmptyObjectTest()
{
}

void EmptyObjectTest::convertEmptyQMLObject()
{
    // Open file with empty QML Object
    const QString emptyQMLObjectFilePath = QString(SRCDIR)+"/qml/EmptyObject.qml";
    QFile qmlSource(emptyQMLObjectFilePath);
    const bool qmlFileOpenSuccesful = qmlSource.open(QIODevice::ReadOnly|QIODevice::Text);
    QVERIFY2(qmlFileOpenSuccesful, "Failed to open QML file");
    // Open file with expected output.
    const QString emptyCppObjectHeaderFilePath = QString(SRCDIR)+"/cpp/emptyobject.h";
    QFile cppHeader(emptyCppObjectHeaderFilePath);
    const bool headerFileOpenSuccesful = cppHeader.open(QIODevice::ReadOnly|QIODevice::Text);
    QVERIFY2(headerFileOpenSuccesful, "Failed to open .h file");
    // Generate
    QTextStream readStream(&qmlSource);
    CppFromQMLGenerator generator;
    QString generatedHeader = generator.generateHeader(readStream);
    // Compare results
}

QTEST_APPLESS_MAIN(EmptyObjectTest)

#include "tst_emptyobjecttest.moc"
