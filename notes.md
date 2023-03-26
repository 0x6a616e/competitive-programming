---
geometry: margin=2.54cm
output: pdf_document
---

# Competitive Programming Notes

## Template for C++

Code template for any program in C++.

~~~C++
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
~~~

Main advantage of this template is that the ***include*** used here brings the whole C++ standard library. Because I always use ***cin*** and ***cout***, this helps to optimize the IO operations, specially helpful when the problem involves a lot o reading/printing. Also worth noting that ***'\\n'*** is faster than ***endl***.

## Compilation command for C++

Is encouraged to use this command to compile C++ programs.

~~~bash
g++ -std=c++11 -O2 -Wall test.cpp
~~~

This command uses the standard for C++11, optimizes the code (O2) and shows warnings of possible errors.

## Working with files

If the contest requires you to read/write from/to a file, you can use the following commands at the beginning of your code.

~~~C++
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
~~~

With this instructions there is no need to further modify the code.

## Some data types and their ranges

| Data Type              | Size (in bytes) | Range                           |
|:----------------------:|:---------------:|:-------------------------------:|
| short int              | 2               | -32,768 to 32,767               |
| unsigned short int     | 2               | 0 to 65,535                     |
| unsigned int           | 4               | 0 to 4,294,967,295              |
| int                    | 4               | -2,147,483,648 to 2,147,483,647 |
| long long int          | 8               | -(2^63) to (2^63) - 1           |
| unsigned long long int | 8               | 0 to 18,446,744,073,709,551,615 |
| float                  | 4               | -3.4 × 10^38 to 3.4 × 10^38     |
| double                 | 8               | -1.7 × 10^308 to 1.7 × 10^308   |
| long double            | 12              | -1.1 × 10^4932 to 1.1 × 10^4932 |

Something about ***long long*** that we have to take into account is its prefix.

~~~C++
long long x = 123456789123456789LL;
~~~

Something similar to ***integer division*** happens when multiplying two ints into a long long, where even when the variable is long long, because they are ints the result is also an int.

## Big numbers and modulo

Sometimes the problem can get an answer bigger than what the data types can manage, so the statement usually asks for the answer to be given as the modulo of another number, there is an interesting property of the modulo when working with addition, substraction and multiplication.

$$ ( a + b ) \bmod m = ( a \bmod m + b \bmod m ) \bmod m $$

$$ ( a - b ) \bmod m = ( a \bmod m - b \bmod m ) \bmod m $$

$$ ( a * b ) \bmod m = ( a \bmod m * b \bmod m ) \bmod m $$

This property is that we can get the modulo after every operation so the number never becomes too big. Also, if there are substractions in the code, a way to avoid having a negative remainder is adding ***m*** if the remainder is under 0

## Floating point numbers

Most of the time using ***double*** will suffice the needs of the problem, if that is not the case we can use ***long double***. Something important about floating points is that sometimes can be risky to compare them with the ***==*** operator, so in cases like this we can assume that two numbers are equal if the difference between them is less than a small number, it can look like this.

~~~C+++
if (abs(a - b) < 1e-9) {
    // a and b are equal
}
~~~

## Math

### Simple progression

Useful formulas for the sum of consecutive numbers, there is a general approach but is way too complex for me so I hope is enough with this three.

$$ 1 + 2 + 3 + \dots + n = \frac{n(n + 1)}{2} $$

$$ 1^2 + 2^2 + 3^2 + \dots + n^2 = \frac{n(n + 1)(2n + 1)}{6} $$

$$ 1^3 + 2^3 + 3^3 + \dots + n^3 = \left[\frac{n(n + 1)}{2}\right]^2 $$

### Arithmetic progression

Another one is a ***arithmetic progression***, which is a sequence where the difference between the numbers stays the same, like this.

$$ 3, 7, 11, 15 $$

In this progression each number increases by 4 units, in this cases there is this formula.

$$ a + \dots + b = \frac{n(a + b)}{2} $$

In this formula ***a*** is the first number, ***b*** is the last number and ***n*** is the amount of numbers.

### Geometric progression

This progression is a sequence of numbers where the ratio between any two consecutive numbers is the same. It can be expressed as follows.

$$ a + ak + ak^2 + \dots + b = \frac{bk - a}{k - 1} $$

### Truth table

| A | B | not A | not B | A and B | A or B | A implies B | A equals B |
|:-:|:-:|:-----:|:-----:|:-------:|:------:|:-----------:|:----------:|
| 0 | 0 | 1     | 1     | 0       | 0      | 1           | 1          |
| 0 | 1 | 1     | 0     | 0       | 1      | 1           | 0          |
| 1 | 0 | 0     | 1     | 0       | 1      | 0           | 0          |
| 1 | 1 | 0     | 0     | 1       | 1      | 1           | 1          |

### Factorial

It can be defined as.

$$ \prod_{x=1}^{n} x = 1 * 2 * 3 * \dots * n $$

Or recursiveky as.

$$ 0! = 1 $$

$$ n! = n * (n - 1)! $$

### Fibonacci numbers

This one can be defined recursively as.

$$ f(0) = 0 $$

$$ f(1) = 1 $$

$$ f(n) = f(n - 1) + f(n - 2) $$

There is closed-form formula for calculating Fibonacci numbers.

$$ f(n) = \frac{(1 + \sqrt{5})^n - (1 - \sqrt{5})^n}{2^n\sqrt{5}} $$

### Logarithms

A logarithm says.

$$ log_k(x) = a \implies k^a = x $$

$$ log_k(ab) = log_k(a) + log_k(b) $$

$$ log_k(x^n) = n * log_k(x) $$

$$ log_k(\frac{a}{b}) = log_k(a) - log_k(b) $$
