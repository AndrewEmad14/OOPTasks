#include "CustomString.h"
#include <iostream>
#define DEFAULT_VAL 0
using namespace std;

                                        //Constructors --done
CustomString::CustomString(){
        strSize=0;

}

CustomString::CustomString(const char* input){
        if(input==NULL){
            this->str=nullptr;
            return;
        }

        const char*inputHead= input;
        this->strSize=cstringLength(input);
        this->str=new char[this->strSize];
        char*head=this->str;
        while(*(inputHead)){
            *head=*inputHead;
            head++;
            inputHead++;

        }

        *head='\0';

}
CustomString::CustomString(CustomString& other){
        if(other.str==NULL){
            this->str=nullptr;
            return;
        }

        const char*inputHead= other.str;
        this->strSize=other.strSize;
        this->str=new char[this->strSize];
        char*head=this->str;
        while(*(inputHead)){
            *head=*inputHead;
            head++;
            inputHead++;

        }

        *head='\0';

}
                                            //display --done
void CustomString::display(){
        if(this->str==NULL) return;
            char* head = this->str;
            while(*(head)){
                cout<<*head;
                head++;
            }
            cout<<endl;


}
void CustomString::operator*(int x){
    while(x){
          this->display();
          x--;
    }


}
                                                    //done
bool CustomString::setString(const char* input){
    if(input==NULL)return 0;
    this->strSize= cstringLength(input)+1;
    delete[] this->str;
    this->str=new char[strSize+1];
    char*head=this->str;
    while(*input){
            *head=*input;
            head++;
            input++;
    }
    *head='\0';

    return 1;
}
                                                            //setters and getters  --done
bool CustomString::setString(const CustomString& other){
    if(other.str==NULL)return 0;
    this->strSize=other.strSize+1;
    delete[] this->str;
    this->str=new char[this->strSize];
    char*head=this->str;
    char*input=other.str;
    while(*input){
            *head=*input;
            head++;
            input++;
    }
    *head='\0';

    return 1;
}


char* CustomString::getString(){
    if(this->str==nullptr)return nullptr;
    return this->str;
}



int CustomString::getSize(){
    return strSize;
}
                                            //static functions
int CustomString::cstringLength(const char* input){
    if(input==NULL)return 0;
    int counter=0;
    while(*input){
        input++;
        counter++;
    }
    return counter;

}
bool CustomString::strCopy(char str1[],char str2[],int str1Size){
    int str2Length=cstringLength(str2);
    if(str1Size<str2Length)return 0;
    while(*(str2)){
        *(str1)=*(str2);
        str1++;
        str2++;
    }
    *str1='\0';
    return 1;

}
                                            //to lower case and to upper case    -- done
bool CustomString::toLower(){
    if(this->str!=NULL)return 0;
    int diff='a'-'A';

    char* head =this->str;
    while(*(head)){
        if(*head>='A'&&*head<='Z'){
            *head+=diff;
        }
        head++;
    }
    return 1;
}
bool CustomString::toUpper(){
    if(this->str!=NULL)return 0;
    int diff='a'-'A';
    char* head =this->str;
    while(*(head)){
        if(*head>='a'&&*head<='z'){
            *head-=diff;
        }
        head++;
    }
    return 1;
}

                                                                        //append done
bool CustomString::append(const char* input){
    if(input==NULL)return true;
    char* res;
    int originalSize=this->strSize;
    int inputSize=cstringLength(input);
                                            //get the sum of the sizes and create an array with both sizes
    this->strSize=originalSize+inputSize;
    res=new char[this->strSize+1];
    char* head=res;
                                            //if the caller is not empty put it in the new char array
    if(this->str != NULL){
            char* originalHead=this->str;
            while(*(originalHead)){
                *(res)=*(originalHead);
                *(originalHead)++;
                res++;
            }
            delete[] this->str;
    }
                                            //if the input is not null then put it in the new char array
    while(*input){
        *(res)=*(input);
        input++;
        res++;
    }
    *res='\0';                              //dont forget the terminator \0
    this->str =head;
    return 1;                               //operation successful
}




