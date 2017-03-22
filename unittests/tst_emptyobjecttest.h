#ifndef TST_EMPTYOBJECTTEST_H
#define TST_EMPTYOBJECTTEST_H
#include <QFile>
#include <QString>

class EmptyObjectTest : public QObject
{
    Q_OBJECT

public:
    EmptyObjectTest();
    QFile* sourceFileOpen(const QString fileName);

private Q_SLOTS:
    void convertEmptyQMLObject();
};
#endif // TST_EMPTYOBJECTTEST_H
