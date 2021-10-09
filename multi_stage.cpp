#include "header.hpp"
#include "multi_stage.hpp"

bool Multi_stage::is_multi_stage(const vector<double>& d, const vector<double>& r)
{
        diff_constant = is_constant(d);
        if(diff_constant){
            return true;
        }
        temp_diff.clear();

        diff_exponential = is_exponential(d);
        if(diff_exponential){
            return true;
        }
        temp_diff.clear();

        rate_constant = is_constant(r);
        if(rate_constant){
            return true;
        }
        temp_diff.clear();

        rate_exponential = is_exponential(r);
        if(rate_exponential){
            return true;
        }
        temp_diff.clear();

        return false;
}

bool Multi_stage::is_constant(const vector<double>& d)
{
    for(int i = 1; i<d.size(); ++i){
        temp_diff.push_back(d[i]-d[i-1]);
    }

    bool check;
    for(int i = 0; i<temp_diff.size(); ++i){
        if(temp_diff[0] == temp_diff[i]){
            check = true;
        } else {
            check = false;
            break;
        }
    }
    return check;
}

bool Multi_stage::is_exponential(const vector<double>& d)
{
    for(int i = 1; i<d.size(); ++i){
        temp_diff.push_back(d[i]/d[i-1]);
    }

    bool check;
    for(int i = 0; i<temp_diff.size(); ++i){
        if(temp_diff[0] == temp_diff[i]){
            check = true;
        } else {
            check = false;
            break;
        }
    }
    return check;
}

void Multi_stage::compile_diff(vector<double>& diff, const int& n)
{
    if(diff_constant && n > diff.size()){
        for(int i = diff.size()-1; i != n-2; ++i){
            diff.push_back(diff[i]+temp_diff[0]);
        }
    } else if(diff_exponential && n > diff.size()){
        for(int i = diff.size()-1; i != n-2; ++i){
            diff.push_back(diff[i]*temp_diff[0]);
        }
    }

    // debug
    /*cout << "temp_diff:\n";
    for(int i = 0; i<temp_diff.size(); ++i){
        cout << temp_diff[i] << endl;
    }
    cout << "diff:\n";
    for(int i = 0; i<diff.size(); ++i){
        cout << diff[i] << endl;
    }*/

    temp_diff.clear();
}

void Multi_stage::compile_rate(vector<double>& rate, const int& n)
{
    if(rate_constant && n > rate.size()){
        for(int i = rate.size()-1; i != n-2; ++i){
            rate.push_back(rate[i]+temp_diff[0]);
        }
    } else if(rate_exponential && n > rate.size()){
        for(int i = rate.size()-1; i != n-2; ++i){
            rate.push_back(rate[i]*temp_diff[0]);
        }
    }

    // debug
    /*cout << "temp_diff:\n";
    for(int i = 0; i<temp_diff.size(); ++i){
        cout << temp_diff[i] << endl;
    }
    cout << "rate:\n";
    for(int i = 0; i<rate.size(); ++i){
        cout << rate[i] << endl;
    }*/

    temp_diff.clear();
}

double Multi_stage::arithmetic(vector<double>& seq, vector<double>& diff, const int& n)
{
    if(n > seq.size()){
        for(int i = seq.size()-1; i != n-1; ++i){
            seq.push_back(seq[i]+diff[i]);
        }
    }
    diff.clear();
    return seq[n-1];
}

double Multi_stage::geometric(vector<double>& seq, vector<double>& rate, const int& n)
{
    if(n > seq.size()){
        for(int i = seq.size()-1; i != n-1; ++i){
            seq.push_back(seq[i]*rate[i]);
        }
    }
    rate.clear();
    return seq[n-1];
}

double Multi_stage::sum(const vector<double>& seq, const int& n)
{
    double sum;
    for(int i = 0; i < n; ++i){
        sum += seq[i];
    }
    return sum;
}

bool Multi_stage::get_diffconst() const
{
    return diff_constant;
}

bool Multi_stage::get_diffexpo() const
{
    return diff_exponential;
}

bool Multi_stage::get_rateconst() const
{
    return rate_constant;
}

bool Multi_stage::get_rateexpo() const
{
    return rate_exponential;
}

void Multi_stage::clear_temp()
{
    temp_diff.clear();
}
