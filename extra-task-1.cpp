#include <iostream>
#include <assert.h>
#include <cmath>

using namespace std;


//1
/*
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.*/
inline double seconds_difference(double time_1, double time_2)
{
    assert(time_1 > 0 && time_2 > 0);
    return time_2 - time_1;
}

//вспомогательная функция,определяющая абсолютную величину разности между аргументами
inline double fabs(double x, double y)
{
    return abs(x - y);
}

//2
/*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.*/
double hours_difference(double time_1, double time_2)
{
    assert(time_1 > 0 && time_2 > 0);
    return seconds_difference(time_1, time_2) / 3600.0;
}

//3
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.*/

inline double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes && minutes < 60 && 0 <= seconds && seconds < 60);
    return hours + minutes / 60.0 + seconds / 3600.0;
}

//4
    /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.*/

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    double fractional = hours - floor(hours);//дробная часть
    return int(floor(hours)) % 24 + fractional;
}



//5
/*
    Implement three functions
        * get_hours
        * get_minutes
        * get_seconds
    They are used to determine the hours part, minutes part and seconds part
    of a time in seconds. E.g.:

    >>> get_hours(3800)
    1

    >>> get_minutes(3800)
    3

    >>> get_seconds(3800)
    20

    In other words, if 3800 seconds have elapsed since midnight,
    it is currently 01:03:20 (hh:mm:ss).
*/
inline int get_hours(int seconds)
{
    return seconds / 3600;
}

inline int get_minutes(int seconds)
{
    return (seconds % 3600) / 60;
}

inline int get_seconds(int seconds)
{
    return (seconds % 3600) % 60;
}

//6
/*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.*/
double time_to_utc(int utc_offset, double time)
{
    assert(0 <= time && time < 24 && abs(utc_offset) <= 12);
    if (utc_offset == 0)
        return time;
    if (utc_offset > 0)
    {
        if (time - utc_offset >= 0)
            return time - utc_offset;
        else
            return 24 + (time - utc_offset);
    }
    if (time - utc_offset < 24)
        return time - utc_offset;
    else
        return int(time - utc_offset) % 24;
}

//7
/*
        Return UTC time in time zone utc_offset.*/

double time_from_utc(int utc_offset, double time)
{
    assert(0 <= time && time < 24 && abs(utc_offset) <= 12);
    if (utc_offset == 0)
        return time;
    if (utc_offset > 0)
    {
        if (time + utc_offset < 24)
            return time + utc_offset;
        else
            return int(time + utc_offset) % 24;
    }
    if (time + utc_offset >= 0)
        return time + utc_offset;
    else
        return 24 + (time + utc_offset);
}


