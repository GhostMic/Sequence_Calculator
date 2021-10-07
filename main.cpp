#include "arithmetic.hpp"
#include "geometric.hpp"
#include "multi_stage.hpp"

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