bool CustomString::append(const CustomString& other){
    if(other.str==NULL)return true;
    char* res;
    int originalSize=this->strSize;
    int inputSize=other.strSize;
                                            //get the sum of the sizes and create an array with both sizes
    this->strSize=originalSize+inputSize;
    res=new char[this->strSize+1];
    char* head=res;
                                            //if the caller is not empty put it in the new char array
    if(this->str != NULL){
            char* originalHead=this->str;
            while(*(originalHead)){
                *(res)=*(originalHead);
                *(originalHead)++;
                res++;
            }
            delete[] this->str;
    }
                                            //if the input is not null then put it in the new char array
    char* input = other.str;
    while(*input){
        *(res)=*(input);
        input++;
        res++;
    }
    *res='\0';                              //dont forget the terminator \0
    this->str =head;
    return 1;                               //operation successful
}




                                                                            //compare --done
int CustomString::strCompare(const char str2[])const {
    if(this->str == nullptr && str2 == nullptr) return 0;
    if(this->str == nullptr) return 1;
    if(str2 == nullptr) return -1;

    int size1 = this->strSize - 1;          // Exclude null terminator
    int size2 = cstringLength(str2);

                                        // Compare by length first
    if(size1 < size2) return 1;
    if(size1 > size2) return -1;

                                        // Same length
    char* str1 = this->str;
    while(*str1 != '\0') {
        if(*str1 < *str2) return 1;
        if(*str1 > *str2) return -1;
        str1++;
        str2++;
    }

    return 0;
}
int CustomString::strCompare(const CustomString& other)const {
    if(this->str == nullptr && other.str == nullptr) return 0;
    if(this->str == nullptr) return 1;
    if(other.str == nullptr) return -1;

    int size1 = this->strSize - 1;          // Exclude null terminator
    int size2 = other.strSize - 1;

                                        // Compare by length first
    if(size1 < size2) return 1;
    if(size1 > size2) return -1;

                                        // Same length
    char* str1 = this->str;
    char* str2 = other.str;
    while(*str1 != '\0') {
        if(*str1 < *str2) return 1;
        if(*str1 > *str2) return -1;
        str1++;
        str2++;
    }

    return 0;
}



                                                                    //overload

                                                                    //uniary operations --done

CustomString CustomString::operator+(const char* other){
        CustomString temp=this->str;
        temp.append(other);
        return temp;

}
CustomString CustomString::operator+(const CustomString& other){
        CustomString temp=this->str;
        temp.append(other);
        return temp;
}



                                                                    //asignment --done
CustomString&  CustomString::operator=(const CustomString& other){
        this->setString(other);
        return *this;

}
CustomString&  CustomString::operator=(const char* other){
        this->setString(other);
        return *this;

}

                                                                    //asigment + append --done


CustomString&  CustomString::operator+=(const CustomString& other){
        this->append(other);
        return *this;
}

                                                                    //compare String--done

bool CustomString::operator==(const CustomString& other)const{
    int result=this->strCompare(other);
    return result==0;
}
bool CustomString::operator!=(const CustomString& other)const{
    int result=this->strCompare(other);
    return result==1 || result==-1;
}
bool CustomString::operator>(const CustomString& other)const{
    int result=this->strCompare(other);
    return result==-1;
}
bool CustomString::operator<(const CustomString& other)const{
    int result=this->strCompare(other);
    return result==1;
}
bool CustomString::operator>=(const CustomString& other)const{
    int result=this->strCompare(other);
    return result==0 || result==-1;
}
bool CustomString::operator<=(const CustomString& other)const{
    int result=this->strCompare(other);
    return result==0 || result==1;
}
                                                                    //compare CString

bool CustomString::operator==(const char other[])const{
    int result=this->strCompare(other);
    return result==0;
}
bool CustomString::operator!=(const char other[])const{
     int result=this->strCompare(other);
    return result==1 || result==-1;
}
bool CustomString::operator>(const char other[])const{
     int result=this->strCompare(other);
    return result==-1;
}
bool CustomString::operator<(const char other[])const{
    int result=this->strCompare(other);
    return result==1;
}
bool CustomString::operator>=(const char other[])const{
     int result=this->strCompare(other);
    return result==0 || result==-1;
}
bool CustomString::operator<=(const char other[])const{
    int result=this->strCompare(other);
    return result==0 || result==1;
}

                                            //write access
char& CustomString::operator[](int index){
    if(index>this->strSize-1)throw std::out_of_range("Complex number has only 2 components");
    return this->str[index];
}
                                            //read only access
const char& CustomString::operator[](int index) const{
    if(index>this->strSize-1)throw std::out_of_range("Complex number has only 2 components");
    return this->str[index];
}
ostream& operator<<(std::ostream& os, const CustomString& c){
    os<<c.str;
    return os;

}
istream& operator>>(std::istream& is, CustomString& c){
       //to be implemented

}

CustomString::~CustomString(){
    delete(str);
}

