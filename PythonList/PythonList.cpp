#include "PythonList.h"
#include <iostream>
#include <sstream>
#include "StreamValidator.h"
                                            //default batch
    PythonList::PythonList(){

        this->itemList=nullptr;
        this->listSize=0;
    }
     PythonList::PythonList(int listSize){

        this->itemList=new Item[listSize];
        this->listSize=listSize;
    }
    PythonList::PythonList(const PythonList& other){
            this->itemList=nullptr;
            this->listSize=0;

            this->setList(other);
    }
    PythonList&   PythonList::operator=(const PythonList& other){
            delete[] this->itemList;
            this->itemList=nullptr;
            this->listSize=0;

            this->setList(other);
            return *this;
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

        for(int i=0;i<this->listSize;i++){
            this->itemList[i]=other.itemList[i];
        }
        return 1;
    }

    int  PythonList::getListSize()const{

        return this->listSize;
    }
    Item& PythonList::operator[](int index){
        if(index<0||index>=this->listSize)throw std::out_of_range("out of bounds");
        return this->itemList[index];
    }
    const Item& PythonList::operator[](int index)const{
        if(index<0||index>=this->listSize)throw std::out_of_range("out of bounds");
        return this->itemList[index];
    }
istream& operator>>(istream& is,PythonList&  targetList){
    string input;
    getline(is, input);
    if(StreamValidator::isEmpty(input)){
           is.setstate(ios::failbit);
           return is;
    }
    targetList.listSize=StreamValidator::getNumberOfInput(input);
    delete[] targetList.itemList;
    targetList.itemList= new Item[targetList.listSize];

    stringstream ss(input);
    string word;

    int tempInt=0;
    double tempDouble=0.0;
    char   tempChar=' ';

    for(int i=0;i<targetList.listSize;i++) {
        ss>>word;
        if(StreamValidator::CastToIntger(word,tempInt)){
            targetList.itemList[i]=tempInt;
        }else if(StreamValidator::CastToDouble(word,tempDouble)){
            targetList.itemList[i]=tempDouble;
        }else if(StreamValidator::CastToChar(word,tempChar)){
            targetList.itemList[i]=tempChar;
        }else{
            targetList.itemList[i]=word;
        }
    }


    return is;

}
ostream& operator<<(std::ostream& os, const PythonList& targetList){


    if(targetList.itemList == nullptr) {
        return os;
    }

    for(int i = 0; i < targetList.listSize; i++) {

        if(i > 0) os << " ";
        os << targetList[i];
    }


    return os;
}






                                                //insert items
//    bool add(Item* item);
//    bool insertAt(index);





    PythonList::~PythonList(){
        delete[] itemList;
    }
