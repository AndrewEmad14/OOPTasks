#include "PythonList.h"
#include <iostream>
                                            //default batch
    PythonList::PythonList(){
        this->tos=-1;
        this->itemList=nullptr;
        this->listSize=0;
    }
     PythonList::PythonList(int listSize){
        this->tos=listSize-1;
        this->itemList=new Item[listSize];
        this->listSize=listSize;
    }
    PythonList::PythonList(const PythonList& other){
            this->itemList=nullptr;
            this->listSize=0;
            this->tos=-1;
            this->setList(other);
    }
    PythonList&   PythonList::operator=(const PythonList& other){
            this->itemList=nullptr;
            this->listSize=0;
            this->tos=-1;
            this->setList(other);
    }


                                                //setters and getters
    bool PythonList::setList(const PythonList& other){
         if(other.itemList==NULL){
                return 0;
        }
        if(this->listSize<other.listSize){
                this->listSize=other.listSize;
                delete[] this->itemList;
                this->itemList=new Item[this->listSize];
        }
        this->tos=other.tos;
        for(int i=0;i<this->tos;i++){
            this->itemList[i]=other.itemList[i];
        }
        return 1;
    }

    int  PythonList::getListSize()const{

        return this->listSize;
    }
    Item& PythonList::operator[](int index){
        if(this->tos<0||index>tos)throw std::out_of_range("out of bounds");
        return this->itemList[index];
    }
    const Item& PythonList::operator[](int index)const{
        if(this->tos<0||index>tos)throw std::out_of_range("out of bounds");
        return this->itemList[index];
    }

                                                //insert items
//    bool add(Item* item);
//    bool insertAt(index);
//
//
//                                                //assigment and read
//    PythonList& operator=(const string& other);
//    string&  operator[](int index);
//    const string& operator[](int index)const;




    PythonList::~PythonList(){
        delete[] itemList;
    }
