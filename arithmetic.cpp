#include "arithmetic.hpp"

bool Arithmetic::is_constant(const vector<double>& seq)
{
    for(int i = 1; i<seq.size(); ++i){
        diff.push_back(seq[i]-seq[i-1]);
    }

    /*cout << "check arith: \n";
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

    /*if(constant){
        return constant;
    }

    for(int i = 1; i<diff.size(); ++i){
        diff2.push_back(diff[i]-diff[i-1]);
    }

    for(int i = 0; i<diff2.size(); ++i){
        if(diff2[0] == diff2[i]){
            Multi_stage_type = true;
        } else {
            Multi_stage_type = false;
            return false;
        }
    }
    return true;*/
}

double Arithmetic::arithmetic(vector<double>& seq, const int& n)
{
    double a1 = seq[0];
    double d = seq[1]-seq[0];
    double ans;

    if(constant){
        ans = a1+((n-1)*d); // an = a1 + (n-1)d
        if(n > seq.size()){
            for(int i = seq.size()-1; i != n-1; ++i){
                seq.push_back(seq[i]+d);
            }
        }
    } /*else {
        d = (seq[seq.size()-1] - seq[seq.size()-2]) + diff2[0];
        if(n > seq.size()){
            for(int i = seq.size()-1; i != n-1; ++i){
                seq.push_back(seq[i]+d);
                d += diff2[0];
            }
        }
        ans = seq[n-1];
    }*/

    for(int i = 0; i<seq.size(); ++i){
        switch(i+1){
        case 1:
            cout << i+1 << "st" << "\t" << seq[i] << endl;
            break;
        case 2:
            cout << i+1 << "nd" << "\t" << seq[i] << endl;
            break;
        case 3:
            cout << i+1 << "rd" << "\t" << seq[i] << endl;
            break;
        default:
            cout << i+1 << "th" << "\t" << seq[i] << endl;
            break;
        }
    }
    cout << endl;

    return ans;
}

double Arithmetic::sum_of_arith(const vector<double>& seq, const int& n, const double& nth_num)
{
    double a1 = seq[0];
    double an = nth_num;
    double sum = n*((a1+an)/2);
    if(Multi_stage_type){
        sum = 0;
        for(int i = 0; i<seq.size(); ++i){
            sum += seq[i];
        }
    }

    return sum;
}