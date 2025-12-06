#include <iostream>
#include "PythonList.h"
using namespace std;

int main()
{

    PythonList myList(5);
    myList[0]=1;
    myList[1]='c';
    myList[2]="haai";
    int x=myList[0];
    char y=myList[1];
    string z=myList[2];
    cout<<x<< y<<z;



    return 0;
}
