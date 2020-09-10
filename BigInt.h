#pragma once
#ifndef _BIGINT_H_
#define _BIGINT_H_


#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
//compare two string  these are possitive
int Compare(const string& a, const string& b)
{
	if (a == b) return 0;
	int i = 0;
	while (a[i] == b[i]) i++;
	if (a.length() > b.length() || (a.length() == b.length() && a[i] > b[i])) return 1;
	return -1;
}
// both a and b are possitive, find the sum of a and b
string Plus(const string& a, const string& b)
{
	string result; long long int re = 0, sum;
	long long int x = a.length() - 1, y = b.length() - 1;
	long long int i = x > y ? x : y;
	for (; i >= 0; i--)
	{
		long long int fa = 0, fb = 0;
		if (x >= 0) fa = a[x] - 48;
		if (y >= 0) fb = b[y] - 48;
		sum = re + fa + fb; x--; y--;
		result = to_string(sum % 10) + result;
		re = sum / 10;
	};
	if (re != 0) result = to_string(re) + result;
	while (result[0] == '0' && result.length() > 1) result.erase(result.begin());
	return result;
};
// both a and b are possitive and a is greater than b, find the subtraction of a by b
string Minus(const string& a, const string& b)
{
	string result;
	int v_b = b.length();
	int remember = 0, sub;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		v_b--; char B = '0';
		if (v_b >= 0) B = b[v_b];
		sub = a[i] - B + remember;
		if (sub < 0)
		{
			result = to_string(sub + 10) + result;
			remember = -1;
		}
		else
		{
			result = to_string(sub) + result;
			remember = 0;
		};
	}
	while (result[0] == '0' && result.length() > 1) result.erase(result.begin());
	return result;

}
//Find a b times, both of them are possitive
string Time(const string& a, const string& b)
{
	string result("0"),temp;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		temp = "0";
		for (int j = 0; j < a[i] - '0'; j++)
		{
			temp = Plus(temp, b);
		}
		for (int j = 0; j < a.length() - 1 - i; j++) temp = temp + '0';
		result = Plus(result, temp);
	}
	return result;
}
class BigInt
{
private:
	//the value of BigInt
	string value;
	//the sign of BigInt =0 if negative or 1 if possitve
	int sign;
public:
	
	BigInt(const char* A = "0")
	{
		if (A[0] == '-')
		{
			sign = 0;
			string x = A;
			x.erase(x.begin()); if (A[0] == '-')
			{
				sign = 0;
				string x = A;
				x.erase(x.begin());
				while (x.length() > 1 && x[0] == '0') x.erase(x.begin());
				value = x;
			}
			else
			{
				sign = 1;
				string x = A;
				while (x.length() > 1 && x[0] == '0') x.erase(x.begin());
				value = x;
			};
			while (x.length() > 1 && x[0] == '0') x.erase(x.begin());
			value = x;
		}
		else
		{
			sign = 1;
			string x = A;
			while (x.length() > 1 && x[0] == '0') x.erase(x.begin());
			value = x;
		};
	}
	BigInt(string A, int i = 1) : value(A), sign(i) {};
	BigInt(const int& i)
	{
		string A = to_string(i);
		if (A[0] == '-')
		{
			sign = 0;
			string x = A;
			x.erase(x.begin());
			while (x.length() > 1 && x[0] == '0') x.erase(x.begin());
			value = x;
		}
		else
		{
			sign = 1;
			string x = A;
			while (x.length() > 1 && x[0] == '0') x.erase(x.begin());
			value = x;
		};

	}
	BigInt(const BigInt& X)
	{
		sign = X.sign;
		value = X.value;
	}
	BigInt& operator=(const int x)
	{
		*this = BigInt(x);
		return *this;
	}
	BigInt& operator=(const char* x)
	{
		*this = BigInt(x);
		return *this;
	}
	BigInt& operator=(const BigInt& x)
	{

		value = x.value;
		sign = x.sign;
		return *this;
	};
	friend bool operator>(const BigInt& a, const BigInt& b)
	{
		if (a.value == "0" && b.value == "0") return false;
		if (a.sign == 1 && b.sign == 1)
		{
			return (Compare(a.value, b.value) == 1);
		}
		else
		{
			if (a.sign == 0 && b.sign == 0)
			{
				return (Compare(a.value, b.value) == -1);
			}
			else
			{
				if (a.sign == 0 && b.sign == 1)
				{
					return false;
				}
				else
					return true;
			}
		}

	}
	friend bool operator==(const BigInt& a, const BigInt& b)
	{
		if (a.value == "0" && b.value == "0") return true;
		return(a.sign == b.sign && a.value == b.value);
	}
	friend bool operator<(const BigInt& a, const BigInt& b)
	{
		return !(a == b || a > b);
	}

