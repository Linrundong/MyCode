#ifndef FINGERBASE_H
#define FINGERBASE_H
#include <QtSql>
#include <QVector>
#include <utility>

struct Node {
    int id;
    QString studentNum;
    QString name;
    int classRef;
    QString date;
    QString time;
    int scheduleRef;
};

struct schedule {
    int id;
    QString tip;
    QString time;
    QString start;
    QString end;
    int flag;
};

class FingerBase
{
public:
    FingerBase();
    bool addStudent(QString studentNum, QString name, int classRef);
    int getFingerId(QString studentNum);
    bool getAllStudent(QVector<std::pair<int, QString>>& ret);
    bool deleteStudent(int index);

    bool addclass(QString className);
    bool getAllClass(QVector<std::pair<int, QString>>& ret);
    bool deleteClass(int index);

    bool addSchedule(QString tip, QString time, QString start, QString end, int flag);
    bool getAllSchedule(QVector<std::pair<int, QString>>& ret);
    bool getScheduleById(int index, schedule& data);
    bool getAllSchedule(QVector<schedule>& data);
    bool deleteSchedule(int index);

    bool addArriveCheck(QString time, int fingerID);
    bool getAllTime(QVector<std::pair<int, QString>>& ret);
    bool deleteArriveCheck(int index);

    bool getAllRecord(QVector<Node>& table);

    static bool baseExist();
    static bool createBase();
    static bool createConnection();

private:
    QSqlQuery m_Query;
};

#endif // FINGERBASE_H
