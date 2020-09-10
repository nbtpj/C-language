#pragma once
#include "BigInt.h"
#include<algorithm>

BigInt pow_10(int m = 0)
{
    BigInt result(1);
    for (int i = 0; i < m; i++) result = result* 10;
    return result;

}

BigInt karatsuba(BigInt num1,BigInt num2)
{
    if (num1.length() < 3 || num2.length() < 3) {
        return(num1 * num2);
    }
    else {
        int m = min(num1.length(), num2.length());
        m /= 2;
        BigInt x1{ num1.split(0,m) }, x2{ num1.split(m,num1.length()) };
        BigInt y1{ num1.split(0,m) }, y2{ num1.split(m,num1.length()) };
        BigInt t0 = karatsuba(x2, y2), t1 = karatsuba((x1 + x2), (y1 + y2)), t2 = karatsuba(x1, y1);
        return (t2 * pow_10(m * 2) + (t1 - t2 - t0) * pow_10(m) + t0);

    }
}
