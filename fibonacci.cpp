#include "header.hpp"
#include "fibonacci.hpp"

bool Fibonacci::is_fibonacci(const vector<double>& seq)
{
    bool check = false;
    for(int i = 2; i<seq.size(); ++i){
        if(seq[i] != seq[i-1]+seq[i-2]){
            return false;
        }
        check = true;
    }
    return check;
}

double Fibonacci::fibonacci(vector<double>& seq, const int& n)
{
    if(n > seq.size()){
        for(int i = seq.size()-1; i != n-1; ++i){
            seq.push_back(seq[i]+seq[i-1]);
        }
    }

    return seq[n-1];
}

double Fibonacci::sum_of_fibo(const vector<double>& seq, const int& n, double& nth_num)
{
    double sum;
    for(int i = 0; i<seq.size(); ++i){
        sum += seq[i];
    }
    return sum;
}
