#include "header.hpp"
#include "arithmetic.hpp"

bool Arithmetic::is_constant(const vector<double>& seq)
{
    for(int i = 1; i<seq.size(); ++i){
        diff.push_back(seq[i]-seq[i-1]);
    }

    // debug
    /*cout << "Arithmetic.diff: " << endl;
    for(int i = 0; i<diff.size(); ++i){
        cout << diff[i] << endl;
    }*/

    for(int i = 0; i<diff.size(); ++i){
        if(diff[0] == diff[i]){
            constant = true;
        } else {
            constant = false;
            break;
        }
    }

    return constant;
}

double Arithmetic::arithmetic(vector<double>& seq, const int& n)
{
    double a1 = seq[0];
    double d = seq[1]-seq[0];
    double ans = a1+((n-1)*d);

    if(n > seq.size()){
        for(int i = seq.size()-1; i != n-1; ++i){
            seq.push_back(seq[i]+d);
        }
    }

    return ans;
}

double Arithmetic::sum_of_arith(const vector<double>& seq, const int& n, const double& nth_num)
{
    double a1 = seq[0];
    double an = nth_num;
    double sum = n*((a1+an)/2);

    return sum;
}

bool Arithmetic::getBool()
{
    return constant;
}

void Arithmetic::clear_arith()
{
    diff.clear();
}
