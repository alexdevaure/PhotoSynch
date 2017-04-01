#include "photo.h"
#include <QDebug>
#include <QDir>

static QDir destination(const QString& root, int year, int month, int day);

Photo::Photo(const QString &file_name, const QDateTime &date) :
    m_file(file_name), m_date(date)
{

}

void Photo::copy(const QString &dest_directory) const
{
    // retrieve year, month and day from the date
    QString year;
    QString month;
    QString day;
    QDate d = m_date.date();
    //year = QString::number(d.day());
    year = QString("%1").arg(d.year(), 4, 10, QLatin1Char('0'));
    //month = QString::number(d.month());
    month = QString("%1").arg(d.month(), 2, 10, QLatin1Char('0'));
    //day = QString::number(d.year());
    day = QString("%1").arg(d.day(), 2, 10, QLatin1Char('0'));

    QDir dest = destination(dest_directory, d.year(), d.month(), d.day());
    qDebug() << "Move " << m_file << "to" << dest.absolutePath();
    QFile source{m_file};
    QFileInfo source_info{source};
    QString to{dest.absolutePath()};
    to += QDir::separator() + source_info.fileName();

    qDebug() << "Copy " << source_info.absoluteFilePath() << "to" << to;
}


QDir destination(const QString& root, int year, int month, int day)
{
    QDir dest{root};

    QString year_directory = QString("%1").arg(year, 4, 10, QLatin1Char('0'));
    bool exist = dest.cd(year_directory);
    if (!exist)
    {
        dest.mkdir(year_directory);
        dest.cd(year_directory);
        qDebug() << dest.absolutePath();
    }
    QString month_directory = QString("%1").arg(month, 2, 10, QLatin1Char('0'));
    exist = dest.cd(month_directory);
    if (!exist)
    {
        dest.mkdir(month_directory);
        dest.cd(month_directory);
        qDebug() << dest.absolutePath();
    }
    QString day_directory = QString("%1").arg(day, 2, 10, QLatin1Char('0'));
    exist = dest.cd(day_directory);
    if (!exist)
    {
        dest.mkdir(day_directory);
        dest.cd(day_directory);
        qDebug() << dest.absolutePath();
    }

    return dest;
}
