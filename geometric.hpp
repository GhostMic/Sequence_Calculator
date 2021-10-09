#ifndef MIC_GEOMETRIC
#define MIC_GEOMETRIC

class Geometric {
public:
    vector<double> rate;
    //vector<double> rate2;

    double geometric(vector<double>&, const int&);

    bool is_exponential(const vector<double>&);

    double sum_of_geo(const vector<double>&, const int&, double&);

    void clear_geo();

    bool getBool();

private:
    bool constant;
};

#endif // MIC_GEOMETRIC
