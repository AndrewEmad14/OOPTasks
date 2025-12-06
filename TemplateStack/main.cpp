#include "TemplateStack.h"
#include <iostream>
#include <string>
using namespace std;

void printTestResult(const char* testName, bool passed) {
    cout << testName << ": " << (passed ? "PASSED" : "FAILED") << endl;
}

int main() {
    cout << "=== TemplateStack Black Box Testing ===" << endl << endl;

    // ========== INTEGER STACK TESTS ==========
    cout << "--- INTEGER STACK TESTS ---" << endl;

    // Test 1: Default Constructor (int)
    {
        TemplateStack<int> s1;
        bool passed = (s1.getStackSize() == 0);
        printTestResult("Test 1 - Default Constructor (int)", passed);
    }

    // Test 2: Parameterized Constructor (int)
    {
        int arr[] = {1, 2, 3, 4, 5};
        TemplateStack<int> s2(arr, 5);
        bool passed = (s2.getStackSize() == 5);
        printTestResult("Test 2 - Parameterized Constructor (int)", passed);
    }

    // Test 3: Copy Constructor (int)
    {
        int arr[] = {10, 20, 30};
        TemplateStack<int> s3(arr, 3);
        TemplateStack<int> s4(s3);
        bool passed = (s4.getStackSize() == 3 && s4.getElementAt(0) == 10);
        printTestResult("Test 3 - Copy Constructor (int)", passed);
    }

    // Test 4: Assignment Operator (int)
    {
        int arr[] = {5, 10, 15};
        TemplateStack<int> s5(arr, 3);
        TemplateStack<int> s6;
        s6 = s5;
        bool passed = (s6.getStackSize() == 3 && s6.getElementAt(1) == 10);
        printTestResult("Test 4 - Assignment Operator (int)", passed);
    }

    // Test 5: setStack with array (int)
    {
        TemplateStack<int> s7;
        int arr[] = {100, 200, 300};
        bool result = s7.setStack(arr, 3);
        bool passed = (result && s7.getStackSize() == 3 && s7.getElementAt(0) == 100);
        printTestResult("Test 5 - setStack with array (int)", passed);
    }

    // Test 6: setStack with another stack (int)
    {
        int arr[] = {7, 8, 9};
        TemplateStack<int> s8(arr, 3);
        TemplateStack<int> s9;
        bool result = s9.setStack(s8);
        bool passed = (result && s9.getStackSize() == 3 && s9.getElementAt(2) == 9);
        printTestResult("Test 6 - setStack with stack (int)", passed);
    }

    // Test 7: getStackSize (int)
    {
        int arr[] = {1, 2, 3, 4};
        TemplateStack<int> s10(arr, 4);
        bool passed = (s10.getStackSize() == 4);
        printTestResult("Test 7 - getStackSize (int)", passed);
    }

    // Test 8: getElementAt (int)
    {
        int arr[] = {11, 22, 33, 44};
        TemplateStack<int> s11(arr, 4);
        bool passed = (s11.getElementAt(0) == 11 && s11.getElementAt(3) == 44);
        printTestResult("Test 8 - getElementAt (int)", passed);
    }

    // Test 9: pushBack (int)
    {
        TemplateStack<int> s12;
        s12.pushBack(100);
        s12.pushBack(200);
        bool passed = (s12.getStackSize() == 2 && s12.getElementAt(0) == 100);
        printTestResult("Test 9 - pushBack (int)", passed);
    }

    // Test 10: pushBack when full (auto-resize) (int)
    {
        int arr[] = {1, 2, 3};
        TemplateStack<int> s13(arr, 3);
        s13.pushBack(4);
        bool passed = (s13.getStackSize() == 4 && s13.getElementAt(3) == 4);
        printTestResult("Test 10 - pushBack auto-resize (int)", passed);
    }

    // Test 11: pop (int)
    {
        int arr[] = {10, 20, 30};
        TemplateStack<int> s14(arr, 3);
        int value;
        bool result = s14.pop(value);
        bool passed = (result && value == 30 && s14.getStackSize() == 2);
        printTestResult("Test 11 - pop (int)", passed);
    }

    // Test 12: pop from empty stack (int)
    {
        TemplateStack<int> s15;
        int value;
        bool result = s15.pop(value);
        bool passed = (!result);
        printTestResult("Test 12 - pop from empty (int)", passed);
    }

    // Test 13: operator[] read (int)
    {
        int arr[] = {5, 15, 25};
        TemplateStack<int> s16(arr, 3);
        bool passed = (s16[0] == 5 && s16[2] == 25);
        printTestResult("Test 13 - operator[] read (int)", passed);
    }

    // Test 14: operator[] write (int)
    {
        int arr[] = {1, 2, 3};
        TemplateStack<int> s17(arr, 3);
        s17[1] = 99;
        bool passed = (s17[1] == 99);
        printTestResult("Test 14 - operator[] write (int)", passed);
    }

    // ========== DOUBLE STACK TESTS ==========
    cout << endl << "--- DOUBLE STACK TESTS ---" << endl;

    // Test 15: Constructor and operations (double)
    {
        double arr[] = {1.1, 2.2, 3.3};
        TemplateStack<double> s18(arr, 3);
        bool passed = (s18.getStackSize() == 3 && s18.getElementAt(1) == 2.2);
        printTestResult("Test 15 - Constructor (double)", passed);
    }

    // Test 16: pushBack and pop (double)
    {
        TemplateStack<double> s19;
        s19.pushBack(3.14);
        s19.pushBack(2.71);
        double value;
        s19.pop(value);
        bool passed = (value == 2.71 && s19.getStackSize() == 1);
        printTestResult("Test 16 - pushBack/pop (double)", passed);
    }

    // Test 17: Copy constructor (double)
    {
        double arr[] = {1.5, 2.5, 3.5};
        TemplateStack<double> s20(arr, 3);
        TemplateStack<double> s21(s20);
        bool passed = (s21.getElementAt(2) == 3.5);
        printTestResult("Test 17 - Copy constructor (double)", passed);
    }

    // ========== CHAR STACK TESTS ==========
    cout << endl << "--- CHAR STACK TESTS ---" << endl;

    // Test 18: Constructor and operations (char)
    {
        char arr[] = {'a', 'b', 'c'};
        TemplateStack<char> s22(arr, 3);
        bool passed = (s22.getStackSize() == 3 && s22.getElementAt(0) == 'a');
        printTestResult("Test 18 - Constructor (char)", passed);
    }

    // Test 19: pushBack and pop (char)
    {
        TemplateStack<char> s23;
        s23.pushBack('X');
        s23.pushBack('Y');
        s23.pushBack('Z');
        char value;
        s23.pop(value);
        bool passed = (value == 'Z' && s23.getStackSize() == 2);
        printTestResult("Test 19 - pushBack/pop (char)", passed);
    }

    // Test 20: Assignment operator (char)
    {
        char arr[] = {'h', 'e', 'l', 'l', 'o'};
        TemplateStack<char> s24(arr, 5);
        TemplateStack<char> s25;
        s25 = s24;
        bool passed = (s25.getStackSize() == 5 && s25[4] == 'o');
        printTestResult("Test 20 - Assignment operator (char)", passed);
    }

    // ========== STRING STACK TESTS ==========
    cout << endl << "--- STRING STACK TESTS ---" << endl;

    // Test 21: Constructor and operations (string)
    {
        string arr[] = {"hello", "world", "test"};
        TemplateStack<string> s26(arr, 3);
        bool passed = (s26.getStackSize() == 3 && s26.getElementAt(1) == "world");
        printTestResult("Test 21 - Constructor (string)", passed);
    }

    // Test 22: pushBack and pop (string)
    {
        TemplateStack<string> s27;
        s27.pushBack("first");
        s27.pushBack("second");
        string value;
        s27.pop(value);
        bool passed = (value == "second" && s27.getStackSize() == 1);
        printTestResult("Test 22 - pushBack/pop (string)", passed);
    }

    // ========== EDGE CASE TESTS ==========
    cout << endl << "--- EDGE CASE TESTS ---" << endl;

    // Test 23: setStack with nullptr (int)
    {
        TemplateStack<int> s28;
        bool result = s28.setStack(nullptr, 5);
        bool passed = (!result && s28.getStackSize() == 0);
        printTestResult("Test 23 - setStack with nullptr", passed);
    }

    // Test 24: Multiple pops until empty (int)
    {
        int arr[] = {1, 2};
        TemplateStack<int> s29(arr, 2);
        int value;
        s29.pop(value);
        s29.pop(value);
        bool result = s29.pop(value);
        bool passed = (!result && s29.getStackSize() == 0);
        printTestResult("Test 24 - Pop until empty", passed);
    }

    // Test 25: Self-assignment (int)
    {
        int arr[] = {10, 20, 30};
        TemplateStack<int> s30(arr, 3);
        s30 = s30;
        bool passed = (s30.getStackSize() == 3 && s30.getElementAt(1) == 20);
        printTestResult("Test 25 - Self assignment", passed);
    }

    // Test 26: getElementAt out of bounds
    {
        cout << "Test 26 - getElementAt out of bounds: ";
        int arr[] = {1, 2, 3};
        TemplateStack<int> s31(arr, 3);
        try {
            int val = s31.getElementAt(10);
            cout << "FAILED (no exception)" << endl;
        } catch (const out_of_range& e) {
            cout << "PASSED (exception caught)" << endl;
        }
    }

    // Test 27: operator[] out of bounds
    {
        cout << "Test 27 - operator[] out of bounds: ";
        int arr[] = {1, 2, 3};
        TemplateStack<int> s32(arr, 3);
        try {
            int val = s32[10];
            cout << "FAILED (no exception)" << endl;
        } catch (const out_of_range& e) {
            cout << "PASSED (exception caught)" << endl;
        }
    }

    // Test 28: Large stack (int)
    {
        int largeArr[100];
        for (int i = 0; i < 100; i++) largeArr[i] = i;
        TemplateStack<int> s33(largeArr, 100);
        bool passed = (s33.getStackSize() == 100 && s33.getElementAt(99) == 99);
        printTestResult("Test 28 - Large stack (100 elements)", passed);
    }

    // Test 29: Multiple pushBack operations (int)
    {
        TemplateStack<int> s34;
        for (int i = 0; i < 10; i++) {
            s34.pushBack(i * 10);
        }
        bool passed = (s34.getStackSize() == 10 && s34.getElementAt(9) == 90);
        printTestResult("Test 29 - Multiple pushBack (10 times)", passed);
    }

    // Test 30: Pop all elements (int)
    {
        int arr[] = {1, 2, 3, 4, 5};
        TemplateStack<int> s35(arr, 5);
        int value;
        int count = 0;
        while (s35.pop(value)) {
            count++;
        }
        bool passed = (count == 5 && s35.getStackSize() == 0);
        printTestResult("Test 30 - Pop all elements", passed);
    }

    // Test 31: Copy then modify original (int)
    {
        int arr[] = {1, 2, 3};
        TemplateStack<int> s36(arr, 3);
        TemplateStack<int> s37(s36);
        s36[0] = 999;
        bool passed = (s36[0] == 999 && s37[0] == 1);
        printTestResult("Test 31 - Copy independence", passed);
    }

    // Test 32: Assign then modify (int)
    {
        int arr[] = {10, 20, 30};
        TemplateStack<int> s38(arr, 3);
        TemplateStack<int> s39;
        s39 = s38;
        s38.pushBack(40);
        bool passed = (s38.getStackSize() == 4 && s39.getStackSize() == 3);
        printTestResult("Test 32 - Assignment independence", passed);
    }

    // Test 33: Mixed operations (int)
    {
        TemplateStack<int> s40;
        s40.pushBack(10);
        s40.pushBack(20);
        s40.pushBack(30);
        int val;
        s40.pop(val);
        s40.pushBack(40);
        s40.pushBack(50);
        bool passed = (s40.getStackSize() == 4 && s40[3] == 50);
        printTestResult("Test 33 - Mixed push/pop operations", passed);
    }

    // Test 34: setStack replaces existing data (int)
    {
        int arr1[] = {1, 2, 3};
        int arr2[] = {10, 20};
        TemplateStack<int> s41(arr1, 3);
        s41.setStack(arr2, 2);
        bool passed = (s41.getStackSize() == 2 && s41.getElementAt(0) == 10);
        printTestResult("Test 34 - setStack replaces data", passed);
    }

    // Test 35: Empty stack operations (double)
    {
        TemplateStack<double> s42;
        bool passed = (s42.getStackSize() == 0);
        double val;
        bool popResult = s42.pop(val);
        passed = passed && !popResult;
        printTestResult("Test 35 - Empty stack operations", passed);
    }

    cout << endl << "=== All Testing Complete ===" << endl;

    return 0;
}
