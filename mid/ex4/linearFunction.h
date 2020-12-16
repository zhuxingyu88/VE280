#include <string>
#include "complex.h"

class LinearFunction{
    Complex a;
    Complex b;

public:
    LinearFunction(Complex &a, Complex &b);

    Complex evaluate(Complex &x);
    std::string str(Complex complex, Complex complex1);
};
