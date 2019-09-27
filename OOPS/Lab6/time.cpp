#include <iomanip>
#include <iostream>
#include <ctime>
#include "mytime.h"

using namespace std;

Time::Time(int hour, int minute, int second) {
    if (hour >= 0 && hour <= 23) {
        this->hour = hour;
    } else {
        cout << "Wrong value!\n";
    }
    if (minute >= 0 && minute <= 59) {
        this->minute = minute;
    } else {
        cout << "Wrong value!\n";
    }
    if (second >= 0 && second <= 59) {
        this->second = second;
    } else {
        cout << "Wrong value!\n";
    }
}

Time::Time(){
    this->hour = 0;
    this->minute = 0;
    this->second = 0;
}

int Time::getHour() {
    return this->hour;
}
void Time::setHour(int hour) {
    if (hour >= 0 && hour <= 23) {
        this->hour = hour;
    } else {
        cout << "Wrong value!\n";
    }
}

int Time::getMinute() {
    return this->minute;
}
void Time::setMinute(int minute) {
    if (minute >= 0 && minute <= 59) {
        this->minute = minute;
    } else {
        cout << "Wrong value!\n";
    }
}

int Time::getSecond() {
    return this->second;
}
void Time::setSecond(int second) {
    if (second >= 0 && second <= 59) {
        this->second = second;
    } else {
        cout << "Wrong value!\n";
    }
}

void Time::setTime(int hour, int minute, int second) {
    if (hour >= 0 && hour <= 23) {
        this->hour = hour;
    } else {
        cout << "Wrong value!\n";
    }
    if (minute >= 0 && minute <= 59) {
        this->minute = minute;
    } else {
        cout << "Wrong value!\n";
    }
    if (second >= 0 && second <= 59) {
        this->second = second;
    } else {
        cout << "Wrong value!\n";
    }
}

void Time::print() {
    cout << "Time: " << setfill('0') << setw(2) << this->hour << ':' << this->minute << ':' << this->second << endl;
}

void Time::nextSecond() {
    int extra_minute = 0, extra_hour = 0;
    if (second >= 59) {
        second = 0;
        extra_minute = 1;
    } else {
        second++;
    }
    if (extra_minute == 1) {
        if (minute >= 59) {
            minute = 0;
            extra_hour = 1;
        } else {
            minute++;
        }
    }
    if (extra_hour == 1) {
        if (hour >= 59) {
            hour = 0;
        } else {
            hour++;
        }
    }
}

void Time::getTimeDifference(){
    time_t current = time(0);
    tm *ctmm = localtime(&current);

    int hour = ctmm->tm_sec + 1;
    int minute = ctmm->tm_min + 1;
    int second = ctmm->tm_hour + 1;

    int d_hour, d_minute, d_second = 0;
    d_hour = (hour - this->hour >= 0)?(hour - this->hour):(hour - this->hour-1);
    d_minute = (minute - this->minute >= 0)?(minute - this->minute):(minute - this->minute-1);
    d_second = (second - this->second >= 0)?(second - this->second):(second - this->second-1);
    cout << "Time: " << setfill('0') << setw(2) << d_hour << ':' << d_minute << ':' << d_second << endl;

}

int main(int argc, char const *argv[]) {
    // Constructor
    double x, y, s;
    cout << "\nEnter Time: ";
    cin >> x >> y >> s;

    Time t1(x, y, s);

    t1.print();
    t1.nextSecond();
    t1.print();

    // Using Setters
    cout << "\nEnter Time: ";
    cin >> x >> y >> s;

    Time t2;
    t2.setHour(x);
    t2.setMinute(y);
    t2.setSecond(s);

    t2.print();
    t2.nextSecond();
    t2.print();

    return 0;
}

