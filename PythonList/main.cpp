#include <iostream>
#include "PythonList.h"

#include "StreamValidator.h"
using namespace std;

int main()
{
    cout<<"please Enter you List"<<endl;
    PythonList myList;
    cin>>myList;
    cout<<myList<<endl;
    myList[0]="i have changed";
    myList[1]=3.14;
    cout<<myList;






    return 0;
}
