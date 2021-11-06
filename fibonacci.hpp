#ifndef FIBONACCI_HPP_INCLUDED
#define FIBONACCI_HPP_INCLUDED
#include "header.hpp"

class Fibonacci {
public:
    bool is_fibonacci(const vector<double>&);

    double fibonacci(vector<double>&, const int&);

    double sum_of_fibo(const vector<double>&, const int&, double&);
};

#endif // FIBONACCI_HPP_INCLUDED
