#include "CustomString.h"
#include <iostream>
#include <sstream>
using namespace std;

void printTestResult(const char* testName, bool passed) {
    cout << testName << ": " << (passed ? "PASSED" : "FAILED") << endl;
}

int main() {
    cout << "=== CustomString Black Box Testing ===" << endl << endl;

    // Test 1: Default Constructor
    {
        CustomString s1;
        bool passed = (s1.getSize() == 0);
        printTestResult("Test 1 - Default Constructor", passed);
    }

    // Test 2: Parameterized Constructor
    {
        CustomString s2("Hello");
        bool passed = (s2.getSize() == 5);
        printTestResult("Test 2 - Parameterized Constructor", passed);
    }

    // Test 3: Copy Constructor
    {
        CustomString s3("World");
        CustomString s4(s3);
        bool passed = (s4.getSize() == 5 && s4 == s3);
        printTestResult("Test 3 - Copy Constructor", passed);
    }

    // Test 4: setString with C-string
    {
        CustomString s5;
        s5.setString("Test");
        bool passed = (s5.getSize() == 4);
        printTestResult("Test 4 - setString(const char*)", passed);
    }

    // Test 5: setString with CustomString
    {
        CustomString s6("Original");
        CustomString s7;
        s7.setString(s6);
        bool passed = (s7.getSize() == 8 && s7 == s6);
        printTestResult("Test 5 - setString(const CustomString&)", passed);
    }

    // Test 6: getString
    {
        CustomString s8("Data");
        char* str = s8.getString();
        bool passed = (str != nullptr && str[0] == 'D');
        printTestResult("Test 6 - getString()", passed);
    }

    // Test 7: getSize
    {
        CustomString s9("Testing");
        bool passed = (s9.getSize() == 7);
        printTestResult("Test 7 - getSize()", passed);
    }

    // Test 8: toLower
    {
        CustomString s10("UPPER");
        s10.toLower();
        bool passed = (s10 == "upper");
        printTestResult("Test 8 - toLower()", passed);
    }

    // Test 9: toUpper
    {
        CustomString s11("lower");
        s11.toUpper();
        bool passed = (s11 == "LOWER");
        printTestResult("Test 9 - toUpper()", passed);
    }

    // Test 10: append with C-string
    {
        CustomString s12("Hello");
        s12.append(" World");
        bool passed = (s12 == "Hello World");
        printTestResult("Test 10 - append(const char[])", passed);
    }

    // Test 11: append with CustomString
    {
        CustomString s13("Hello");
        CustomString s14(" C++");
        s13.append(s14);
        bool passed = (s13 == "Hello C++");
        printTestResult("Test 11 - append(const CustomString&)", passed);
    }

    // Test 12: strCompare with C-string (equal)
    {
        CustomString s15("abc");
        bool passed = (s15.strCompare("abc") == 0);
        printTestResult("Test 12 - strCompare equal (C-string)", passed);
    }

    // Test 13: strCompare with C-string (less than)
    {
        CustomString s16("abc");
        bool passed = (s16.strCompare("xyz") < 0);
        printTestResult("Test 13 - strCompare less than (C-string)", passed);
    }

    // Test 14: strCompare with C-string (greater than)
    {
        CustomString s17("xyz");
        bool passed = (s17.strCompare("abc") > 0);
        printTestResult("Test 14 - strCompare greater than (C-string)", passed);
    }

    // Test 15: strCompare with CustomString
    {
        CustomString s18("test");
        CustomString s19("test");
        bool passed = (s18.strCompare(s19) == 0);
        printTestResult("Test 15 - strCompare(const CustomString&)", passed);
    }

    // Test 16: Assignment operator with C-string
    {
        CustomString s20;
        s20 = "Assigned";
        bool passed = (s20 == "Assigned");
        printTestResult("Test 16 - operator=(const char*)", passed);
    }

    // Test 17: Assignment operator with CustomString
    {
        CustomString s21("Source");
        CustomString s22;
        s22 = s21;
        bool passed = (s22 == s21);
        printTestResult("Test 17 - operator=(const CustomString&)", passed);
    }

    // Test 18: Addition operator with CustomString
    {
        CustomString s23("Hello");
        CustomString s24(" World");
        CustomString s25 = s23 + s24;
        bool passed = (s25 == "Hello World");
        printTestResult("Test 18 - operator+(const CustomString&)", passed);
    }

    // Test 19: Addition operator with C-string
    {
        CustomString s26("Hello");
        CustomString s27 = s26 + " C++";
        bool passed = (s27 == "Hello C++");
        printTestResult("Test 19 - operator+(const char*)", passed);
    }

    // Test 20: Multiply operator (print n times)
    {
        cout << "Test 20 - operator*(int) - Manual Check: ";
        CustomString s28("*");
        s28 * 5;
        cout << " (Should print: * * * * *)" << endl;
    }

    // Test 21: += operator
    {
        CustomString s29("Start");
        CustomString s30(" End");
        s29 += s30;
        bool passed = (s29 == "Start End");
        printTestResult("Test 21 - operator+=(const CustomString&)", passed);
    }

    // Test 22: == operator with CustomString
    {
        CustomString s31("equal");
        CustomString s32("equal");
        bool passed = (s31 == s32);
        printTestResult("Test 22 - operator==(const CustomString&)", passed);
    }

    // Test 23: != operator with CustomString
    {
        CustomString s33("first");
        CustomString s34("second");
        bool passed = (s33 != s34);
        printTestResult("Test 23 - operator!=(const CustomString&)", passed);
    }

    // Test 24: > operator with CustomString
    {
        CustomString s35("xyz");
        CustomString s36("abc");
        bool passed = (s35 > s36);
        printTestResult("Test 24 - operator>(const CustomString&)", passed);
    }

    // Test 25: < operator with CustomString
    {
        CustomString s37("abc");
        CustomString s38("xyz");
        bool passed = (s37 < s38);
        printTestResult("Test 25 - operator<(const CustomString&)", passed);
    }

    // Test 26: >= operator with CustomString
    {
        CustomString s39("xyz");
        CustomString s40("abc");
        bool passed = (s39 >= s40);
        printTestResult("Test 26 - operator>=(const CustomString&)", passed);
    }

    // Test 27: <= operator with CustomString
    {
        CustomString s41("abc");
        CustomString s42("xyz");
        bool passed = (s41 <= s42);
        printTestResult("Test 27 - operator<=(const CustomString&)", passed);
    }

    // Test 28: == operator with C-string
    {
        CustomString s43("match");
        bool passed = (s43 == "match");
        printTestResult("Test 28 - operator==(const char[])", passed);
    }

    // Test 29: != operator with C-string
    {
        CustomString s44("one");
        bool passed = (s44 != "two");
        printTestResult("Test 29 - operator!=(const char[])", passed);
    }

    // Test 30: > operator with C-string
    {
        CustomString s45("xyz");
        bool passed = (s45 > "abc");
        printTestResult("Test 30 - operator>(const char[])", passed);
    }

    // Test 31: < operator with C-string
    {
        CustomString s46("abc");
        bool passed = (s46 < "xyz");
        printTestResult("Test 31 - operator<(const char[])", passed);
    }

    // Test 32: >= operator with C-string
    {
        CustomString s47("xyz");
        bool passed = (s47 >= "abc");
        printTestResult("Test 32 - operator>=(const char[])", passed);
    }

    // Test 33: <= operator with C-string
    {
        CustomString s48("abc");
        bool passed = (s48 <= "xyz");
        printTestResult("Test 33 - operator<=(const char[])", passed);
    }

    // Test 34: << operator (output stream)
    {
        cout << "Test 34 - operator<<(ostream&) - Manual Check: ";
        CustomString s49("Output Test");
        cout << s49 << " (Should print: Output Test)" << endl;
    }

    // Test 35: >> operator (input stream)
    {
        cout << "Test 35 - operator>>(istream&) - Manual input test" << endl;
        cout << "Enter a word: ";
        CustomString s50;
        cin >> s50;
        cout << "You entered: " << s50 << endl;
    }

    // Test 36: [] operator write access
    {
        CustomString s51("test");
        s51[0] = 'b';
        bool passed = (s51 == "best");
        printTestResult("Test 36 - operator[](int) write access", passed);
    }

    // Test 37: [] operator read access
    {
        CustomString s52("read");
        bool passed = (s52[0] == 'r' && s52[1] == 'e');
        printTestResult("Test 37 - operator[](int) read access", passed);
    }

    // Test 38: Static cstringLength
    {
        int len = CustomString::cstringLength("length");
        bool passed = (len == 6);
        printTestResult("Test 38 - cstringLength(const char*)", passed);
    }


    // Test 40: Static strCopy
    {
        char dest[10];
        char src[] = "copy";
        bool result = CustomString::strCopy(dest, src, 5);
        bool passed = (result && dest[0] == 'c' && dest[1] == 'o');
        printTestResult("Test 40 - strCopy(char[], char[], int)", passed);
    }

    // Test 41: display method
    {
        cout << "Test 41 - display() - Manual Check: ";
        CustomString s54("Display Test");
        s54.display();
        cout << " (Should print: Display Test)" << endl;
    }

    cout << endl << "=== EDGE CASE & INVALID INPUT TESTS ===" << endl << endl;

    // Test 42: Constructor with nullptr
    {
        CustomString s55(nullptr);
        bool passed = (s55.getSize() == 0);
        printTestResult("Test 42 - Constructor with nullptr", passed);
    }

    // Test 43: setString with nullptr
    {
        CustomString s56("Valid");
        s56.setString(nullptr);
        bool passed = (s56.getSize() == 0);
        printTestResult("Test 43 - setString with nullptr", passed);
    }

    // Test 44: append nullptr C-string
    {
        CustomString s57("Start");
        bool result = s57.append((const char*)nullptr);
        bool passed = (s57 == "Start" && !result);
        printTestResult("Test 44 - append nullptr C-string", passed);
    }

    // Test 45: Empty string constructor
    {
        CustomString s58("");
        bool passed = (s58.getSize() == 0);
        printTestResult("Test 45 - Constructor with empty string", passed);
    }

    // Test 46: setString with empty string
    {
        CustomString s59("NonEmpty");
        s59.setString("");
        bool passed = (s59.getSize() == 0);
        printTestResult("Test 46 - setString with empty string", passed);
    }

    // Test 47: append empty string
    {
        CustomString s60("Text");
        s60.append("");
        bool passed = (s60 == "Text" && s60.getSize() == 4);
        printTestResult("Test 47 - append empty string", passed);
    }

    // Test 48: Compare with nullptr
    {
        CustomString s61("test");
        int result = s61.strCompare(nullptr);
        bool passed = (result != 0);
        printTestResult("Test 48 - strCompare with nullptr", passed);
    }

    // Test 49: Empty string comparison
    {
        CustomString s62("");
        CustomString s63("");
        bool passed = (s62 == s63);
        printTestResult("Test 49 - Compare two empty strings", passed);
    }

    // Test 51: Copy constructor from empty string
    {
        CustomString s65("");
        CustomString s66(s65);
        bool passed = (s66.getSize() == 0);
        printTestResult("Test 51 - Copy constructor from empty", passed);
    }

    // Test 52: Addition with empty string
    {
        CustomString s67("Text");
        CustomString s68("");
        CustomString s69 = s67 + s68;
        bool passed = (s69 == "Text");
        printTestResult("Test 52 - Addition with empty string", passed);
    }

    // Test 53: toLower on empty string
    {
        CustomString s70("");
        bool result = s70.toLower();
        bool passed = (s70.getSize() == 0);
        printTestResult("Test 53 - toLower on empty string", passed);
    }

    // Test 54: toUpper on empty string
    {
        CustomString s71("");
        bool result = s71.toUpper();
        bool passed = (s71.getSize() == 0);
        printTestResult("Test 54 - toUpper on empty string", passed);
    }

    // Test 55: Array access out of bounds (negative index)
    {
        cout << "Test 55 - Array access negative index - Manual Check: ";
        CustomString s72("test");
        try {
            char c = s72[-1];
            cout << "No bounds checking (accessed: " << c << ")" << endl;
        } catch (...) {
            cout << "PASSED (Exception caught)" << endl;
        }
    }

    // Test 56: Array access out of bounds (beyond size)
    {
        cout << "Test 56 - Array access beyond size - Manual Check: ";
        CustomString s73("test");
        try {
            char c = s73[100];
            cout << "No bounds checking (accessed: " << c << ")" << endl;
        } catch (...) {
            cout << "PASSED (Exception caught)" << endl;
        }
    }

    // Test 57: Multiply by zero
    {
        cout << "Test 57 - operator*(0) - Manual Check: ";
        CustomString s74("Star");
        s74 * 0;
        cout << " (Should print nothing)" << endl;
    }

    // Test 58: Multiply by negative number
    {
        cout << "Test 58 - operator*(-3) - Manual Check: ";
        CustomString s75("Neg");
        s75 * -3;
        cout << " (Should print nothing or handle gracefully)" << endl;
    }

    // Test 59: Very long string
    {
        char longStr[1001];
        for (int i = 0; i < 1000; i++) longStr[i] = 'a';
        longStr[1000] = '\0';
        CustomString s76(longStr);
        bool passed = (s76.getSize() == 1000);
        printTestResult("Test 59 - Very long string (1000 chars)", passed);
    }

    // Test 60: Special characters
    {
        CustomString s77("Hello\nWorld\t!");
        bool passed = (s77.getSize() == 13);
        printTestResult("Test 60 - String with special chars", passed);
    }

    // Test 61: Numbers in string
    {
        CustomString s78("Test123");
        s78.toUpper();
        bool passed = (s78 == "TEST123");
        printTestResult("Test 61 - toUpper with numbers", passed);
    }

    // Test 62: Mixed case toLower
    {
        CustomString s79("HeLLo WoRLd");
        s79.toLower();
        bool passed = (s79 == "hello world");
        printTestResult("Test 62 - toLower mixed case", passed);
    }

    // Test 63: Static cstringLength with nullptr
    {
        int len = CustomString::cstringLength(nullptr);
        bool passed = (len == 0);
        printTestResult("Test 63 - cstringLength with nullptr", passed);
    }

    // Test 64: Static cstringLength with empty string
    {
        int len = CustomString::cstringLength("");
        bool passed = (len == 0);
        printTestResult("Test 64 - cstringLength with empty string", passed);
    }


    // Test 66: Static strCopy with invalid parameters
    {
        bool result = CustomString::strCopy(nullptr, nullptr, 5);
        bool passed = (!result);
        printTestResult("Test 66 - strCopy with nullptr arguments", passed);
    }

    // Test 67: Static strCopy with zero size
    {
        char dest[10], src[] = "test";
        bool result = CustomString::strCopy(dest, src, 0);
        bool passed = (!result);
        printTestResult("Test 67 - strCopy with zero size", passed);
    }

    // Test 68: Comparison operators with empty strings
    {
        CustomString s81("");
        CustomString s82("");
        bool passed = (s81 == s82 && !(s81 < s82) && !(s81 > s82));
        printTestResult("Test 68 - All comparison ops on empty strings", passed);
    }

    // Test 69: += with empty string
    {
        CustomString s83("Base");
        CustomString s84("");
        s83 += s84;
        bool passed = (s83 == "Base");
        printTestResult("Test 69 - operator+= with empty string", passed);
    }

    // Test 70: Chained operations
    {
        CustomString s85("A");
        s85 = s85 + "B" + "C";
        bool passed = (s85 == "ABC");
        printTestResult("Test 70 - Chained addition operations", passed);
    }

    cout << endl << "=== All Testing Complete ===" << endl;

    return 0;
}
