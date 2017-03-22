#ifndef _MULTIPLEPROPERTIESOBJECT_H
#define _MULTIPLEPROPERTIESOBJECT_H
#include <QObject>
#include <QString>
#include <QColor>
class MultiplePropertiesObject : public QObject
{
public:
    MultiplePropertiesObject();
    QString getMyText() const;
    int getANumber() const;
    QColor getDasColor() const;
    QString getAnotherText() const;
    double getDoubleDareNumber() const;
    double getARealNumber() const;
    bool getThisIsFalse() const;
    int getBNumber() const;
    QColor getBackgroundColor() const;
    double getDoubleAgain() const;
    double getNotSoRealNumber() const;
    bool getThisIsTrue() const;
    void setMyText(const QString input);
    void setANumber(const int input);
    void setDasColor(const QColor input);
    void setAnotherText(const QString input);
    void setDoubleDareNumber(const double input);
    void setARealNumber(const double input);
    void setThisIsFalse(const bool input);
    void setBNumber(const int input);
    void setBackgroundColor(const QColor input);
    void setDoubleAgain(const double input);
    void setNotSoRealNumber(const double input);
    void setThisIsTrue(const bool input);
signals:
    void myTextChanged();
    void aNumberChanged();
    void dasColorChanged();
    void anotherTextChanged();
    void doubleDareNumberChanged();
    void aRealNumberChanged();
    void thisIsFalseChanged();
    void bNumberChanged();
    void backgroundColorChanged();
    void doubleAgainChanged();
    void notSoRealNumberChanged();
    void thisIsTrueChanged();
private:
    Q_OBJECT
    Q_PROPERTY(QString myText READ getMyText WRITE setMyText NOTIFY myTextChanged)
    Q_PROPERTY(int aNumber READ getANumber WRITE setANumber NOTIFY aNumberChanged)
    Q_PROPERTY(QColor dasColor READ getDasColor WRITE setDasColor NOTIFY dasColorChanged)
    Q_PROPERTY(QString anotherText READ getAnotherText WRITE setAnotherText NOTIFY anotherTextChanged)
    Q_PROPERTY(double doubleDareNumber READ getDoubleDareNumber WRITE setDoubleDareNumber NOTIFY doubleDareNumberChanged)
    Q_PROPERTY(double aRealNumber READ getARealNumber WRITE setARealNumber NOTIFY aRealNumberChanged)
    Q_PROPERTY(bool thisIsFalse READ getThisIsFalse WRITE setThisIsFalse NOTIFY thisIsFalseChanged)
    Q_PROPERTY(int bNumber READ getBNumber WRITE setBNumber NOTIFY bNumberChanged)
    Q_PROPERTY(QColor backgroundColor READ getBackgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)
    Q_PROPERTY(double doubleAgain READ getDoubleAgain WRITE setDoubleAgain NOTIFY doubleAgainChanged)
    Q_PROPERTY(double notSoRealNumber READ getNotSoRealNumber WRITE setNotSoRealNumber NOTIFY notSoRealNumberChanged)
    Q_PROPERTY(bool thisIsTrue READ getThisIsTrue WRITE setThisIsTrue NOTIFY thisIsTrueChanged)
    QString m_myText;
    int m_aNumber;
    QColor m_dasColor;
    QString m_anotherText;
    double m_doubleDareNumber;
    double m_aRealNumber;
    bool m_thisIsFalse;
    int m_bNumber;
    QColor m_backgroundColor;
    double m_doubleAgain;
    double m_notSoRealNumber;
    bool m_thisIsTrue;
};
#endif /* _MULTIPLEPROPERTIESOBJECT_H */
