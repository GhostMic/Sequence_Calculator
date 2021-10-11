#include "header.hpp"
#include "exponent.hpp"

bool Exponent::is_perfect_square(const double& n)
{
    int root = sqrt(n);
    if(pow(root,2) == n){
        expo.push_back(root);
        return true;
    }
    return false;
}

bool Exponent::is_perfect_cube(const double& n)
{
    int root = cbrt(n);
    if(pow(root,3) == n){
        expo.push_back(root);
        return true;
    }
    return false;
}

bool Exponent::is_seq_exponent(const vector<double>& seq)
{
    for(int i = 0; i<seq.size(); ++i){
        if(is_perfect_square(seq[i]) && seq[i] >= 0){
            perfect_square = true;
        } else {
            perfect_square = false;
            break;
        }
    }

    if(!perfect_square){
        for(int i = 0; i<seq.size(); ++i){
            if(is_perfect_cube(seq[i]) && seq[i] >= 0){
                perfect_cube = true;
            } else {
                perfect_cube = false;
                break;
            }
        }
    }

    bool diff_valid = check_expo(expo);
    if(perfect_square && diff_valid || perfect_cube && diff_valid){
        return true;
    }
    expo.clear();
    return false;
}

bool Exponent::check_expo(const vector<double>& expo)
{
    vector<double> diff;
    for(int i = 1; i<expo.size(); ++i){
        diff.push_back(expo[i]-expo[i-1]);
    }

    // debug
    /*cout << "expo:\n";
    for(int i = 0; i<expo.size(); ++i){
        cout << expo[i] << endl;
    }
    cout << "diff:\n";
    for(int i = 0; i<diff.size(); ++i){
        cout << diff[i] << endl;
    }*/

    bool check;
    for(int i = 0; i<diff.size(); ++i){
        if(diff[0] == diff[i]){
            check = true;
        } else {
            check = false;
            break;
        }
    }
    return check;
}

double Exponent::exponential(vector<double>& seq, const int& n)
{
    double d = expo[1]-expo[0];
    if(n > seq.size()){
        if(perfect_square){
            for(int i = seq.size()-1; i != n-1; ++i){
                seq.push_back(pow((expo[i]+d),2));
                expo.push_back(expo[i]+d);
            }
        } else {
            for(int i = seq.size()-1; i != n-1; ++i){
                seq.push_back(pow((expo[i]+d),3));
                expo.push_back(expo[i]+d);
            }
        }
    }
    expo.clear();
    return seq[n-1];
}

double Exponent::expo_sum(const vector<double>& seq, const int& n)
{
    double sum;
    for(int i = 0; i<seq.size(); ++i){
        sum += seq[i];
    }
    return sum;
}
