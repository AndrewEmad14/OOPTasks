//Arithmetic Operators:
//                              done
//Addition (+)
//Subtraction (-)
//Multiplication (*)
//Division (/)
//Unary plus (+)
//Unary minus (-)
//Unary Multiplication (*)
//Unary Division (/)
//
//Compound Assignment Operators: done
//
//  += (add and assign)
//  -= (subtract and assign)
//  *= (multiply and assign)
//  /= (divide and assign)
//
//Comparison Operators:done
//
//== (equality)
//!= (inequality)
//< (less than) - though this is mathematically problematic for complex numbers
//>(greater than) - same issue as above
//<= (less than or equal)
//>= (greater than or equal)
//Note: The ordering operators (<, >, <=, >=) don't have a standard mathematical meaning for complex numbers,
//but some assignments may ask you to implement them anyway (perhaps by comparing magnitudes).
//
//Stream Operators:
//<< (output stream, for printing)                      done
//>>(input stream, for reading)
//

//Other Possible Operators:
//copy constructor
//constructor                       done
//destructor
//setter ,getter,display
//= (assignment operator)
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#define EPSILON 1e-9                //tolerance value
#include <string>
class Complex{
    double real;
    double imag;


    public:
        Complex();
        Complex(double real,double imag=0.0);
        void setComplex(double real,double imag);
        double getReal();
        double getImag();
        bool isComplexZero();
        std::string complexToString()const;
                                                        //Math
        Complex operator+(const Complex& other);
        Complex operator-(const Complex& other);
        Complex operator*(const Complex& other);
        Complex operator/(const Complex& other);
                                                        //assignment
        void operator+=(const Complex& other);
        void operator-=(const Complex& other);
        void operator*=(const Complex& other);
        void operator/=(const Complex& other);

                                                        //unary
        Complex operator+(double realNum);
        Complex operator-(double realNum);
        Complex operator*(double realNum);
        Complex operator/(double realNum);
                                                        //assigment
        void operator+=(double realNum);
        void operator-=(double realNum);
        void operator*=(double realNum);
        void operator/=(double realNum);
                                                        //compare
        double getMagnitude()const;
        bool operator==(const Complex& other)const;
        bool operator!=(const Complex& other)const;
        bool operator>(const Complex& other)const;
        bool operator<(const Complex& other)const;
        bool operator>=(const Complex& other)const;
        bool operator<=(const Complex& other)const;
        int compareComplex(const Complex& c2)const;
                                                        //input and output

        friend std::ostream& operator<<(std::ostream& os, const Complex& c);
        //friend istream& operator>>(istream& is, Complex& c);

};








#endif // COMPLEX
