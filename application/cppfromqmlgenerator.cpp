#include "cppfromqmlgenerator.h"
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QVector>

#define QML_INHERITED_ITEM_COUNT 41

static QVector<QString> alreadySupportedTypes({"int",
                                             "bool",
                                             "double",
                                             "float",
                                             "char",
                                             "short",
                                             "long"});

CppFromQMLGenerator::CppFromQMLGenerator(QString qmlFileName) :
    m_qmlFileName(qmlFileName)
{
    m_appEngine.load(m_qmlFileName);
    if (m_appEngine.rootObjects().length()) {
        m_rootObject = m_appEngine.rootObjects()[0]->metaObject();
    } else {
        m_rootObject = Q_NULLPTR;
    }
    QString className = m_qmlFileName.fileName();
    if (!className.endsWith(".qml")) {
        qWarning() << "Filename is invalid:" << className;
        m_className = "";
    }
    else
    {
        className.chop(4);
        m_className = className;
    }
}

CppFromQMLGenerator::~CppFromQMLGenerator()
{
}

QString CppFromQMLGenerator::generateHeader()
{
    m_headerFileContents = "";
    generateMultipleInclusionProtectionBegin();
    generateHeaderIncludes();
    generateClassDeclaration();
    generateHeaderPublic();
    generateHeaderGetMethods();
    generateHeaderSetMethods();
    generateHeaderSignals();
    generateHeaderPrivateProperties();
    generateClassClosing();
    generateMultipleInclusionProtectionEnd();
    return m_headerFileContents;
}

void CppFromQMLGenerator::generateMultipleInclusionProtectionBegin()
{
    m_headerFileContents += "#ifndef _" + m_className.toUpper() + "_H\n";
    m_headerFileContents += "#define _" + m_className.toUpper() + "_H\n";
}

void CppFromQMLGenerator::generateMultipleInclusionProtectionEnd()
{
    m_headerFileContents += "#endif /* _" + m_className.toUpper() + "_H */\n";
}

void CppFromQMLGenerator::generateHeaderIncludes()
{
    m_headerFileContents += "#include <QObject>\n";
    QVector<QString> listOfIncludes;
    for (int i = QML_INHERITED_ITEM_COUNT ; i < m_rootObject->propertyCount() ; ++i) {
        const QString typeName(m_rootObject->property(i).typeName());
        if (!alreadySupportedTypes.contains(typeName)) {
            if (!listOfIncludes.contains(typeName)) {
                listOfIncludes.append(typeName);
            }
        }
    }
    QString appendString;
    foreach (appendString, listOfIncludes) {
        m_headerFileContents += "#include <" + appendString + ">\n";
    }
}

void CppFromQMLGenerator::generateClassDeclaration()
{
    m_headerFileContents += "class " + m_className + " : public QObject\n";
    m_headerFileContents += "{\n";
}

void CppFromQMLGenerator::generateHeaderPublic()
{
    m_headerFileContents += "public:\n";
    m_headerFileContents += "    " + m_className + "();\n";
}

void CppFromQMLGenerator::generateHeaderGetMethods()
{
    for (int i = QML_INHERITED_ITEM_COUNT ; i < m_rootObject->propertyCount() ; ++i) {
        QString uppercaseStartingName = QString(m_rootObject->property(i).name());
        uppercaseStartingName[0] = uppercaseStartingName[0].toUpper();
        m_headerFileContents += "    "
                          + QString(m_rootObject->property(i).typeName())
                          + " get"
                          + uppercaseStartingName
                          + "() const;\n";
    }
}

void CppFromQMLGenerator::generateHeaderSetMethods()
{
    for (int i = QML_INHERITED_ITEM_COUNT ; i < m_rootObject->propertyCount() ; ++i) {
        QString uppercaseStartingName = QString(m_rootObject->property(i).name());
        uppercaseStartingName[0] = uppercaseStartingName[0].toUpper();
        m_headerFileContents += "    void set"
                          + uppercaseStartingName
                          + "(const "
                          + QString(m_rootObject->property(i).typeName())
                          + " input);\n";
    }
}

void CppFromQMLGenerator::generateHeaderSignals()
{

    if (m_rootObject->propertyCount() > QML_INHERITED_ITEM_COUNT)
        m_headerFileContents += "signals:\n";
    for (int i = QML_INHERITED_ITEM_COUNT ; i < m_rootObject->propertyCount() ; ++i) {
        m_headerFileContents += "    void "
                          + QString(m_rootObject->property(i).name())
                          + "Changed();\n";
    }
}

