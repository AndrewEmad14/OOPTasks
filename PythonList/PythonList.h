#ifndef PYTHON_LIST_H
#define PYTHON_LIST_H
#include <string>
#include "Item.h"
class PythonList{
    Item* itemList;
    int listSize;

public:
                                                //default batch
    PythonList();
    PythonList(const PythonList& other);
    PythonList& operator=(const PythonList& other);
    PythonList(int listSize);



                                                //insert at
    bool setList(const PythonList& other);
    bool add(Item* item);
    int  getListSize()const;
    bool insertAt(int index);


                                                //assigment and read
    PythonList& operator=(const string& other);
    Item&  operator[](int index);
    const Item& operator[](int index)const;

    friend std::istream& operator>>(std::istream& is,PythonList&  targetList);
    friend std::ostream& operator<<(std::ostream& os, const PythonList& targetList);

    ~PythonList();



};



#endif // PYTHON_LIST_H
