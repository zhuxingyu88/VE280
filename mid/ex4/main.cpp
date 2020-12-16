#include <iostream>

#include "complex.h"
#include "linearFunction.h"
#include "powerN.h"

using namespace std;

int main(){
      Complex c1(1, 1);
      Complex c2(2, 0);
      Complex c3(0.5, -4);

      LinearFunction lf(c1, c2);
      PowerN pn(c3);

      cout << c1.toString() << endl;
      cout << c2.toString() << endl;
      cout << c3.toString() << endl;

      cout << lf.str() << endl;
      cout << pn.str() << endl;

      cout << lf.evaluate(c3).str() << endl;
      cout << pn.evaluate(2).str() << endl;

      return 0;
}
