#pragma once
#include "Triad.h"
class Time :
    public Triad
{
public:
    Time(void);
public:
    ~Time(void);
    void Show();
    Time(int, int, int);
    Time(const Time&);
    int get_hours() const;
    int get_minutes() const;
    int get_seconds() const;
    void set_hours(int h);
    void set_minutes(int m);
    void set_seconds(int s);
    bool operator==(const Time& t) const;
    bool operator!=(const Time& t) const;
    bool operator<(const Time& t) const;
    bool operator<=(const Time& t) const;
    bool operator>(const Time& t) const;
    bool operator>=(const Time& t) const;
    Time& operator=(const Time&);
    friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, const Time& t);
};
