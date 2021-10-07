#ifndef MIC_SEQ_CAL_ARITH_SEQ
#define MIC_SEQ_CAL_ARITH_SEQ

#include "util.hpp"

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

#endif