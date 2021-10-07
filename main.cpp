#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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

class Type {
public:
    bool is_arith;
    bool is_geo;
    bool is_multi_stage;
    bool is_fibo;
};

class Arithmetic {
public:
    vector<double> diff;
    //vector<double> diff2;

    double arithmetic(vector<double>&, const int&);

    bool is_constant(const vector<double>&);

    double sum_of_arith(const vector<double>&, const int&, const double&);

    bool getBool()
    {
        return constant;
    }

    void clear_arith()
    {
        diff.clear();
        //diff2.clear();
    }

private:
    bool constant;
    bool Multi_stage_type;
};

class Geometric {
public:
    vector<double> rate;
    //vector<double> rate2;

    double geometric(vector<double>&, const int&);

    bool is_exponential(const vector<double>&);

    double sum_of_geo(const vector<double>&, const int&, double&);

    void clear_geo()
    {
        rate.clear();
        //rate2.clear();
    }

    bool getBool()
    {
        return constant;
    }

private:
    bool constant;
    bool Multi_stage_type;
};

class Multi_stage {
public:
    bool diff_arithmetic;
    bool diff_geometric;
    bool rate_arithmetic;
    bool rate_geometric;

    vector<double> check_diff(const vector<double>&);
    void check_rate(const vector<double>&);

    void add_diff(vector<double>&, const int&);
    void add_rate(vector<double>&);

    bool is_multi_stage(const vector<double>& d, const vector<double>& r)
    {
        check_diff(d);
        if(diff_arithmetic || diff_geometric){
            return true;
        }
        check_rate(r);
        if(rate_arithmetic || rate_geometric){
            return true;
        }
        return false;
    }
};

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

bool Geometric::is_exponential(const vector<double>& seq)
{
    for(int i = 1; i<seq.size(); ++i){
        rate.push_back(seq[i]/seq[i-1]);
    }

    for(int i = 0; i<rate.size(); ++i){
        if(rate[0] == rate[i]){
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

    for(int i = 1; i<rate.size(); ++i){
        rate2.push_back(rate[i]/rate[i-1]);
    }

    for(int i = 0; i<rate2.size(); ++i){
        if(rate2[0] == rate2[i]){
            Multi_stage_type = true;
        } else {
            Multi_stage_type = false;
            return false;
        }
    }
    return true;*/
}

double Geometric::geometric(vector<double>& seq, const int& n)
{
    double a1 = seq[0];
    double r = seq[1]/seq[0];
    double ans;   // an = a1*ar^n-1

    if(constant){
        ans = a1*pow(r,(n-1));
        if(n > seq.size()){
            for(int i = seq.size()-1; i != n-1; ++i){
                seq.push_back(seq[i]*r);
            }
        }
    } /*else {
        r = (seq[seq.size()-1] / seq[seq.size()-2]) * rate2[0];
        if(n > seq.size()){
            for(int i = seq.size()-1; i != n-1; ++i){
                seq.push_back(seq[i]*r);
                r *= rate2[0];
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

double Geometric::sum_of_geo(const vector<double>& seq, const int& n, double& nth_num)
{
    double a = seq[0];
    double r = seq[1]/seq[0];
    double sum = a*((1-pow(r,n))/(1-r));  // Sn = a(1-r^n/1-r)

    return sum;
}

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

int main()
{
    Type type;
    Arithmetic arithmetic;
    Geometric geometric;
    Multi_stage ms;

    vector<double> seq;
    double input;
    int n;

    cout << "[Example: 2,4,8,16...]\n";
    while(true){
        input_sequence(seq, input);

        type.is_arith = arithmetic.is_constant(seq);
        type.is_geo = geometric.is_exponential(seq);
        if(!type.is_arith && !type.is_geo){
            type.is_multi_stage = ms.is_multi_stage(arithmetic.diff, geometric.rate);
        }
        type.is_fibo = is_fibonacci(seq);

        cout << "is_arith: " << type.is_arith << endl;
        cout << "is_geo: " << type.is_geo << endl;
        cout << "is_multi_stage: " << type.is_multi_stage << endl;
        cout << "is_fibo: " << type.is_fibo << endl;

        cinError();

        if(type.is_arith && !type.is_geo){
            cout << "Sequence is arithmetic..." << endl;
        } else if(type.is_geo){
            cout << "Sequence is geometric..." << endl;
        } else if(type.is_multi_stage){
            cout << "Sequence is a two stage type..." << endl;
        } else if(type.is_fibo){
            cout << "Sequence is a fibonacci..." << endl;
        } else {
            cerr << "There is no pattern..." << endl;
            cout << "[Retry Input] \n\n";
            seq.clear();
            arithmetic.clear_arith();
            continue;
        }

        while(true){
            cout << "Find nth term: ";
            cin >> n;
            if(cin.fail() || n < 1){
                cerr << "[INVALID INPUT]"<< endl;
                cinError();
                continue;
            }
            break;
        }

        double nth_num;
        double sum;
        if(type.is_arith){
            nth_num = arithmetic.arithmetic(seq, n);
            sum = arithmetic.sum_of_arith(seq, n, nth_num);
            arithmetic.clear_arith();
        } else if(type.is_geo){
            nth_num = geometric.geometric(seq, n);
            sum = geometric.sum_of_geo(seq, n, nth_num);
        } else if(type.is_multi_stage){
            if(ms.diff_arithmetic){

            } else if(ms.diff_geometric){
                //nth_num =
            }
        } else if(type.is_fibo){
            nth_num = fibonacci(seq, n);
            sum = sum_of_fibo(seq, n, nth_num);
        } else {
            throw "error";
        }

        cout << "The " << n << "th term is: " << nth_num << endl;
        cout << "The sum of the sequence is: " << sum << endl;
        seq.clear();

        char ch;
        while(true){
            cout << "\nRetry? ['y' for yes, 'n' for no, 'c' to clear screen]\n";
            cout << "Choice: ";
            cin >> ch;
            if(ch == 'y'){
                cout << endl;
                break;
            } else if(ch == 'n'){
                break;
            } else if(ch == 'c'){
                cls();
                break;
            } else {
                cerr << "[BAD INPUT]" << endl;
                cinError();
            }
        }
        if(ch == 'n'){ break; }
    }

    return 0;
}
