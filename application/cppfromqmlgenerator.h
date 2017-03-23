#ifndef CPPFROMQMLGENERATOR_H
#define CPPFROMQMLGENERATOR_H
#include <QString>
#include <QFile>
#include <QUrl>
#include <QQmlApplicationEngine>

class CppFromQMLGenerator
{
public:
    CppFromQMLGenerator(QString qmlFileName);
    ~CppFromQMLGenerator();
    QString generateHeader();
    QString generateSource();
    QString getHeaderFilename();
    QString getSourceFilename();
private:
    CppFromQMLGenerator();
    void generateMultipleInclusionProtectionBegin();
    void generateMultipleInclusionProtectionEnd();
    void generateHeaderIncludes();
    void generateClassDeclaration();
    void generateHeaderPublic();
    void generateHeaderGetMethods();
    void generateHeaderSetMethods();
    void generateHeaderSignals();
    void generateHeaderPrivateProperties();
    void generateSourceInclude();
    void generateSourceConstructor();
    void generateSourceGetMethods();
    void generateSourceSetMethods();
    QUrl m_qmlFileName;
    QString m_className;
    QString m_headerFileContents;
    QString m_sourceFileContents;
    QQmlApplicationEngine m_appEngine;
    const QMetaObject* m_rootObject;

    void generateClassClosing();
};

#endif // CPPFROMQMLGENERATOR_H
