#include <iostream>

using namespace std;

class Complex {
public:
    Complex(){
    real = 0.0;
    imaginary = 0.0;
    }
    Complex(double r, double i){
        real = r;
        imaginary = i;
    }
    double getReal(){
        return real;
    }
    double getIm(){
        return imaginary;
    }
    void printcomplex(){
        cout << "Real:" << real << endl;
        cout << "Imaginary: "<< imaginary << endl;
    }
private:
    double real = 0.0;
    double imaginary = 0.0;
};


int main()
{
    cout << "Hello World!" << endl;
    Complex c1(3.0,2.0);

    c1.printcomplex();
    return 0;
}
