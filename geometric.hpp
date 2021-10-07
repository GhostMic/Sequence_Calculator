#ifndef MIC_SEQ_CAL_GEO_SEQ
#define MIC_SEQ_CAL_GEO_SEQ

#include "util.hpp"

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

#endif