#ifndef _EMPTYOBJECT_H
#define _EMPTYOBJECT_H
#include <QObject>
class EmptyObject : public QObject
{
public:
    EmptyObject();
private:
    Q_OBJECT
};
#endif /* _EMPTYOBJECT_H */
