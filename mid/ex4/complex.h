class Complex{


    double x;
    double y;
public:
    Complex(double x=0, double y=0);


    double getX();
    double getY();

    Complex add(Complex &c);
    Complex multiply(Complex &c);
    std::string toString(Complex complex);
};
