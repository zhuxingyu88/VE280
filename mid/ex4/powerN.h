#include <string>
#include "complex.h"

class PowerN
{
   Complex c;

public:

   PowerN(Complex &c);

   Complex evaluate(int n);
   std::string str(Complex c);
};
