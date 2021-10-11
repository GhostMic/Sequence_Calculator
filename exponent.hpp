#ifndef MIC_EXPONENT
#define MIC_EXPONENT

class Exponent {
public:
    bool is_seq_exponent(const vector<double>&);
    bool is_perfect_square(const double&);
    bool is_perfect_cube(const double&);

    bool check_expo(const vector<double>&);
    double exponential(vector<double>&, const int&);
    double expo_sum(const vector<double>&, const int&);
private:
    vector<double> expo;
    bool perfect_square;
    bool perfect_cube;
};

#endif // EXPONENT_HPP_INCLUDED
