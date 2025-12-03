#include "CustomString.h"
#include <iostream>
#define DEFAULT_VAL 0
using namespace std;

                                        //done
CustomString::CustomString(){
        strSize=0;

}
                                        //done
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
                                                        //done
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
                                            //done
void CustomString::display(){
        if(this->str==NULL) return;
            char* head = this->str;
            while(*(head)){
                cout<<*head;
                head++;
            }
            cout<<endl;


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
                                                            //done
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

                                                    //done
char* CustomString::getString(){
    if(this->str==nullptr)return nullptr;
    return this->str;
}


                                                //done
int CustomString::getSize(){
    return strSize;
}
                                            //returns char arr size
int CustomString::cstringLength(const char* input){
    if(input==NULL)return 0;
    int counter=0;
    while(*input){
        input++;
        counter++;
    }
    return counter;

}
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

                                                                        //done
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



                                                                        //done
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
//int CustomString::strCompare(char str2[]){
//    if(this->str == NULL || str2==NULL)return -2;
//    int sumStr1=DEFAULT_VAL,sumStr2=DEFAULT_VAL;
//    char *str1=this->str;
//    int size1=strSize,size2=cstringLength(str2);
//    if(size1<size2)
//        return 1;
//    else if (size1>size2)
//        return -1;
//    while(*(str1)||*(str2)){
//        if(*(str1)){
//            str1++;
//            sumStr1+=*str1;
//        }
//        if(*(str2)){
//            str2++;
//            sumStr2+=*str2;
//        }
//    }
//    if(sumStr1>sumStr2){
//            return -1;
//
//    }else if(sumStr1<sumStr2){
//        return 1;
//    }else{
//        return 0;
//    }
//}

CustomString CustomString::operator+(const char* other){
        this->append(other);
        return *this;

}
CustomString CustomString::operator+(const CustomString& other){
        this->append(other);
        return *this;
}
CustomString&  CustomString::operator=(const CustomString& other){
        this->setString(other);
        return *this;

}
CustomString&  CustomString::operator=(const char* other){
        this->setString(other);
        return *this;

}
void CustomString::operator*(int x){
    while(x){
          this->display();
          x--;
    }


}

//bool operator+=(const CustomString& other);
//bool operator==(const CustomString& other)const;
//bool operator!=(const CustomString& other)const;
//bool operator>(const CustomString& other)const;
//bool operator<(const CustomString& other)const;
//bool operator>=(const CustomString& other)const;
//bool operator<=(const CustomString& other)const;
//friend std::ostream& operator<<(std::ostream& os, const CustomString& c);
//friend std::istream& operator>>(std::istream& is, CustomString& c);

                                            //write access
//char& operator[](int index);
                                            //read only access
//const char& operator[](int index) const;
CustomString::~CustomString(){
    delete(str);
}

