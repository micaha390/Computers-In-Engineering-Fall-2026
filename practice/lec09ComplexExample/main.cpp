#include <iostream>
#include <cmath>

using namespace std;

class Complex{
public:
    double real;
    double imag;

    double getPhase() {
        return atan2(imag, real);
    }

    double getMagnitude() {
        return sqrt(real*real + imag*imag);
    }
};

Complex addComplex(Complex x, Complex y);

int main() {
    Complex p{1, 5};
    Complex q{2, -3};

    Complex s = addComplex(p, q);

    cout << "real part of s = " << s.real << endl;
    cout << "imag part of s = " << s.imag << endl;

    Complex x{2, 2};

    cout << "magnitude of x = " << x.getMagnitude() << endl;
    cout << "phase of x = " << x.getPhase() << endl;

    return 0;
}

Complex addComplex(Complex x, Complex y){
    Complex result;

    result.real = x.real + y.real;
    result.imag = x.imag + y.imag;

    return result;
}
