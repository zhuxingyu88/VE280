#include <iostream>
#include <sstream>
#include "linearFunction.h"

LinearFunction::LinearFunction(Complex &a, Complex &b):a(a), b(b){
}

Complex LinearFunction::evaluate(Complex &x){
   return a.multiply(x).add(b);
}

std::string LinearFunction::str(Complex complex, Complex complex1){
   std::ostringstream os;
   os << complex.toString(complex) << "x + " << complex1.toString(complex1);
   return os.str();
}
