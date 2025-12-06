#include <iostream>
#include "Stack.h"
using namespace std;
                                                                                                                //assigment
Stack::Stack(){
    this->itemPtr=nullptr;
    this->stackSize=0;
    this->tos=-1;
}

Stack::Stack(int* itemPtr,int stackSize){
    this->itemPtr=nullptr;
    this->stackSize=0;
    this->tos=-1;
    this->setStack(itemPtr,stackSize);
}

Stack::Stack(const Stack& other){
    this->itemPtr=nullptr;
    this->stackSize=0;
    this->tos=-1;
    this->setStack(other);

}
bool Stack::setStack(int *itemPtr,int stackSize){
      if(itemPtr==NULL){
                this->itemPtr=nullptr;
                this->stackSize=0;
                this->tos=-1;
                return 0;
        }
        if(this->stackSize<stackSize){
                this->stackSize=stackSize;
                delete[] this->itemPtr;
                this->itemPtr=new int[this->stackSize];
        }
        this->stackSize=stackSize;
        this->tos=-1;
        for(int i=0;i<this->stackSize;i++){
            this->itemPtr[i]=itemPtr[i];
            this->tos++;
        }
        return 1;
}
bool Stack::setStack(const Stack& other){
    if(other.itemPtr==NULL){
                this->itemPtr=nullptr;
                this->stackSize=0;
                this->tos=-1;
                return 0;
        }
        if(this->stackSize<other.stackSize){
                this->stackSize=other.stackSize;
                delete[] this->itemPtr;
                this->itemPtr=new int[this->stackSize];
        }
        this->tos=other.tos;
        for(int i=0;i<this->tos;i++){
            this->itemPtr[i]=other.itemPtr[i];
        }
        return 1;

}
Stack& Stack::operator=(const Stack& other){
         this->setStack(other);
         return *this;



}
                                                                                            //getters
int  Stack::getStackSize()const{
    return this->tos+1;
}
int Stack::getElementAt(int index)const{
    return this->itemPtr[index];
}
bool Stack::pushBack(int element){
    if(this->tos>=this->stackSize-1){
            int*temp= new int[stackSize+1];
            for(int i=0;i<stackSize;i++){
                temp[i]=this->itemPtr[i];
            }
            temp[stackSize]=element;
            delete[] this->itemPtr;
            this->itemPtr=temp;
            this->tos=stackSize;
            this->stackSize=stackSize+1;
    }else{
        this->itemPtr[tos+1]=element;
        tos++;
    }
    return 1;

}


bool Stack::pop(int& value ){
     if(this->tos<0)return 0;
     value=this->itemPtr[tos];
     tos--;

    return 1;
}
int& Stack::operator[](int index){
    if(this->tos<0)throw std::out_of_range("out of bounds");
    return this->itemPtr[index];
}
Stack::~Stack(){
    delete[] itemPtr;
}
