#include "Item.h"
#include <stdexcept>
#include <iostream>
                                                                        //default constrcutors and assigment
Item::Item() : intVal(0), type(INTEGER) {}
Item::Item(int val){
    this->intVal=val;
    this->type=INTEGER;
}
Item::Item(double val){
    this->doubleVal=val;
    this->type=DOUBLE;
}
Item::Item(char val){
    this->charVal=val;
    this->type=CHAR;
}
Item::Item(const string& val){
    this->strVal=val;
    this->type=STRING;
}
Item::Item(const Item& other){
     this->type = other.type;
            switch(type) {
                case INTEGER: this->intVal = other.intVal; break;
                case DOUBLE: this->doubleVal = other.doubleVal; break;
                case CHAR: this->charVal = other.charVal; break;
                case STRING: this->strVal =  other.strVal; break;
            }
}
Item& Item::operator=(const Item& other){
      this->type = other.type;
              switch(type) {
                case INTEGER: this->intVal = other.intVal; break;
                case DOUBLE: this->doubleVal = other.doubleVal; break;
                case CHAR: this->charVal = other.charVal; break;
                case STRING: this->strVal =  other.strVal; break;
            }
            return *this;
}
                                                // Assignment from int
Item& Item::operator=(int val) {


    intVal = val;
    type = INTEGER;
    return *this;
}

                                            // Assignment from double
Item& Item::operator=(double val) {
    doubleVal = val;
    type = DOUBLE;
    return *this;
}

                                        // Assignment from char
Item& Item::operator=(char val) {
    charVal = val;
    type = CHAR;
    return *this;
}


Item& Item::operator=(const string& val) {
    strVal = val;
    type = STRING;
    return *this;
}
                                                                // Conversion operators (overloading the casting operator)
Item::operator int() const {
    if (type !=INTEGER) throw invalid_argument("Not an int");
    return intVal;
}

Item::operator double() const {
    if (type != DOUBLE) throw invalid_argument("Not a double");
    return doubleVal;
}

Item::operator char() const {
    if (type != CHAR) throw invalid_argument("Not a characater");
    return charVal;
}

Item::operator string() const {
    if (type !=STRING) throw invalid_argument("Not a string");
    return strVal;
}
void Item::display()const{
         switch(this->type) {
            case INTEGER: {
                int tempInt = this->intVal;
                cout << tempInt;
                break;
            }
            case DOUBLE: {
                double tempDouble = this->doubleVal;  // Fixed typo
                cout << tempDouble;
                break;
            }
            case CHAR: {
                char tempChar = this->charVal;
                cout << tempChar;
                break;
            }
            case STRING: {
                string tempString = this->strVal;
                cout << tempString;  // Fixed: was 'x'
                break;
            }
        }
}
 ostream& operator<<(ostream& os, const Item& targetItem){

            targetItem.display();
            return os;
 }
char Item::getType() const { return type; }
