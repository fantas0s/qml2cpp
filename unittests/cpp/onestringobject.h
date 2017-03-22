#ifndef _ONESTRINGOBJECT_H
#define _ONESTRINGOBJECT_H
#include <QObject>
#include <QString>
class OneStringObject : public QObject
{
public:
    OneStringObject();
    QString getMyString() const;
    void setMyString(const QString input);
signals:
    void myStringChanged();
private:
    Q_OBJECT
    Q_PROPERTY(QString myString READ getMyString WRITE setMyString NOTIFY myStringChanged)
    QString m_myString;
};
#endif /* _ONESTRINGOBJECT_H */
