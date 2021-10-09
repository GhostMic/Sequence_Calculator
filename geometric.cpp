#include "header.hpp"
#include "geometric.hpp"

bool Geometric::is_exponential(const vector<double>& seq)
{
    for(int i = 1; i<seq.size(); ++i){
        rate.push_back(seq[i]/seq[i-1]);
    }

    // debug
    /*cout << "Geometric.rate: " << endl;
    for(int i = 0; i<rate.size(); ++i){
        cout << rate[i] << endl;
    }*/

    for(int i = 0; i<rate.size(); ++i){
        if(rate[0] == rate[i]){
            constant = true;
        } else {
            constant = false;
            break;
        }
    }
    return constant;
}

double Geometric::geometric(vector<double>& seq, const int& n)
{
    double a1 = seq[0];
    double r = seq[1]/seq[0];
    double ans = a1*pow(r,(n-1));   // an = a1*ar^n-1

    if(n > seq.size()){
        for(int i = seq.size()-1; i != n-1; ++i){
            seq.push_back(seq[i]*r);
        }
    }

    return ans;
}

double Geometric::sum_of_geo(const vector<double>& seq, const int& n, double& nth_num)
{
    double a = seq[0];
    double r = seq[1]/seq[0];
    double sum = a*((1-pow(r,n))/(1-r));  // Sn = a(1-r^n/1-r)

    return sum;
}

void Geometric::clear_geo()
{
    rate.clear();
}

bool Geometric::getBool()
{
    return constant;
}
