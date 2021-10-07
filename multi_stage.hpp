#ifndef MIC_SEQ_CAL_MULT_STAGE
#define MIC_SEQ_CAL_MULT_STAGE

#include "util.hpp"

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

#endif