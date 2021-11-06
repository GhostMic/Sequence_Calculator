#ifndef MIC_ARITH
#define MIC_ARITH
#include "header.hpp"

class Arithmetic {
public:
    vector<double> diff;

    double arithmetic(vector<double>&, const int&);

    bool is_constant(const vector<double>&);

    double sum_of_arith(const vector<double>&, const int&, const double&);

    bool getBool();

    void clear_arith();

private:
    bool constant;
};

#endif // MIC_ARITH
