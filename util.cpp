#include "util.hpp"

void cls()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

void cinError()
{
    cin.clear();
    cin.ignore(256, '\n');
}

bool is_fibonacci(const vector<double>& seq)
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

double fibonacci(vector<double>& seq, const int& n)
{
   // double fn;
    if(n > seq.size()){
        for(int i = seq.size()-1; i != n-1; ++i){
            seq.push_back(seq[i]+seq[i-1]);
        }
    }

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
    return seq[n-1];
}

double sum_of_fibo(const vector<double>& seq, const int& n, double& nth_num)
{
    double sum;
    for(int i = 0; i<seq.size(); ++i){
        sum += seq[i];
    }
    return sum;
}

void input_sequence(vector<double>& seq, double& input)
{
    char sep;
    cout << "Enter Sequence: ";
    while(true){
        cin >> input;
        if(cin.fail()){
            break;
        }
        cin.get(sep);
        seq.push_back(input);
    }
}