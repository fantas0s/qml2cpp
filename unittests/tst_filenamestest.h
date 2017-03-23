#ifndef TST_FILENAMESTEST_H
#define TST_FILENAMESTEST_H
#include <QFile>
#include <QString>

class FilenamesTest : public QObject
{
    Q_OBJECT

public:
    FilenamesTest();

private Q_SLOTS:
    void testHeaderAndSourceFileForEmptyObject();
    void testHeaderAndSourceFileForMultiplePropertiesObject();
};
#endif // TST_FILENAMESTEST_H
