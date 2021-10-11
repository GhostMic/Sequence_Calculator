#include "header.hpp"
#include "arithmetic.hpp"
#include "geometric.hpp"
#include "exponent.hpp"
#include "multi_stage.hpp"
#include "fibonacci.hpp"
#include "utility.hpp"

class Type {
public:
    bool is_arith;
    bool is_geo;
    bool is_exponent;
    bool is_multi_stage;
    bool is_fibo;
};

void print_seq(const vector<double>& seq)
{
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
}

void retry(char& ch)
{
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
}

void find_nth(int& n)
{
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
}

void input_sequence(vector<double>& seq, double& input)
{
    while(true){
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
        if(seq.size() <= 1){
            cerr << "[A SEQUENCE NEEDS ATLEAST 2 TERMS]\n";
            seq.clear();
            cinError();
            cout << "Press enter to continue...";
            cin.get();
            cls();
            continue;
        } else {
            break;
        }
    }
}

int main()
{
    Type type;
    Arithmetic arithmetic;
    Geometric geometric;
    Exponent exponent;
    Multi_stage ms;
    Fibonacci fb;

    vector<double> seq;
    double input;
    int n;

    cout << "[Example: 2,4,8,16...]\n";
    while(true){
        input_sequence(seq, input);

        type.is_arith = arithmetic.is_constant(seq);
        type.is_geo = geometric.is_exponential(seq);
        type.is_exponent = exponent.is_seq_exponent(seq);
        if(!type.is_arith && !type.is_geo && !type.is_exponent){
            type.is_multi_stage = ms.is_multi_stage(arithmetic.diff, geometric.rate);
        }
        type.is_fibo = fb.is_fibonacci(seq);

        // debug
        /*cout << "is_arith: " << type.is_arith << endl;
        cout << "is_geo: " << type.is_geo << endl;
        cout << "is_multi_stage: " << type.is_multi_stage << endl;
        cout << "is_fibo: " << type.is_fibo << endl;*/

        cinError();

        if(type.is_arith){
            cout << "Sequence is arithmetic..." << endl;
        } else if(type.is_geo){
            cout << "Sequence is geometric..." << endl;
        } else if(type.is_exponent){
            cout << "Sequence is exponential..." << endl;
        } else if(type.is_multi_stage){
            cout << "Sequence is a two stage type..." << endl;
        } else if(type.is_fibo){
            cout << "Sequence is a fibonacci..." << endl;
        } else {
            cerr << "Unknown pattern..." << endl;
            cout << "[Retry Input] \n\n";
            seq.clear();
            arithmetic.clear_arith();
            geometric.clear_geo();
            continue;
        }

        find_nth(n);

        double nth_num;
        double sum;
        if(type.is_arith){
            nth_num = arithmetic.arithmetic(seq, n);
            sum = arithmetic.sum_of_arith(seq, n, nth_num);
            print_seq(seq);
        } else if(type.is_geo){
            nth_num = geometric.geometric(seq, n);
            sum = geometric.sum_of_geo(seq, n, nth_num);
            print_seq(seq);
        } else if(type.is_exponent){
            nth_num = exponent.exponential(seq, n);
            sum = exponent.expo_sum(seq, n);
            print_seq(seq);
        } else if(type.is_multi_stage){
            if(ms.get_diffconst() || ms.get_diffexpo()){
                ms.compile_diff(arithmetic.diff, n);
                nth_num = ms.arithmetic(seq, arithmetic.diff, n);
                sum = ms.sum(seq, n);
                print_seq(seq);
            } else if(ms.get_rateconst() || ms.get_rateexpo()){
                ms.compile_rate(geometric.rate, n);
                nth_num = ms.geometric(seq, geometric.rate, n);
                sum = ms.sum(seq, n);
                print_seq(seq);
            }
        } else if(type.is_fibo){
            nth_num = fb.fibonacci(seq, n);
            sum = fb.sum_of_fibo(seq, n, nth_num);
            print_seq(seq);
        } else {
            throw "error";
        }

        cout << "The " << n << "th term is: " << nth_num << endl;
        cout << "The sum of the sequence is: " << sum << endl;
        seq.clear();
        arithmetic.clear_arith();
        geometric.clear_geo();

        char ch;
        retry(ch);

        if(ch == 'n'){ break; }
    }

    return 0;
}
