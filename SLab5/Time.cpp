#include "Time.h"

static int convSec(const Time& t)
{
	return t.get_hours() * 3600 + t.get_minutes() * 60 + t.get_seconds();
}

Time::Time(void) :Triad()
{

}

Time::~Time(void)
{

}

Time::Time(int H, int M, int S) :Triad(H, M, S)
{

}

Time::Time(const Time& t) :Triad(t)
{

}

int Time::get_hours() const { return get_first(); }
int Time::get_minutes() const { return get_second(); }
int Time::get_seconds() const { return get_third(); }

void Time::set_hours(int h) { set_first(h); }
void Time::set_minutes(int m) { set_second(m); }
void Time::set_seconds(int s) { set_third(s); }

bool Time::operator==(const Time& t) const
{
	return convSec(*this) == convSec(t);
}
bool Time::operator!=(const Time& t) const
{
	return convSec(*this) != convSec(t);
}
bool Time::operator<(const Time& t) const
{
	return convSec(*this) < convSec(t);
}
bool Time::operator<=(const Time& t) const
{
	return convSec(*this) <= convSec(t);
}
bool Time::operator>(const Time& t) const
{
	return convSec(*this) > convSec(t);
}
bool Time::operator>=(const Time& t) const
{
	return convSec(*this) >= convSec(t);
}

Time& Time::operator=(const Time& t)
{
	if (&t == this) return *this;
	Triad::operator=(t);
	return *this;
}

istream& operator>>(istream& in, Time& t)
{
	int h, m, s;
	cout << "Enter hours: "; in >> h;
	cout << "Enter minutes: "; in >> m;
	cout << "Enter seconds: "; in >> s;
	t.set_hours(h);
	t.set_minutes(m);
	t.set_seconds(s);
	return in;
}
ostream& operator<<(ostream& out, const Time& t)
{
	out << "\nHours: " << t.get_hours();
	out << "\nMinutes: " << t.get_minutes();
	out << "\nSeconds: " << t.get_seconds();
	return out;
}

void Time::Show()
{
	cout << "\nHours: " << get_hours();
	cout << "\nMinutes: " << get_minutes();
	cout << "\nSeconds: " << get_seconds() << "\n";
}