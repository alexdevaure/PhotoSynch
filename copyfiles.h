#ifndef COPYFILES_H
#define COPYFILES_H

#include <QObject>

class CopyFiles : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sourceDirectory READ sourceDirectory WRITE setSourceDirectory NOTIFY sourceDirectoryChanged)
    Q_PROPERTY(QString destinationDirectory READ destinationDirectory WRITE setDestinationDirectory NOTIFY destinationDirectoryChanged)
public:
    explicit CopyFiles(QObject *parent = 0);

    void setSourceDirectory(const QString& s);
    QString sourceDirectory();

    void setDestinationDirectory(const QString& s);
    QString destinationDirectory();

signals:
    void sourceDirectoryChanged();
    void destinationDirectoryChanged();
public slots:
    void synchronise();

private:
    QString m_sourceDirectory;
    QString m_destinationDirectory;

    void listFiles(const QUrl& directory);
};

#endif // COPYFILES_H
