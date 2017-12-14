#include "FingerBase.h"
#include <QFile>

FingerBase::FingerBase()
{

}

bool FingerBase::addStudent(QString studentNum, QString name, int classRef) {
    m_Query.prepare("INSERT INTO Student (studentNum, name, classRef) "
                 "VALUES (:studentNum, :name, :classRef);");
    m_Query.bindValue(":studentNum", studentNum);
    m_Query.bindValue(":name", name);
    m_Query.bindValue(":classRef", classRef);
    if(!m_Query.exec()) {
        qDebug() << "Error: Insert Student Fail!!!";
        return false;
    }
    return true;
}

bool FingerBase::deleteStudent(int index) {
    m_Query.prepare("DELETE FROM Student WHERE id = :index;");
    m_Query.bindValue(":index", index);
    if(!m_Query.exec()) {
        qDebug() << "Error: Delete Student Fail!!!";
        return false;
    }
    return true;
}

int FingerBase::getFingerId(QString studentNum) {
    m_Query.prepare("SELECT id FROM Student WHERE studentNum = :stduentNum;");
    m_Query.bindValue(":studentNum", studentNum);
    if(!m_Query.exec()) {
        qDebug() << "Error:  GetFingerId Fail!!!";
        return false;
    }

    m_Query.next();
    return m_Query.value(0).toInt();
}

bool FingerBase::getAllStudent(QVector<std::pair<int, QString>>& ret) {
    m_Query.exec("SELECT id, studentNum FROM Student;");
    while(m_Query.next()) {
        ret.push_back(std::make_pair(m_Query.value(0).toInt(), m_Query.value(1).toString()));
    }
    return true;
}

bool FingerBase::addclass(QString className) {
    m_Query.prepare("INSERT INTO Classes (name) VALUE(:name);");
    m_Query.bindValue(":name", className);
    if(!m_Query.exec()) {
        qDebug() << "Error: Insert Classes Fail!!!";
        return false;
    }
    return true;
}

bool FingerBase::getAllClass(QVector<std::pair<int, QString>> &ret) {
    m_Query.exec("SELECT id, name FROM Classes;");
    while (m_Query.next()) {
        ret.push_back(std::make_pair(m_Query.value(0).toInt(), m_Query.value(1).toString()));
    }

    return true;
}

bool FingerBase::deleteClass(int index) {
    m_Query.prepare("DELETE FROM Classes WHERE id = :index;");
    m_Query.bindValue(":index", index);
    if(!m_Query.exec()) {
        qDebug() << "Error: Delete Classes Fail!!!";
        return false;
    }
    return true;
}

bool FingerBase::addSchedule(QString tip, QString time, QString start, QString end, int flag) {
    m_Query.prepare("INSERT INTO Schedule (tip, time, start, end, flag)"
                 "VALUES (:tip, :time, :start, :end, :flag);");
    m_Query.bindValue(":tip", tip);
    m_Query.bindValue(":time", time);
    m_Query.bindValue(":start", start);
    m_Query.bindValue(":end", end);
    m_Query.bindValue(":flag", flag);
    if(!m_Query.exec()) {
        qDebug() << "Error: Insert Schedule Fail!!!";
        return false;
    }
    return true;
}

bool FingerBase::getAllSchedule(QVector<std::pair<int, QString>>& ret) {
    m_Query.exec("SELECT id, tip FROM Schedule;");
    while (m_Query.next()) {
        ret.push_back(std::make_pair(m_Query.value(0).toInt(), m_Query.value(1).toString()));
    }

    return true;
}

bool FingerBase::getAllSchedule(QVector<schedule>& vdata) {
    m_Query.exec("SELECT * FROM Schedule;");
    schedule data;
    while(m_Query.next()) {
        data.id = m_Query.value(0).toInt();
        data.tip = m_Query.value(1).toString();
        data.time = m_Query.value(2).toString();
        data.start = m_Query.value(3).toString();
        data.end = m_Query.value(4).toString();
        data.flag = m_Query.value(5).toInt();
        vdata.push_back(data);
    }
    return true;
}

