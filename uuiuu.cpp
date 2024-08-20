#include <iostream>
#include <cmath>

class Complex {
private:
    double real; // действительная часть
    double imag; // мнимая часть
    double r; // модуль
    double theta; // аргумент
    
public:
    Complex() {
        real = 0;
        imag = 0;
        updatePolar();
    }
    
    Complex(double re, double im) {
        real = re;
        imag = im;
        updatePolar();
    }
    
    void updatePolar() {
        r = sqrt(real * real + imag * imag);
        theta = atan2(imag, real);
    }
    
    double getReal() {
        return real;
    }
    
    double getImag() {
        return imag;
    }
    
    Complex operator~() {
        return Complex(real, -imag);
    }
    
    Complex& operator=(double re) {
        real = re;
        imag = 0;
        updatePolar();
        return *this;
    }
    
    Complex operator-() {
        return Complex(-real, -imag);
    }
    
    Complex& operator+=(const Complex& c) {
        real += c.real;
        imag += c.imag;
        updatePolar();
        return *this;
    }
    
    Complex& operator-=(const Complex& c) {
        real -= c.real;
        imag -= c.imag;
        updatePolar();
        return *this;
    }
    
    Complex& operator*=(const Complex& c) {
        double oldReal = real;
        real = real * c.real - imag * c.imag;
        imag = oldReal * c.imag + imag * c.real;
        updatePolar();
        return *this;
    }
    
    Complex& operator/=(const Complex& c) {
        if (c.real == 0 && c.imag == 0) {
            std::cerr << "Error: division by zero" << std::endl;
        } else {
            double denom = c.real * c.real + c.imag * c.imag;
            double oldReal = real;
            real = (real * c.real + imag * c.imag) / denom;
            imag = (imag * c.real - oldReal * c.imag) / denom;
            updatePolar();
        }
        return *this;
    }
    
    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }
    
    Complex operator-(const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }
    
    Complex operator*(const Complex& c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }
    
    Complex operator/(const Complex& c) {
        if (c.real == 0 && c.imag == 0) {
            std::cerr << "Error: division by zero" << std::endl;
            return Complex();
        } else {
            double denom = c.real * c.real + c.imag * c.imag;
            return Complex((real * c.real + imag * c.imag) / denom, (imag * c.real - real * c.imag) / denom);
        }
    }
    
    Complex operator^(int n) {
        double newR = pow(r, n);
        double newTheta = theta * n;
        return Complex(newR * cos(newTheta), newR * sin(newTheta));
    }
};

int main() {

    double a, b;

    std::cout << "Insert real" << std::endl;

    std::cin >> a;

    std::cout << "Insert imagine" << std::endl;

    std::cin >> b;

    Complex z1(a, b);
    Complex z2(1, -2);
    
    Complex sum1 = z1 + z2;
    Complex diff1 = z1 - z2;
    Complex mult1 = z1 * z2;
    Complex div1 = z1 / z2;
    
    z1 += z2;
    z2 -= z1;
    z1 *= z2;
    z2 /= z1;
    
    Complex power = z1 ^ 3;
    


    std::cout << "Sum: " << sum1.getReal() << " + " << sum1.getImag() << "i" << std::endl;
    std::cout << "Difference: " << diff1.getReal() << " + " << diff1.getImag() << "i" << std::endl;
    std::cout << "Product: " << mult1.getReal() << " + " << mult1.getImag() << "i" << std::endl;
    std::cout << "Division: " << div1.getReal() << " + " << div1.getImag() << "i" << std::endl;
    
    std::cout << "Power: " << power.getReal() << " + " << power.getImag() << "i" << std::endl;
    
    return 0;
}