void CppFromQMLGenerator::generateHeaderPrivateProperties()
{
    m_headerFileContents += "private:\n";
    m_headerFileContents += "    Q_OBJECT\n";
    for (int i = QML_INHERITED_ITEM_COUNT ; i < m_rootObject->propertyCount() ; ++i) {
        QString uppercaseStartingName = QString(m_rootObject->property(i).name());
        uppercaseStartingName[0] = uppercaseStartingName[0].toUpper();
        m_headerFileContents += "    Q_PROPERTY("
                             + QString(m_rootObject->property(i).typeName())
                             + " "
                             + QString(m_rootObject->property(i).name())
                             + " READ get"
                             + uppercaseStartingName
                             + " WRITE set"
                             + uppercaseStartingName
                             + " NOTIFY "
                             + QString(m_rootObject->property(i).name())
                             + "Changed)\n";
    }
    for (int i = QML_INHERITED_ITEM_COUNT ; i < m_rootObject->propertyCount() ; ++i) {
        m_headerFileContents += "    "
                          + QString(m_rootObject->property(i).typeName())
                          + " m_"
                          + QString(m_rootObject->property(i).name())
                          + ";\n";
    }
}

void CppFromQMLGenerator::generateClassClosing()
{
    m_headerFileContents += "};\n";
}

QString CppFromQMLGenerator::generateSource()
{
    m_sourceFileContents = "";
    generateSourceInclude();
    generateSourceConstructor();
    generateSourceGetMethods();
    generateSourceSetMethods();
    return m_sourceFileContents;
}

void CppFromQMLGenerator::generateSourceInclude()
{
    m_sourceFileContents += "#include \"" + getHeaderFilename() + "\"\n";
}

void CppFromQMLGenerator::generateSourceConstructor()
{
    m_sourceFileContents += m_className + "::" + m_className + "()";
    if (m_rootObject->propertyCount() > QML_INHERITED_ITEM_COUNT)
        m_sourceFileContents += " :";
    m_sourceFileContents += "\n";
    for (int i = QML_INHERITED_ITEM_COUNT ; i < m_rootObject->propertyCount() ; ++i) {
        m_sourceFileContents += "    m_"
                          + QString(m_rootObject->property(i).name())
                          + "(";
        if ((QVariant::String == m_rootObject->property(i).type()) ||
            (QVariant::Color == m_rootObject->property(i).type()))
            m_sourceFileContents += "\"" + m_rootObject->property(i).read(m_appEngine.rootObjects()[0]).toString() + "\")";
        else
            m_sourceFileContents += m_rootObject->property(i).read(m_appEngine.rootObjects()[0]).toString() + ")";
        if (i < m_rootObject->propertyCount()-1)
            m_sourceFileContents += ",";
        m_sourceFileContents += "\n";
    }
    m_sourceFileContents += "{\n}\n";
}

void CppFromQMLGenerator::generateSourceGetMethods()
{
    for (int i = QML_INHERITED_ITEM_COUNT ; i < m_rootObject->propertyCount() ; ++i) {
        QString uppercaseStartingName = QString(m_rootObject->property(i).name());
        uppercaseStartingName[0] = uppercaseStartingName[0].toUpper();
        m_sourceFileContents += "\n"
                          + QString(m_rootObject->property(i).typeName())
                          + " "
                          + m_className
                          + "::get"
                          + uppercaseStartingName
                          + "() const\n";
        m_sourceFileContents += "{\n    return m_"
                          + QString(m_rootObject->property(i).name())
                          + ";\n}\n";
    }
}

void CppFromQMLGenerator::generateSourceSetMethods()
{
    for (int i = QML_INHERITED_ITEM_COUNT ; i < m_rootObject->propertyCount() ; ++i) {
        QString uppercaseStartingName = QString(m_rootObject->property(i).name());
        uppercaseStartingName[0] = uppercaseStartingName[0].toUpper();
        m_sourceFileContents += "\nvoid "
                          + m_className
                          + "::set"
                          + uppercaseStartingName
                          + "(const "
                          + QString(m_rootObject->property(i).typeName())
                          + " input)\n";
        m_sourceFileContents += "{\n    m_"
                          + QString(m_rootObject->property(i).name())
                          + " = input;\n";
        m_sourceFileContents += "    emit "
                          + QString(m_rootObject->property(i).name())
                          + "Changed();\n}\n";
    }
}

QString CppFromQMLGenerator::getHeaderFilename()
{
    return m_className.toLower() + ".h";
}

QString CppFromQMLGenerator::getSourceFilename()
{
    return m_className.toLower() + ".cpp";
}
