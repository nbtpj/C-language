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
}/*
if (num1 < 10) or (num2 < 10)
    return num1 × num2

    /* Calculates the size of the numbers. *
    m = min(size_base10(num1), size_base10(num2))
    m2 = floor(m / 2)
    /* m2 = ceil(m / 2) will also work *

    /* Split the digit sequences in the middle. *
    high1, low1 = split_at(num1, m2)
    high2, low2 = split_at(num2, m2)

    /* 3 calls made to numbers approximately half the size. *
    z0 = karatsuba(low1, low2)
    z1 = karatsuba((low1 + high1), (low2 + high2))
    z2 = karatsuba(high1, high2)

    return (z2 × 10 ^ (m2 × 2)) + ((z1 - z2 - z0) × 10 ^ m2) + z0*/