#ifndef CPPFROMQMLGENERATOR_H
#define CPPFROMQMLGENERATOR_H
#include <QTextStream>
class CppFromQMLGenerator
{
public:
    QString generateHeader(QTextStream& qmlStream);
};

#endif // CPPFROMQMLGENERATOR_H
