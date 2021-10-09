#ifndef MIC_SEQ_CAL
#define MIC_SEQ_CAL

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void cls();

void cinError();

class Type {
public:
    bool is_arith;
    bool is_geo;
    bool is_multi_stage;
    bool is_fibo;
};

bool is_fibonacci(const vector<double>& seq);

double fibonacci(vector<double>& seq, const int& n);

double sum_of_fibo(const vector<double>& seq, const int& n, double& nth_num);

void input_sequence(vector<double>& seq, double& input);

#endif