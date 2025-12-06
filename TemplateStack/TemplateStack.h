#ifndef TEMPLATE_STACK_H
#define TEMPLATE_STACK_H
#include "iostream"
template<typename T>
class TemplateStack{

    int tos=-1;
    int stackSize;
    T *itemPtr=nullptr;
public:
    TemplateStack();
    TemplateStack(T* itemPtr,int stackSize);
    TemplateStack& operator=(const TemplateStack& other);
    TemplateStack(const TemplateStack& other);
                                                    //setters and getters
    bool setStack(T*itemPtr,int stackSize);
    bool setStack(const TemplateStack& other);
    int  getStackSize()const;
    T  getElementAt(int index)const;
                                                    //insert and deletion
    bool pushBack(T element);
    bool pop(T& value);

    T& operator[](int index);
    const T& operator[](int index)const;

                                                    //destructor
    ~TemplateStack();



};
#endif

template<typename T>
 TemplateStack<T>::TemplateStack(){
    this->itemPtr=nullptr;
    this->stackSize=0;
    this->tos=-1;
}
template<typename T>
TemplateStack<T>::TemplateStack(T* itemPtr,int stackSize){
    this->itemPtr=nullptr;
    this->stackSize=0;
    this->tos=-1;
    this->setStack(itemPtr,stackSize);
}
template<typename T>
TemplateStack<T>::TemplateStack(const TemplateStack& other){
    this->itemPtr=nullptr;
    this->stackSize=0;
    this->tos=-1;
    this->setStack(other);

}
template<typename T>
bool TemplateStack<T>::setStack(T *itemPtr,int stackSize){
      if(itemPtr==NULL){
                this->itemPtr=nullptr;
                this->stackSize=0;
                this->tos=-1;
                return 0;
        }
        if(this->stackSize<stackSize){
                this->stackSize=stackSize;
                delete[] this->itemPtr;
                this->itemPtr=new T[this->stackSize];
        }
        this->stackSize=stackSize;
        this->tos=-1;
        for(int i=0;i<this->stackSize;i++){
            this->itemPtr[i]=itemPtr[i];
            this->tos++;
        }
        return 1;
}
template<typename T>
bool TemplateStack<T>::setStack(const TemplateStack& other){
    if(other.itemPtr==NULL){
                this->itemPtr=nullptr;
                this->stackSize=0;
                this->tos=-1;
                return 0;
        }
        if(this->stackSize<other.stackSize){
                this->stackSize=other.stackSize;
                delete[] this->itemPtr;
                this->itemPtr=new T[this->stackSize];
        }
        this->tos=other.tos;
        for(int i=0;i<this->tos;i++){
            this->itemPtr[i]=other.itemPtr[i];
        }
        return 1;

}
template<typename T>
TemplateStack<T>&  TemplateStack<T>::operator=(const TemplateStack& other){
         this->setStack(other);
         return *this;



}
 template<typename T>                                                                                           //getters
int   TemplateStack<T>::getStackSize()const{
    return this->tos+1;
}
template<typename T>
T  TemplateStack<T>::getElementAt(int index)const{
    return this->itemPtr[index];
}
template<typename T>
bool  TemplateStack<T>::pushBack(T element){
    if(this->tos>=this->stackSize-1){
            T*temp= new T[stackSize+1];
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

template<typename T>
bool  TemplateStack<T>::pop(T& value ){
     if(this->tos<0)return 0;
     value=this->itemPtr[tos];
     tos--;

    return 1;
}
template<typename T>
T&  TemplateStack<T>::operator[](int index){
    if(this->tos<0)||index>tos)throw std::out_of_range("out of bounds");
    return this->itemPtr[index];
}
template<typename T>
const T& TemplateStack<T>::operator[](int index)const{
     if(this->tos<0)||index>tos)throw std::out_of_range("out of bounds");
    return this->itemPtr[index];
}

template<typename T>
 TemplateStack<T>::~TemplateStack<T>(){
    delete[] itemPtr;
}
