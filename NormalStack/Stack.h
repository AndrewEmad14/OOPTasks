#ifndef STACK_H
#define STACK_H

class Stack{

    int tos=-1;
    int stackSize;
    int *itemPtr=nullptr;
public:
    Stack();
    Stack(int* itemPtr,int stackSize);
    Stack& operator=(const Stack& other);
    Stack(const Stack& other);
                                                    //setters and getters
    bool setStack(int*itemPtr,int stackSize);
    bool setStack(const Stack& other);
    int  getStackSize()const;
    int  getElementAt(int index)const;
                                                    //insert and deletion
    bool pushBack(int element);
    bool pop(int& value);

    int& operator[](int index);
    const int& operator[](int index)const;

                                                    //destructor
    ~Stack();


};






#endif // STACK_H
