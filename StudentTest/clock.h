#ifndef CLOCK_H
#define CLOCK_H
#include <QDateTime>
class clock{            //时钟类
private:
    QDateTime time;     //私有成员：原始时间
    QDateTime now;      //私有成员：当前时间
public:
    void sleep(int second){                     //延时函数
        time = QDateTime::currentDateTime();    //把当前时间赋值为“原始时间”
        do{
            now = QDateTime::currentDateTime(); //把当前时间赋值为变量“当前时间”
        } while (time.secsTo(now) <=second );   //当原始时间对比变量“当前时间”小于设定秒数（second）时循环
    }
};

#endif // CLOCK_H