	friend BigInt operator+(const BigInt& a, const BigInt& b)
	{

		if (a.sign == b.sign)
		{
			return BigInt(Plus(a.value, b.value), a.sign);
		}
		else
		{
			if (Compare(a.value, b.value) == 1)
			{
				return BigInt(Minus(a.value, b.value), a.sign);
			}
			else
			{
				return BigInt(Minus(b.value, a.value), b.sign);
			}
		}
	};
	friend BigInt operator+(const BigInt& a, const int& x)
	{
		BigInt b(x);
		return a + b;

	};
	friend BigInt operator+(const int& x, const BigInt& b)
	{
		BigInt a(x);
		return a + b;
	};


	friend BigInt operator-(const BigInt& a, const BigInt& b)
	{

		if (a.sign != b.sign)
		{

			return BigInt(Plus(a.value, b.value), a.sign);
		}
		else
		{
			if (Compare(a.value, b.value) == 1)
			{
				return BigInt(Minus(a.value, b.value), a.sign);
			}
			else
			{
				if (a.sign == 0)
				{
					return BigInt(Minus(b.value, a.value), 1);
				}
				else
				{
					return BigInt(Minus(b.value, a.value), 0);
				}

			}
		}
	};
	friend BigInt operator-(const BigInt& a, const int& x)
	{
		BigInt b(x);
		return a - b;

	};
	//product of a and b
	friend BigInt operator-(const int& x, const BigInt& b)
	{
		BigInt a(x);
		return a - b;
	};
	friend BigInt operator*(const BigInt& a, const BigInt& b)
	{
		if (a.sign == b.sign)
		{
			return BigInt(Time(a.value, b.value), 1);
		}
		return BigInt(Time(a.value, b.value), 0);
	};
	friend BigInt operator*(const BigInt& a, const int& x)
	{
		return a * BigInt(x);
	};
	friend BigInt operator*(const int& x, const BigInt& b)
	{
		return BigInt(x) * b;
	}
	//a and b are positive, a mod b
	friend BigInt operator%( BigInt a,  BigInt b)
	{
		if (a < b) return b;

		while (a.value.length() - 1 > b.value.length())
		{
			BigInt x(b);
			for (int i = 0; i < a.value.length() - b.value.length() - 1; i++) x.value += '0';
			a = a - x;
		}
		while (a > b || a == b)
		{
			a = a - b;
		};
		return a;

	}

	BigInt& operator+=(const BigInt& a)
	{
		*this = *this + a;
		return*this;
	};
	BigInt& operator+=(const int& a)
	{
		*this = *this + a;
		return*this;
	};
	BigInt& operator-=(const BigInt& a)
	{
		*this = *this - a;
		return*this;
	};
	BigInt& operator-=(const int& a)
	{
		*this = *this - a;
		return*this;
	};


	friend istream& operator >>(istream& is, BigInt& X)
	{
		string x;
		is >> x;
		X = BigInt(x.c_str());
		return is;
	}
	friend ostream& operator <<(ostream& os, const BigInt& X)
	{
		if (X.sign == 0) os << '-';
		os << X.value;
		return os;
	}
	int length()
	{
		return value.length();
	}
	BigInt split(int pos_begin = 0, int pos_end =0)
	{
			return BigInt(string(value.begin() + pos_begin, value.begin() + pos_end));
	}
};
#endif // !_BIGINT_H_