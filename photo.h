#ifndef PHOTO_H
#define PHOTO_H
#include <QString>
#include <QDateTime>

class Photo
{
public:
    Photo(const QString& file_name, const QDateTime& date);
    void copy(const QString& dest_directory) const;
private:
    QString m_file;
    QDateTime m_date;
};

#endif // PHOTO_H
