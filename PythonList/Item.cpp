#include "Item.h"
#include <stdexcept>
                                                                        //default constrcutors and assigment
Item::Item() : intVal(0), type('i') {}
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
    type = 'i';
    return *this;
}

                                            // Assignment from double
Item& Item::operator=(double val) {
    doubleVal = val;
    type = 'd';
    return *this;
}

                                        // Assignment from char
Item& Item::operator=(char val) {
    charVal = val;
    type = 'c';
    return *this;
}


Item& Item::operator=(const string& val) {
    strVal = val;
    type = 's';
    return *this;
}
                                                                // Conversion operators
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


char Item::getType() const { return type; }
