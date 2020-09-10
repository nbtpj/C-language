#pragma once
#ifndef _MyString_h_
#define _MyString_h_
#include<iostream>
using namespace std;
class MyString {
    char* str;
    int len;
public:
    // Hàm khởi tạo xâu rỗng
    MyString();

    // Hàm khởi tạo từ một xâu kiểu c-string
    MyString(const char*);

    // Hàm khởi tạo sao chép từ một thực thể (instance) MyString khác
    MyString(const MyString&);

    // Hàm huỷ
    ~MyString();

    // Toán tử gán
    MyString operator=(const MyString&);
    MyString operator=(const char*);

    MyString operator+=(const char* a);

    // Toán tử nối xâu rồi gán
    MyString operator+=(const MyString&);

    // Toán tử truy cập đến từng kí tự
    char& operator[] (unsigned int index);
    const char& operator[] (unsigned int index) const;

    // Hàm trả về độ dài của xâu
    int size();

    // Hàm trả về 1 thực thể MyString có các kí tự giống thực thể đang xét nhưng các chữ cái viết hoa
    MyString upper() const;

    // Hàm trả về 1 thực thể MyString có các kí tự giống thực thể đang xét nhưng các chữ cái viết thường
    MyString lower() const;

    // Toán tử để in ra màn hình
    friend ostream& operator<< (ostream&, const MyString&);

    // Toán tử nối xâu
    friend MyString operator+ (const MyString&, const MyString&);

    // Các toán tử so sánh
    friend bool operator< (const MyString&, const MyString&);
    friend bool operator> (const MyString&, const MyString&);
    friend bool operator<=(const MyString&, const MyString&);
    friend bool operator>=(const MyString&, const MyString&);
    friend bool operator==(const MyString&, const MyString&);
    friend bool operator!=(const MyString&, const MyString&);
    friend ostream& operator<<(ostream&, const MyString&);

};
MyString::MyString(): str(NULL), len(0) {};
MyString::MyString(const char* a)
{
    len = 0;
    while (a[len] != '\0') len++;
    str = new char[len+1];
    int i = 0;
    while (a[i] != '\0')
    {
        str[i] = a[i];
        i++;
    };
    str[i] = '\0';
}
MyString::MyString(const MyString& A)
{
    len = A.len;
    str = new char[A.len + 1];
    for (int i = 0; i < len; i++)
    {
        str[i] = A.str[i];
    };
    str[len] = '\0';

}
MyString::~MyString()
{
    delete[] str;
}
MyString MyString::operator = (const MyString& A)
{
    str = new char[A.len + 1];
    for (int i = 0; i <= len; i++)
    {
        str[i] = A.str[i];
    }
    return *this;
}
MyString MyString::operator = (const char* a)
{
    len = 0;
    while (a[len] != '\0') len++;
    str = new char[len + 1];
    int i = 0;
    while (a[i] != '\0')
    {
        str[i] = a[i];
        i++;
    };
    str[i] = '\0';
    return *this;
}
MyString MyString::operator+= (const MyString& a)
{
    int i = 0;
    while (a[i] != '\0') i++;

    char* vz = new char[i + this->len];
    for (int j = 0; j < this->len; j++)
    {
        vz[j] = str[j];
    };
    for (int j = this->len; j < this->len + i; j++)
    {
        vz[j] = a[j - this->len];
    };
    str = vz;
    len += i;
    return *this;
}

char& MyString:: operator[](unsigned int index)
{
    return *(str+index);
};
const char& MyString:: operator[](unsigned int index) const
{
    return *(str+index);
}
int MyString::size()
{
    return len;
}
MyString MyString::upper()const

{
    char* x= new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            x[i] = str[i] + 'A' - 'a';
        }
        else
        {
            x[i] = str[i];
        }
    };
    x[len] = '\0';
    return MyString(x);
}
MyString MyString::lower() const
{
    char* x = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            x[i] = str[i] + 'a' - 'A';
        }
        else
        {
            x[i] = str[i];
        }
    };
    x[len] = '\0';
    return MyString(x);
}
MyString operator+(const MyString& a, const MyString& b)
{
  
    char* vz = new char[a.len + b.len + 1];
    for (int i = 0; i < a.len; i++) vz[i] = a[i];
    for (int i = a.len; i < a.len + b.len; i++) vz[i] = b[i - a.len];
    vz[a.len + b.len] = '\0';
    return MyString(vz);
    
}
bool operator<(const MyString& a, const MyString& b)
{
    int i = 0;
    while (a[i]== b[i]) i++;
    return (a[i] < b[i]);
}
bool operator>(const MyString& a, const MyString& b)
{
    int i = 0;
    while (a[i] == b[i]) i++;
    return (a[i] > b[i]);
}
bool operator== (const MyString& a, const MyString& b)
{
    int i = 0;
    while (a[i] == b[i]) 
    {
        i++; if (a[i]!=b[i]) return false;
    }
    return true;

}
bool operator >=(const MyString& a, const MyString& b)
{
    return (a > b || a == b);
}
bool operator <=(const MyString& a, const MyString& b)
{
    return(a < b || a == b);
}
bool operator !=(const MyString& a, const MyString& b)
{
    return !(a == b);
}

ostream& operator<<(ostream& os, const MyString& x)
{
    for (int i = 0; i < x.len; i++) os << x.str[i];
    return os;
}



#endif // !_MyString_h_