bool FingerBase::getScheduleById(int index, schedule& data) {
    m_Query.prepare("SELECT * FROM Schedule WHERE id = :index;");
    m_Query.bindValue(":index", index);

    if(!m_Query.exec()) {
        qDebug() << "Error: getScheduleById Fail!!!";
        return false;
    }
    m_Query.next();
    data.id = m_Query.value(0).toInt();
    data.tip = m_Query.value(1).toString();
    data.time = m_Query.value(2).toString();
    data.start = m_Query.value(3).toString();
    data.end = m_Query.value(4).toString();
    data.flag = m_Query.value(5).toInt();

    return true;
}

bool FingerBase::deleteSchedule(int index) {
    m_Query.prepare("DELETE FROM Schedule WHERE id = :index;");
    m_Query.bindValue(":index", index);
    if(!m_Query.exec()) {
        qDebug() << "Error: Delete Schedule Fail!!!";
        return false;
    }
    return true;
}

bool FingerBase::addArriveCheck(QString time, int fingerID) {

}

bool FingerBase::deleteArriveCheck(int index) {
    m_Query.prepare("DELETE FROM ArriveCheck WHERE id = :index;");
    m_Query.bindValue(":index", index);
    if(!m_Query.exec()) {
        qDebug() << "Error: Delete ArriveCheck Fail!!!";
        return false;
    }
    return true;
}

bool FingerBase::getAllTime(QVector<std::pair<int, QString>>& ret) {
    m_Query.exec("SELECT id, date FROM ArriveCheck GROUP BY date;");
    while (m_Query.next()) {
        ret.push_back(std::make_pair(m_Query.value(0).toInt(), m_Query.value(1).toString()));
    }

    return true;
}

bool FingerBase::getAllRecord(QVector<Node>& table) {
    m_Query.exec("select Student.id, Student.studentNum, Student.name, Student.classRef, "
                 "ArriveCheck.date, ArriveCheck.time, ArriveCheck.scheduleRef from Student "
                 "cross join ArriveCheck on Student.id=ArriveCheck.who;");
    Node tmp;
    while(m_Query.next()) {
        tmp.id = m_Query.value(0).toInt();
        tmp.studentNum = m_Query.value(1).toString();
        tmp.name = m_Query.value(2).toString();
        tmp.classRef = m_Query.value(3).toInt();
        tmp.date = m_Query.value(4).toString();
        tmp.time = m_Query.value(5).toString();
        tmp.scheduleRef = m_Query.value(6).toInt();

        table.push_back(tmp);
    }

    return true;
}

bool FingerBase::baseExist() {
    return QFile::exists("FingerDB.db");
}

bool FingerBase::createConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // QSQLITE
       db.setDatabaseName("FingerDB.db");
       if (!db.open()) {
           return false;
       }
       return true;
}

bool FingerBase::createBase() {
    QSqlQuery m_Query;
    m_Query.exec("DROP TABLE Student;");
    m_Query.exec("DROP TABLE Classes;");
    m_Query.exec("DROP TABLE ArriveCheck;");
    m_Query.exec("DROP TABLE Schedule;");

    m_Query.exec("CREATE TABLE Student ("
                 "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                 "studentNum TEXT NOT NULL,"
                 "name TEXT NOT NULL,"
                 "classRef INTEGER NOT NULL,"
                 "UNIQUE (studentNum),"
                 "FOREIGN KEY (classRef) REFERENCES Classes(id));");

    m_Query.exec("CREATE TABLE Classes ("
                 "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                 "name TEXT NOT NULL,"
                 "UNIQUE (name));");

    m_Query.exec("CREATE TABLE ArriveCheck ("
                 "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                 "who INTEGER NOT NULL,"
                 "date TEXT NOT NULL,"
                 "time TEXT NOT NULL,"
                 "scheduleRef INTEGER NOT NULL,"
                 "FOREIGN KEY (who) REFERENCES Student(id),"
                 "FOREIGN KEY (scheduleRef) REFERENCES Schedule(id));");

    m_Query.exec("CREATE TABLE Schedule ("
                 "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                 "tip TEXT NOT NULL,"
                 "time TEXT NOT NULL,"
                 "start TEXT NOT NULL,"
                 "end TEXT NOT NULL,"
                 "flag INTEGER NOT NULL);");

    return true;
}
