#pragma once
#ifndef _Point_h_
#define _Point_h_


#include<math.h>
#include<iostream>
using namespace std;
struct Point {
    double x, y; 
    Point(); 
    Point(double, double); 
    Point(const Point&); 
};
Point::Point() :x(0), y(0) {};
Point::Point(double x_, double y_) :x(x_), y(y_) {};
Point::Point(const Point& X) :x(X.x), y(X.y) {};

double length(const Point& a, const Point& b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

class Triangle {
    Point p1, p2, p3;
public:
    Triangle(Point, Point, Point); 
    double getPerimeter() const;  
    double getArea() const; 
};
Triangle::Triangle(Point a, Point b, Point c) : p1(a), p2(b), p3(c) {};
double Triangle::getArea() const
{
    double p = (length(p1, p2) + length(p1, p3) + length(p3, p2)) / 2;
    return sqrt(p * (p - length(p1, p2)) * (p - length(p3, p2)) * (p - length(p1, p3)));
};
double Triangle::getPerimeter() const
{
    return length(p1, p2) + length(p1, p3) + length(p3, p2);
}
#endif // !_Point_h_