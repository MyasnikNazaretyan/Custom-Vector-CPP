#include<iostream>
#include<string>
#include"Vector.hpp"
using namespace std;
int main()
{
    cout << "=== 1. Testing push_back and capacity growth ===" << endl;
    Vector<int> numbers;

    for (int i = 1; i <= 5; ++i) {
        numbers.push_back(i * 10);
        cout << "Added: " << i * 10 
                  << " | Size: " << numbers.get_size() 
                  << " | Capacity: " << numbers.get_capacity() << endl;
    }

    cout << "\n=== 2. Testing operator[] and at() ===" << endl;
    cout << "Element at index 2 (operator[]): " << numbers[2] << endl;
    cout << "Element at index 2 (.at()): " << numbers.at(2) << endl;

    cout << "\n=== 3. Testing Exception Handling (throw / catch) ===" << endl;
    try {
        cout << numbers.at(10) << endl; // 10-րդ ինդեքս չկա
    } catch (const out_of_range& e) {
        cout << "Caught Exception: " << e.what() << endl;
    }

    cout << "\n=== 4. Testing Copy Semantics ===" << endl;
    Vector<int> copy_numbers = numbers; // Deep copy
    copy_numbers[0] = 999;
    cout << "Original numbers[0]: " << numbers[0] << " (Unchanged)" << endl;
    cout << "Copy numbers[0]: " << copy_numbers[0] << " (Updated)" << endl;

    cout << "\n=== 5. Testing Move Semantics with std::string ===" << endl;
    Vector<string> words;
    words.push_back("Varazdat");
    words.push_back("Custom");
    words.push_back("Vector");

    for (size_t i = 0; i < words.get_size(); ++i) {
        cout << words[i] << " ";
    }
    cout << endl;

    return 0;
}