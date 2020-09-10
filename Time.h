#pragma once
#ifndef _Time_h_
#define _Time_h_
#include<iostream>
#include<iomanip>
using namespace std;
class Time
{
private:
	int h, m, s;
public:
	Time(int h_ = 0, int m_ = 0, int s_ = 0)
	{
		s = s_ % 60;
		m_ += s_ / 60;
		m = m_ % 60;
		h_ += m_ / 60;
		h = h_;
	};
	friend ostream& operator<<(ostream& os, const Time& X)
	{
		os << setfill('0') << setw(2) << X.h;
		os << ':';
		os << setfill('0') << setw(2) << X.m;
		os << ':';
		os << setfill('0') << setw(2) << X.s;
	}
	bool operator>(const Time& X)const
	{
		if (h != X.h)
		{
			return (h > X.h);
		}
		else
		{
			if (m != X.m)
			{
				return (m > X.m);
			}
			else
			{
				return (s > X.s);
			}
		}
	}bool operator<(const Time& X)const
	{
		if (h != X.h)
		{
			return (h < X.h);
		}
		else
		{
			if (m != X.m)
			{
				return (m < X.m);
			}
			else
			{
				return (s < X.s);
			}
		}
	}
	bool operator==(const Time& X) const
	{
		return (h == X.h && m == X.m && s == X.s);
	}
	bool operator>=(const Time& X) const
	{
		return (*this > X || *this == X);
	}
	bool operator<=(const Time& X) const
	{
		return (*this < X || *this == X);
	}
	bool operator!=(const Time& X) const
	{
		return !(*this == X);
	}
	int hour()
	{
		return h;
	}
	int minute()
	{
		return m;
	}
	int second()
	{
		return s;
	}

};
#endif // !_Time_h_
