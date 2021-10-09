#ifndef MIC_MULTI_STAGE
#define MIC_MULTI_STAGE

class Multi_stage {
public:
    Multi_stage()
    : diff_constant(false), diff_exponential(false), rate_constant(false),
        rate_exponential(false), temp_diff() {}

    bool is_multi_stage(const vector<double>&, const vector<double>&);
    bool is_constant(const vector<double>&);
    bool is_exponential(const vector<double>&);

    void compile_diff(vector<double>&, const int&);
    void compile_rate(vector<double>&, const int&);

    double arithmetic(vector<double>&, vector<double>&, const int&);
    double geometric(vector<double>&, vector<double>&, const int&);
    double sum(const vector<double>&, const int&);

    bool get_diffconst() const;
    bool get_diffexpo() const;
    bool get_rateconst() const;
    bool get_rateexpo() const;

    void clear_temp();
private:
    bool diff_constant;
    bool diff_exponential;
    bool rate_constant;
    bool rate_exponential;
    vector<double> temp_diff;
};

#endif // MIC_MULTI_STAGE
