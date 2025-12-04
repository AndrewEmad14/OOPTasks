#include <iostream>
#include "Complex.h"
#include <math.h>
using namespace std;
//Complex() : counter=0   ???? what is happening here
//the constuctor takes the parameters of its call
//the : starts the initilization of the varibles 'counter = 0'
//this works  when you have a constant variable or a refrence,or somthing you wish to give an inital value to

Complex::Complex(){
    real=0;
    imag=0;
}
Complex::Complex(double real, double imag){

    this->real = real;
    this->imag = imag;

}
void Complex::setComplex(double real,double imag){
    this->real = real;
    this->imag = imag;
}
double Complex::getReal(){
    return this->real;
}
double Complex::getImag(){
    return this->imag;
}
bool Complex::isComplexZero(){
    return this->real == 0 && this->imag == 0;
}
string Complex::complexToString()const{
    string complexStr="";
    bool isRealZero = (this->real==0);
    bool isImagZero = (this->imag==0);
    bool isImagNegative  = (this->imag<0);
    bool isImagOne= (this->imag == 1)||(this->imag == -1);


                                                            //if both empty
    if (isRealZero && isImagZero){
        complexStr+="0";
        return complexStr;
    }
                                                            //print real
    if(!isRealZero){
        complexStr+=to_string(real);
    }

                                                            //print imaginary
    if(!isImagZero){
                                                            //set the postive sign
        if(!isRealZero){
            if(!isImagNegative)
                complexStr+="+";
        }
                                                            //if imag is equal to 1
        if(isImagOne){
            if(isImagNegative){
                complexStr+="-i";
            }else{
                complexStr+="i";

            }

        }else{
            complexStr+=to_string(imag);
            complexStr+="i";
        }
    }
   return complexStr;

}


                                                                                                        //Math operations

Complex Complex:: operator+(const Complex& other)  {
    double real=this->real + other.real;
    double imag=this->imag + other.imag;
    return Complex(real, imag);
}

Complex Complex:: operator-(const Complex& other)  {
    double real=this->real - other.real;
    double imag=this->imag - other.imag;
    return Complex(real,imag);
}

Complex Complex:: operator*(const Complex& other)  {
    double real=this->real * other.real - this->imag * other.imag;
    double imag=this->real * other.imag + this->imag * other.real;
    return Complex(real,imag);
}
Complex Complex:: operator/(const Complex& other)  {
    double denominator = other.real * other.real + other.imag * other.imag;
    double real=(this->real * other.real - this->imag * other.imag)/denominator;
    double imag=(this->real * other.imag + this->imag * other.real)/denominator;
    return Complex(real,imag);
}

                                                                                    //assignment

Complex& Complex:: operator=(const Complex& other){

    this->real = other.real;
    this->imag = other.imag;
    return *this;
}

Complex& Complex::operator+=(const Complex& other) {
    this->real += other.real;
    this->imag += other.imag;
}

Complex& Complex::operator-=(const Complex& other) {
    this->real -= other.real;
    this->imag -= other.imag;
}

Complex& Complex::operator*=(const Complex& other) {
    double newReal = this->real * other.real - this->imag * other.imag;
    double newImag = this->real * other.imag + this->imag * other.real;
    this->real = newReal;
    this->imag = newImag;
}

Complex& Complex::operator/=(const Complex& other) {
    double denominator = other.real * other.real + other.imag * other.imag;
    double newReal = (this->real * other.real + this->imag * other.imag) / denominator;
    double newImag = (this->imag * other.real - this->real * other.imag) / denominator;
    this->real = newReal;
    this->imag = newImag;
}




                                                                                                                                        //UNIARY operations
                                                                            //UNIARY operations



Complex Complex:: operator+(double realNum)  {
    double real=this->real + realNum;
    double imag=this->imag ;
    return Complex(real, imag);
}

Complex Complex:: operator-(double realNum)  {
    double real=this->real - realNum;
    double imag=this->imag;
    return Complex(real,imag);
}

Complex Complex:: operator*(double realNum)  {
    double real=this->real * realNum;
    double imag=this->imag * realNum;
    return Complex(real,imag);
}
Complex Complex:: operator/(double realNum)  {
    double real=(this->real)/realNum;
    double imag=(this->imag )/realNum;
    return Complex(real,imag);
}



                                                                //assignment with int
Complex&  Complex::operator+=(double realNum) {
    this->real += realNum;
    return *this;

}

Complex&  Complex::operator-=(double realNum) {
    this->real -= realNum;
    return *this;

}

Complex&  Complex::operator*=(double realNum) {
    this->real *= realNum;
    this->imag *= realNum;
    return *this;
}

Complex&  Complex::operator/=(double realNum) {
    this->real /= realNum;
    this->imag /= realNum;
    return *this;
}
                                                                                //prefix
Complex& Complex::operator++(){
    this->real++;
    this->imag++;
    return *this;
}
Complex& Complex::operator--(){
    this->real--;
    this->imag--;
    return *this;
}
                                                                            //postfix
Complex Complex::operator++(int) {
    Complex temp = *this;
    this->real++;
    this->imag++;
    return temp;
}
Complex Complex::operator--(int){
     Complex temp = *this;
    this->real--;
    this->imag--;
    return temp;
}


                                                                                                            //comparison
double Complex::getMagnitude()const{
    return sqrt(this->real * this->real + this->imag * this->imag);
}

bool Complex::operator==(const Complex& other)const{
    double c1=this->getMagnitude();
    double c2=other.getMagnitude();
    return fabs(c1-c2)<EPSILON;
}

bool Complex::operator!=(const Complex& other)const {
    return !(*this == other);
}
bool Complex::operator<(const Complex& other)const {
    double c1 = this->getMagnitude();
    double c2 = other.getMagnitude();
    return c1 < c2;
}
bool Complex::operator>(const Complex& other)const {
    double c1 = this->getMagnitude();
    double c2 = other.getMagnitude();
    return c1 > c2;
}
bool Complex::operator<=(const Complex& other)const {
    return (*this < other) || (*this == other);
}

bool Complex::operator>=(const Complex& other)const {
    return (*this > other) || (*this == other);
}
int Complex::compareComplex(const Complex& c2)const {
    if (*this < c2) return -1;
    if (*this == c2) return 0;
    return 1;
}

istream& operator>>(istream& is, Complex& c){
    string stream="";
    double real=DEFAULTVAL,imag=DEFAULTVAL;
    cout << "Enter Complex Number " << ":" << endl;
    cout << "  Real part: ";
    getline(is,stream);
    if(StreamValidator::isEmpty(stream)||!(StreamValidator::CastToDouble(stream,real))){
           is.setstate(ios::failbit);
           return is;

    }

    cout << "  Imaginary part: ";
    getline(is,stream);
    if(StreamValidator::isEmpty(stream)||!(StreamValidator::CastToDouble(stream,imag))){
            is.setstate(ios::failbit);
            return is;

    }

    cout << endl;
    c.setComplex(real,imag);
    return is;

}
                                                                //I/O
ostream& operator<<(ostream& os, const Complex& c) {

    os<<c.complexToString();

    return os;
}

double&  Complex::operator[](int index) {
    if (index == 0) return real;
    else if (index == 1) return imag;
    else throw std::out_of_range("Complex number has only 2 components");
}
                                                    //read only access
const double& Complex:: operator[](int index) const {
    if (index == 0) return real;
    else if (index == 1) return imag;
    else throw std::out_of_range("Complex number has only 2 components");
}

