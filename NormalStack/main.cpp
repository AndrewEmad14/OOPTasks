#include <iostream>
#include "Stack.h"
using namespace std;

void testConstructors();
void testPushPop();
void testOperators();
void testBoundaryConditions();
void testEdgeCases();
void printTestResult(const string& testName, bool passed);

int main() {
    cout << "========== STACK BLACK BOX TESTING ==========\n\n";

    testConstructors();
    testPushPop();
    testOperators();
    testBoundaryConditions();
    testEdgeCases();

    cout << "\n========== TESTING COMPLETE ==========\n";
    return 0;
}

void printTestResult(const string& testName, bool passed) {
    cout << testName << ": " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

void testConstructors() {
    cout << "--- Testing Constructors ---\n";

    // Test 1: Default constructor
    Stack s1;
    printTestResult("Default constructor", s1.getStackSize() == 0);

    // Test 2: Parameterized constructor
    int arr[] = {1, 2, 3, 4, 5};
    Stack s2(arr, 5);
    bool test2 = (s2.getStackSize() == 5) && (s2.getElementAt(0) == 1) && (s2.getElementAt(4) == 5);
    printTestResult("Parameterized constructor", test2);

    // Test 3: Copy constructor
    Stack s3(s2);
    bool test3 = (s3.getStackSize() == 5) && (s3.getElementAt(0) == 1);
    printTestResult("Copy constructor", test3);

    // Test 4: Constructor with NULL pointer
    Stack s4(nullptr, 0);
    printTestResult("Constructor with nullptr", s4.getStackSize() == 0);

    cout << endl;
}

void testPushPop() {
    cout << "--- Testing Push and Pop ---\n";

    // Test 1: Push single element
    Stack s1;
    bool test1 = s1.pushBack(10) && (s1.getStackSize() == 1) && (s1.getElementAt(0) == 10);
    printTestResult("Push single element", test1);

    // Test 2: Push multiple elements
    Stack s2;
    s2.pushBack(1);
    s2.pushBack(2);
    s2.pushBack(3);
    bool test2 = (s2.getStackSize() == 3) && (s2.getElementAt(2) == 3);
    printTestResult("Push multiple elements", test2);

    // Test 3: Pop from non-empty stack
    int arr[] = {10, 20, 30};
    Stack s3(arr, 3);
    int popped = 0;
    bool result = s3.pop(popped);
    bool test3 = (popped == 30) && (s3.getStackSize() == 2);
    printTestResult("Pop from non-empty stack", test3);

    // Test 4: Pop from empty stack
    Stack s4;
     result = s4.pop(popped);
    printTestResult("Pop from empty stack returns error value", result == -1 || s4.getStackSize() < 0);

    // Test 5: Push and pop sequence
    Stack s5;
    s5.pushBack(100);
    s5.pushBack(200);
    int val1 = 0;
    s5.pop(val1);
    int val2 = 0;
    s5.pop(val2);
    bool test5 = (val1 == 200) && (val2 == 100) && (s5.getStackSize() == 0);
    printTestResult("Push-pop sequence (LIFO)", test5);

    cout << endl;
}

void testOperators() {
    cout << "--- Testing Operators ---\n";

    // Test 1: Assignment operator
    int arr[] = {1, 2, 3};
    Stack s1(arr, 3);
    Stack s2;
    s2 = s1;
    bool test1 = (s2.getStackSize() == 3) && (s2.getElementAt(0) == 1) && (s2.getElementAt(2) == 3);
    printTestResult("Assignment operator", test1);

    // Test 2: Self-assignment
    Stack s3(arr, 3);
    s3 = s3;
    bool test2 = (s3.getStackSize() == 3) && (s3.getElementAt(0) == 1);
    printTestResult("Self-assignment", test2);

    // Test 3: Index operator (read)
    Stack s4(arr, 3);
    bool test3 = (s4[0] == 1) && (s4[1] == 2) && (s4[2] == 3);
    printTestResult("Index operator (read)", test3);

    // Test 4: Index operator (write)
    Stack s5(arr, 3);
    s5[1] = 99;
    bool test4 = (s5[1] == 99);
    printTestResult("Index operator (write)", test4);

    cout << endl;
}

void testBoundaryConditions() {
    cout << "--- Testing Boundary Conditions ---\n";

    // Test 1: Access first element
    int arr[] = {10, 20, 30};
    Stack s1(arr, 3);
    printTestResult("Access first element", s1.getElementAt(0) == 10);

    // Test 2: Access last element
    printTestResult("Access last element", s1.getElementAt(2) == 30);

    // Test 3: Access out of bounds (negative index)
    int result1 = s1.getElementAt(-1);
    printTestResult("Negative index handling", true); // Should not crash

    // Test 4: Access out of bounds (too large)
    int result2 = s1.getElementAt(100);
    printTestResult("Large index handling", true); // Should not crash

    // Test 5: Empty stack operations
    Stack s2;
    bool test5 = (s2.getStackSize() == 0);
    printTestResult("Empty stack size", test5);

    cout << endl;
}

void testEdgeCases() {
    cout << "--- Testing Edge Cases ---\n";

    // Test 1: Large stack
    Stack s1;
    for(int i = 0; i < 1000; i++) {
        s1.pushBack(i);
    }
    bool test1 = (s1.getStackSize() == 1000) && (s1.getElementAt(999) == 999);
    printTestResult("Large stack (1000 elements)", test1);

    // Test 2: Push then pop all
    int test=0;
    Stack s2;
    s2.pushBack(1);
    s2.pushBack(2);
    s2.pushBack(3);
    s2.pop(test);
    s2.pop(test);
    s2.pop(test);
    printTestResult("Pop all elements", s2.getStackSize() == 0);

    // Test 3: Reuse stack after clearing
    s2.pushBack(100);
    printTestResult("Reuse after clearing", s2.getStackSize() == 1 && s2.getElementAt(0) == 100);

    // Test 4: SetStack method
    int newArr[] = {5, 6, 7};
    Stack s3;
    s3.setStack(newArr, 3);
    bool test4 = (s3.getStackSize() == 3) && (s3.getElementAt(1) == 6);
    printTestResult("SetStack method", test4);

    // Test 5: Copy then modify
    int arr[] = {1, 2, 3};
    Stack s4(arr, 3);
    Stack s5(s4);
    s5.pushBack(4);
    bool test5 = (s4.getStackSize() == 3) && (s5.getStackSize() == 4);
    printTestResult("Deep copy verification", test5);

    // Test 6: Chained assignment
    Stack s6, s7, s8;
    int data[] = {10, 20};
    s6.setStack(data, 2);
    s7 = s8 = s6;
    bool test6 = (s7.getStackSize() == 2) && (s8.getStackSize() == 2);
    printTestResult("Chained assignment", test6);

    // Test 7: Destructor test (create and destroy)
    {
        Stack temp;
        for(int i = 0; i < 100; i++) {
            temp.pushBack(i);
        }
    } // temp goes out of scope here
    printTestResult("Destructor (no crash)", true);

    cout << endl;
}
