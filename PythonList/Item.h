#ifndef ITEM_H
#define ITEM_H
#define INTEGER 'i'
#define DOUBLE  'd'
#define CHAR    'c'
#define STRING  's'
#include <string>
using namespace std;
class Item {

    int intVal;
    double doubleVal;
    char charVal;
    string strVal;
    char type;                                              // 'i', 'd', 'c', 's'

public:
                                                            // Constructors for each type
    Item();
    Item(int val);
    Item(double val);
    Item(char val);
    Item(const string& val);

                                                            // Copy constructor and assignment
    Item(const Item& other);
    Item& operator=(const Item& other);
    Item& operator=(int val);
    Item& operator=(double val);
    Item& operator=(char val);
    Item& operator=(const string& val);
    char getType() const;

                                                            // Conversion operators for automatic casting
    operator int() const;
    operator double() const;
    operator char() const;
    operator string() const;

                                                            // Display
    friend ostream& operator<<(ostream& os, const Item& targetItem);
    void display()const;


};

#endif // ITEM_H
