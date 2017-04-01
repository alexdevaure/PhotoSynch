#include "copyfiles.h"
#include <QDebug>
#include <QDir>
#include <QUrl>
#include <photo.h>


CopyFiles::CopyFiles(QObject *parent) : QObject(parent), m_sourceDirectory(), m_destinationDirectory()
{
    qDebug() << "CopyFiles constructor";
}

void CopyFiles::setSourceDirectory(const QString &s)
{
    if (s != m_sourceDirectory){
        m_sourceDirectory = s;
        sourceDirectoryChanged();
    }
    qDebug() << "Update source directory: " << m_sourceDirectory;
}

QString CopyFiles::sourceDirectory()
{
    qDebug() << "Call sourceDirectory " << m_sourceDirectory;
    return m_sourceDirectory;
}

void CopyFiles::setDestinationDirectory(const QString &s)
{
    if (s != m_destinationDirectory){
        m_destinationDirectory = s;
        destinationDirectoryChanged();
    }
    qDebug() << "Update destination directory: " << m_destinationDirectory;
}

QString CopyFiles::destinationDirectory()
{
    return m_destinationDirectory;
}

// copy the files from the camera to hard drive
void CopyFiles::synchronise()
{
    qDebug() << "Start synchronisation";
    listFiles(QUrl(m_sourceDirectory));
}

void CopyFiles::listFiles(const QUrl &directory)
{
    std::vector<Photo> photos;
    QDir currentDir(directory.path());
    if (currentDir.exists())
    {
        qDebug() << currentDir.absolutePath();
        // Filters filters = NoFilter, SortFlags sort = NoSort
        QFileInfoList filesList = currentDir.entryInfoList(QDir::Files, QDir::Name);
        for (const auto& file : filesList)
        {
            qDebug() << file.absoluteFilePath();
            Photo photo(file.absoluteFilePath(), file.created());
            photos.push_back(photo);
        }
        qDebug() << photos.size();

        for (const auto& photo : photos)
        {
            photo.copy(QUrl(m_destinationDirectory).path());
        }
    }
}
