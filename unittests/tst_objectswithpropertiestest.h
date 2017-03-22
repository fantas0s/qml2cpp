#ifndef TST_OBJECTSWITHPROPERTIESTEST_H
#define TST_OBJECTSWITHPROPERTIESTEST_H
#include <QFile>
#include <QString>

class ObjectsWithPropertiesTest : public QObject
{
    Q_OBJECT

public:
    ObjectsWithPropertiesTest();
    QFile* sourceFileOpen(const QString fileName);

private Q_SLOTS:
    void convertQMLObjectWithOneStringProperty();
    void convertQMLObjectWithMultipleProperties();
};
#endif // TST_OBJECTSWITHPROPERTIESTEST_H
