#include <sstream>
#include "complex.h"

Complex::Complex(double x, double y):x(x), y(y){
}


double Complex::getX()
{
    return x;
}

double Complex::getY()
{
    return y;
}

Complex Complex::add(Complex &c){
    return Complex(this->getX()+c.getX(), this->getY()+c.getY());
}

Complex Complex::multiply(Complex &c){
    return Complex(this->getX()*c.getX() - this->getY()*c.getY(), this->getX()*c.getY() + this->getY()*c.getX());
}

std::string toString(Complex complex){
   std::ostringstream is;
   is << complex.getX() << " + " << complex.getY() << 'i';
   return is.str();
}
