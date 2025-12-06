#include <iostream>
#include "Complex.h"
#include "StreamValidator.h"
#define DEFAULTVAL 0
#define OPTION_ADDITION                      1
#define OPTION_SUBTRACTION                   2
#define OPTION_MULTIPLICATION                3
#define OPTION_DIVISION                      4
#define OPTION_NUMBER_ADDITION               5
#define OPTION_NUMBER_SUBTRACTION            6
#define OPTION_NUMBER_MULTIPLICATION         7
#define OPTION_NUMBER_DIVISION               8
#define OPTION_COMPARE                       9
#define OPTION_DISPLAY_COMPLEX              10
#define OPTION_EXIT                         11

using namespace std;
void displayWelcome();
bool getUserInput(Complex &complexNum);
bool getUserInput(int &choice);
bool getUserInput(double &num);
void displayMenu(void);

int main(void) {
                                                            //welcome message



    displayWelcome();
    Complex complex1,complex2,complex3;
    int choice=DEFAULTVAL,result=DEFAULTVAL;
    double realNumber=DEFAULTVAL;


                                                // Get first complex number
    while(!(cin>>complex1)){cout<<"Input Invalid,Please Try Again"<<endl;cin.clear(); }
                                                     //Get second complex number
    while(!(cin>>complex2)){cout<<"Input Invalid,Please Try Again"<<endl;cin.clear(); }





    while(choice!=OPTION_EXIT){
        displayMenu();
        while(!(getUserInput(choice))){cout<<"Input Invalid,Please Try Again"<<endl;}
        switch(choice){
            case OPTION_ADDITION:
                complex1=complex1+complex2;
                cout<<complex1<<endl;
                break;
            case OPTION_SUBTRACTION:
                complex1=complex1-complex2;
                cout<<complex1<<endl;
                break;
            case OPTION_MULTIPLICATION:
                complex1*=complex2;
                cout<<complex1<<endl;
                break;
            case OPTION_DIVISION:
                if(!complex2.isComplexZero()){
                    complex1/=complex2;
                    cout<<complex1<<endl;
                }else{
                cout<<"Cant Divide by zero"<<endl;
                }
                break;
            case OPTION_NUMBER_ADDITION:
                cout<<"Please enter a number"<<endl;
                while(!(getUserInput(realNumber))){cout<<"Input Invalid,Please Try Again"<<endl;}
                complex1+=realNumber;
                cout<<complex1<<endl;
                realNumber=DEFAULTVAL;
                break;
            case OPTION_NUMBER_SUBTRACTION:
                cout<<"Please enter a number"<<endl;
                while(!(getUserInput(realNumber))){cout<<"Input Invalid,Please Try Again"<<endl;}
                complex1-=realNumber;
                cout<<complex1<<endl;
                realNumber=DEFAULTVAL;
                break;
            case OPTION_NUMBER_MULTIPLICATION:
                cout<<"Please enter a number"<<endl;
                while(!(getUserInput(realNumber))){cout<<"Input Invalid,Please Try Again"<<endl;}
                complex1=complex1*realNumber;
                cout<<complex1<<endl;
                realNumber=DEFAULTVAL;
                break;
            case OPTION_NUMBER_DIVISION:
            cout<<"Please enter a number"<<endl;
                while(!(getUserInput(realNumber))&&realNumber==0){cout<<"Input Invalid,Please Try Again"<<endl;}
                complex1=complex1/realNumber;
                cout<<complex1<<endl;
                realNumber=DEFAULTVAL;
                break;
            case OPTION_COMPARE:
                result =complex1.compareComplex(complex2);
                if(result==0){
                    cout<<"complex1 is equal to complex 2"<<endl;
                }else if(result==-1){
                    cout<<"complex1 is greater that complex2"<<endl;
                }else{
                    cout<<"complex2 is greater than complex1"<<endl;
                }
                break;
            case OPTION_DISPLAY_COMPLEX:
                cout<<complex1<<endl;
                cout<<complex2<<endl;
                break;
            default:
            ;
        }
    }




    return 0;
}
void displayWelcome() {
    cout << "\n";
    cout << "========================================" << endl;
    cout << "    COMPLEX NUMBER CALCULATOR" << endl;
    cout << "========================================" << endl;
    cout << "\n";
    cout << "Welcome! This program performs operations" << endl;
    cout << "on complex numbers (a + bi format)." << endl;
    cout << "\n";
}

bool getUserInput(Complex &complexNum){
    string stream="";
    double real=DEFAULTVAL,imag=DEFAULTVAL;
    cout << "Enter Complex Number " << ":" << endl;
    cout << "  Real part: ";
    getline(cin,stream);
    if(StreamValidator::isEmpty(stream)||!(StreamValidator::CastToDouble(stream,real))){
            return false;
    }

    cout << "  Imaginary part: ";
    getline(cin,stream);
    if(StreamValidator::isEmpty(stream)||!(StreamValidator::CastToDouble(stream,imag))){
            return false;
    }

    cout << endl;
    complexNum.setComplex(real,imag);
    return true;

}
bool getUserInput(int &choice){
    string stream;
    getline(cin,stream);
    if(StreamValidator::isEmpty(stream)||!(StreamValidator::CastToIntger(stream,choice))){
            return false;
    }
    return true;
}
bool getUserInput(double &num){
    string stream;
    getline(cin,stream);
    if(StreamValidator::isEmpty(stream)||!(StreamValidator::CastToDouble(stream,num))){
            return false;
    }
    return true;
}
void displayMenu() {
    cout << "----------------------------------------" << endl;
    cout << "Select an operation:" << endl;
    cout << "  1. Addition" << endl;
    cout << "  2. Subtraction" << endl;
    cout << "  3. Multiplication" << endl;
    cout << "  4. Division" << endl;
    cout << "  5. Number_Addition" << endl;
    cout << "  6. Number_Subtraction" << endl;
    cout << "  7. Number_Multiplication" << endl;
    cout << "  8. Number_Division" << endl;
    cout << "  9. Compare" << endl;
    cout << "  10. Display complex numbers" << endl;
    cout << "  11. Exit" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Your choice: ";

}


