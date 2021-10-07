#include "multi_stage.hpp"

vector<double> Multi_stage::check_diff(const vector<double>& diff)
{
    cout << "diff: " << endl;
    for(int i = 0; i<diff.size(); ++i){
        cout << diff[i] << endl;
    }

    vector<double> diff2;
    vector<double> rate2;

    for(int i = 1; i<diff.size(); ++i){
        diff2.push_back(diff[i]-diff[i-1]);
    }
    for(int i = 1; i<diff.size(); ++i){
        rate2.push_back(diff[i]/diff[i-1]);
    }

    cout << "diff2:\n";
    for(int i = 0; i<diff2.size(); ++i){
        cout << diff2[i] << endl;
    }

    cout << "rate2:\n";
    for(int i = 0; i<rate2.size(); ++i){
        cout << rate2[i] << endl;
    }

    for(int i = 0; i<diff2.size(); ++i){
        if(diff2[0] == diff2[i]){
            diff_arithmetic = true;
        } else {
            diff_arithmetic = false;
            break;
        }
    }
    if(diff_arithmetic){
        return diff2;
    }
    for(int i = 0; i<rate2.size(); ++i){
        if(rate2[0] == rate2[i]){
            diff_geometric = true;
        } else {
            diff_geometric = false;
            break;
        }
    }
    if(diff_geometric){
        return rate2;
    }

}

void Multi_stage::check_rate(const vector<double>& rate)
{
    cout << "rate:" << endl;
    for(int i = 0; i<rate.size(); ++i){
        cout << rate[i] << endl;
    }

    vector<double> diff2;
    vector<double> rate2;

    for(int i = 0; i<rate.size(); ++i){
        diff2.push_back(rate[i]-rate[i-1]);
    }
    for(int i = 1; i<rate.size(); ++i){
        rate2.push_back(rate[i]/rate[i-1]);
    }

    cout << "rate2: " << endl;
    for(int i = 0; i<rate2.size(); ++i){
        cout << rate2[i] << endl;
    }

    for(int i = 0; i<diff2.size(); ++i){
        if(diff2[0] == diff2[i]){
            rate_arithmetic = true;
        } else {
            rate_arithmetic = false;
            break;
        }
    }
    for(int i = 0; i<rate2.size(); ++i){
        if(rate2[0] == rate2[i]){
            rate_geometric = true;
        } else {
            rate_geometric = false;
            break;
        }
    }
}

void Multi_stage::add_diff(vector<double>& diff, const int& n)
{
    vector<double> vec2 = check_diff(diff);
    if(diff_geometric){
        for(int i = diff.size()-1; i != n-1; ++i){
            diff.push_back(vec2[0]*diff[i]);
        }
    }

}