int main()
{
    setlocale(LC_ALL, "russian");
    double eps = DBL_EPSILON;

    cout << "Task1" << endl;

    cout <<"3600.0 c - 1800.0 c = "<<seconds_difference(1800.0, 3600.0)<<" с"<<endl;
    assert(fabs(seconds_difference(1800.0, 3600.0), 1800.0) < eps);

    cout << "\n";

    cout <<"1800.0 c - 3600.0 c = "<<seconds_difference(3600.0, 1800.0) <<" с"<< endl;
    assert(fabs(seconds_difference(3600.0, 1800.0), -1800.0) < eps);

    cout << "\n";

    cout <<"2160.0 c - 1800.0 c = "<<seconds_difference(1800.0, 2160.0) <<" с"<< endl;
    assert(fabs(seconds_difference(1800.0, 2160.0), 360.0) < eps);

    cout << "\n";

    cout <<"1800.0 c - 1800.0 c = "<<seconds_difference(1800.0, 1800.0) <<" с"<< endl;
    assert(fabs(seconds_difference(1800.0, 1800.0), 0.0) < eps);

    cout << "\n Тесты пройдены!\n" << endl;

    cout << "Task2" << endl;

    cout << "3600.0 c - 1800.0 c = " << hours_difference(1800.0, 3600.0) << " ч" << endl;
    assert(fabs(hours_difference(1800.0, 3600.0),0.5) < eps);

    cout << "\n";

    cout << "1800.0 c - 3600.0 c = " << hours_difference(3600.0, 1800.0) << " ч" << endl;
    assert(fabs(hours_difference(3600.0, 1800.0), -0.5) < eps);

    cout << "\n";

    cout << "2160.0 c - 1800.0 c = " << hours_difference(1800.0, 2160.0) << " ч" << endl;
    assert(fabs(hours_difference(1800.0, 2160.0), 0.1) < eps);

    cout << "\n";

    cout << "1800.0 c - 1800.0 c = " << hours_difference(1800.0, 1800.0) << " ч" << endl;
    assert(fabs(hours_difference(1800.0, 1800.0), 0.0) < eps);

    cout << "\n Тесты пройдены!\n" << endl;

    cout << "Task3" << endl;

    cout << ">>> to_float_hours(0, 15, 0)" << endl;
    cout << to_float_hours(0, 15, 0) << "\n" << endl;
    assert(fabs(to_float_hours(0, 15, 0), 0.25) < eps);

    cout << ">>> to_float_hours(2, 45, 9)" << endl;
    cout << to_float_hours(2, 45, 9) << "\n" << endl;
    assert(fabs(to_float_hours(2, 45, 9), 2.7525) < eps);

    cout << ">>> to_float_hours(1, 0, 36)" << endl;
    cout << to_float_hours(1, 0, 36) << "\n" << endl;
    assert(fabs(to_float_hours(1, 0, 36), 1.01) < eps);

    cout << "\n Тесты пройдены!\n" << endl;

    cout << "Task4" << endl;

    cout << ">>> to_24_hour_clock(24)" << endl;
    cout << to_24_hour_clock(24) << "\n" << endl;
    assert(fabs(to_24_hour_clock(24), 0) < eps);

    cout << ">>> to_24_hour_clock(48)" << endl;
    cout << to_24_hour_clock(48) << "\n" << endl;
    assert(fabs(to_24_hour_clock(48), 0) < eps);

    cout << ">>> to_24_hour_clock(25)" << endl;
    cout << to_24_hour_clock(25) << "\n" << endl;
    assert(fabs(to_24_hour_clock(25), 1) < eps);

    cout << ">>> to_24_hour_clock(4)" << endl;
    cout << to_24_hour_clock(4) << "\n" << endl;
    assert(fabs(to_24_hour_clock(4), 4) < eps);

    cout << ">>> to_24_hour_clock(28.5)" << endl;
    cout << to_24_hour_clock(28.5) << "\n" << endl;
    assert(fabs(to_24_hour_clock(28.5), 4.5) < eps);

    cout << "\n Тесты пройдены!\n" << endl;

    cout << "Task5" << endl;

    cout << ">>> get_hours(3800)" << endl;
    cout << get_hours(3800) << "\n" << endl;
    assert(get_hours(3800) == 1);

    cout << ">>> get_minutes(3800)" << endl;
    cout << get_minutes(3800) << "\n" << endl;
    assert(get_minutes(3800) == 3);

    cout << ">>> get_seconds(3800)" << endl;
    cout << get_seconds(3800) << "\n" << endl;
    assert(get_seconds(3800) == 20);

    cout << "\n Тесты пройдены!\n" << endl;

    cout << "Task6" << endl;

    cout << "time_to_utc(+0, 12.0)" << endl;
    cout << time_to_utc(+0, 12.0) << "\n" << endl;
    assert(fabs(time_to_utc(+0, 12.0), 12.0)<eps);

    cout << "time_to_utc(+1, 12.0)" << endl;
    cout << time_to_utc(+1, 12.0) << "\n" << endl;
    assert(fabs(time_to_utc(+1, 12.0), 11.0) < eps);

    cout << "time_to_utc(-1, 12.0)" << endl;
    cout << time_to_utc(-1, 12.0) << "\n" << endl;
    assert(fabs(time_to_utc(-1, 12.0), 13.0) < eps);

    cout << "time_to_utc(-11, 18.0)" << endl;
    cout << time_to_utc(-11, 18.0) << "\n" << endl;
    assert(fabs(time_to_utc(-11, 18.0), 5.0) < eps);

    cout << "time_to_utc(-1, 0.0)" << endl;
    cout << time_to_utc(-1, 0.0) << "\n" << endl;
    assert(fabs(time_to_utc(-1, 0.0), 1.0) < eps);

    cout << "time_to_utc(-1, 23.0)" << endl;
    cout << time_to_utc(-1, 23.0) << "\n" << endl;
    assert(fabs(time_to_utc(-1, 23.0), 0.0) < eps);

    cout << "\n Тесты пройдены!\n" << endl;

    cout << "Task7" << endl;

    cout << "time_from_utc(+0, 12.0)" << endl;
    cout << time_from_utc(+0, 12.0) << "\n" << endl;
    assert(fabs(time_from_utc(+0, 12.0), 12.0) < eps);

    cout << "time_from_utc(+1, 12.0)" << endl;
    cout << time_from_utc(+1, 12.0) << "\n" << endl;
    assert(fabs(time_from_utc(+1, 12.0), 13.0) < eps);

    cout << "time_from_utc(+6, 6.0)" << endl;
    cout << time_from_utc(+6, 6.0) << "\n" << endl;
    assert(fabs(time_from_utc(+6, 6.0), 12.0) < eps);

    cout << "time_from_utc(-7, 6.0)" << endl;
    cout << time_from_utc(-7, 6.0) << "\n" << endl;
    assert(fabs(time_from_utc(-7, 6.0), 23.0) < eps);

    cout << "time_from_utc(-1, 12.0)" << endl;
    cout << time_from_utc(-1, 12.0) << "\n" << endl;
    assert(fabs(time_from_utc(-1, 12.0), 11.0) < eps);

    cout << "time_from_utc(-1, 0.0)" << endl;
    cout << time_from_utc(-1, 0.0) << "\n" << endl;
    assert(fabs(time_from_utc(-1, 0.0), 23.0) < eps);

    cout << "time_from_utc(-1, 23.0)" << endl;
    cout << time_from_utc(-1, 23.0) << "\n" << endl;
    assert(fabs(time_from_utc(-1, 23.0), 22.0) < eps);

    cout << "time_from_utc(+1, 23.0)" << endl;
    cout << time_from_utc(+1, 23.0) << "\n" << endl;
    assert(fabs(time_from_utc(+1, 23.0), 0.0) < eps);

    cout << "\n Тесты пройдены!\n" << endl;

    system("pause");
