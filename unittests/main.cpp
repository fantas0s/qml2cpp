#include "tst_emptyobjecttest.h"
#include "tst_objectswithpropertiestest.h"
#include "tst_filenamestest.h"
#include <QCoreApplication>
#include <QtTest>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    EmptyObjectTest tc;
    QTEST_SET_MAIN_SOURCE_PATH
    int returnValue = QTest::qExec(&tc, argc, argv);
    if (returnValue)
        return returnValue;
    ObjectsWithPropertiesTest tc2;
    returnValue =  QTest::qExec(&tc2, argc, argv);
    if (returnValue)
        return returnValue;
    FilenamesTest tc3;
    return  QTest::qExec(&tc3, argc, argv);
}
