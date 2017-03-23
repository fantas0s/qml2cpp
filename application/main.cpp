#include "cppfromqmlgenerator.h"
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("QML to C++");
    QCoreApplication::setApplicationVersion("0.9");

    QCommandLineParser parser;
    parser.setApplicationDescription("qml2cpp is a C++ code generator that creates C++ files from a QML file.\n"
                                     "Resulting class can be instantiated as a QML object that can be used as a\n"
                                     "replacement of the original QML object.\n"
                                     "Supports only very basic QML objects, e.g. JavaScript is not copied.");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("files", "One or more QML files to convert to C++.");
    parser.process(app);

    QStringList filesToConvert = parser.positionalArguments();
    if (!filesToConvert.length())
        parser.showHelp(EXIT_FAILURE);

    QString fileName;
    foreach (fileName, filesToConvert) {
        CppFromQMLGenerator generator(fileName);
        QFile headerFile(generator.getHeaderFilename());
        if (headerFile.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            QTextStream headerFileStream(&headerFile);
            headerFileStream << generator.generateHeader();
            headerFile.close();
        }
        QFile sourceFile(generator.getSourceFilename());
        if (sourceFile.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            QTextStream sourceFileStream(&sourceFile);
            sourceFileStream << generator.generateSource();
            sourceFile.close();
        }
    }
    return EXIT_SUCCESS;
}
