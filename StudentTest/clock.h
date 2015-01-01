#ifndef CLOCK_H
#define CLOCK_H
#include <QDateTime>
class clock{
private:
    QDateTime time;
    QDateTime now;
public:
    void sleep(int second){
        time = QDateTime::currentDateTime();
        do{
            now = QDateTime::currentDateTime();
        } while (time.secsTo(now) <=second );
    }
};

#endif // CLOCK_H
