#include <iostream>

class Time {
   private:
    int hour, minute, second;

   public:
    Time();
    Time(int hour, int minute, int second);

    int getHour();
    void setHour(int hour);
    int getMinute();
    void setMinute(int minute);
    int getSecond();
    void setSecond(int second);
    void setTime(int hour, int minute, int second);
    void print();
    void nextSecond();
    void getTimeDifference();
};

