#ifndef CUSTOM_STRING_H
#define CUSTOM_STRING_H
#include <iostream>
//length
//compare
//tolower
//toupper
//concat
//copy
//reverse
//display
//<< >> + == >= <= > < overload operators
//

class CustomString{
        char *str=nullptr;
        int  strSize;
        bool strConcatinate(const char str2[]);



    public:
        static int cstringLength(const char*input);
        static CustomString strConcatinate(const char str1[],const char str2[]);
        static CustomString strConcatinate(const CustomString& first,const CustomString& other);
        static CustomString strConcatinate(const CustomString& first,const char str2[]);
        static bool strCopy(char str1[],char str2[],int size_str2);
                                                                            //constructors
        CustomString();
        CustomString(const char* input);
                                                                            //copy constructors

        CustomString(CustomString& other);
                                                                            //setters , getters
        bool  setString(const char*input);
        bool  setString(const CustomString& other);
        char* getString();
        int   getSize();
                                                                            //display
        void  display();
        bool  toLower();
        bool  toUpper();


                                                                            //append
        bool  append(const char str2[]);
        bool  append(const CustomString& other);


                                                                            //compare
        int strCompare(const char str2[])const;
        int strCompare(const CustomString& other)const;

                                                                            //overloading



                                                                            //assignment

        CustomString& operator=(const char* other);
        CustomString& operator=(const CustomString& other);
                                                                            //append

        CustomString operator+(const CustomString& other);
        CustomString operator+(const char* other);
                                                                            //print times x

        void operator*(int x);

                                                                            //assigment and append
        CustomString& operator+=(const CustomString& other);

        bool operator==(const CustomString& other)const;
        bool operator!=(const CustomString& other)const;
        bool operator>(const CustomString& other)const;
        bool operator<(const CustomString& other)const;
        bool operator>=(const CustomString& other)const;
        bool operator<=(const CustomString& other)const;
        bool operator==(const char str2[])const;
        bool operator!=(const char str2[])const;
        bool operator>(const char str2[])const;
        bool operator<(const char str2[])const;
        bool operator>=(const char str2[])const;
        bool operator<=(const char str2[])const;
        friend std::ostream& operator<<(std::ostream& os, const CustomString& c);
        friend std::istream& operator>>(std::istream& is, CustomString& c);

                                                    //write access
        char& operator[](int index);
                                                    //read only access
        const char& operator[](int index) const;
        ~CustomString();
};

#endif

