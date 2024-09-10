#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include <stdexcept>
#include <cstdlib> 

const int Input_Size = 200; // additional 100(+1) space to add more

class IndexOutOfBoundsException : public runtime_error {
public:
    IndexOutOfBoundsException() : runtime_error("Out of bounds! Not within range!") {}
};

class ArrayFullException : public runtime_error {
public:
    ArrayFullException() : runtime_error("Array is full, can't handle more!") {}
};
//the runtime error placed here, incase of an event of an error occurs


// function to read data from file into the array
void ReadFile(const char* fname, int OneD[], int& size) {
    ifstream inputFile(fname);
    if (!inputFile) {
        cout << "Error opening file!" << endl;
        exit(1);
    }
    //error incase file cannot be opened for some reason

    int number;
    while (inputFile >> number) {
        if (size < Input_Size) {
            OneD[size++] = number;
        }

        else {
            cout << "Array is over max limit!" << endl;
            exit(1);
            //an error type case
        }

    }

    inputFile.close();
    //always got to close files after used
}

int FindIndex(const int OneD[], int size, int num) {
    for (int i = 0; i < size; ++i) {
        if (OneD[i] == num) {
            return i;//found
        }
        //searches through the array to find the one it was called for
    }

    return -1; // Not found
}

void ModVal(int OneD[], int size, int index, int newValue) {
    if (index >= 0 && index < size) {
        cout << "Old value: " << OneD[index] << endl;
        OneD[index] = newValue;
        cout << "New value: " << OneD[index] << endl;
        cout << endl;
        //returns the old and new value presented
    }

    else {
        throw IndexOutOfBoundsException();
    }

}

void AddVal(int OneD[], int& size, int value) {
    if (size < Input_Size) {
        OneD[size++] = value;
        cout << "Value added at end: " << value << endl;
        cout << endl;
        //adds value and returns
    }

    else {
        throw ArrayFullException();
    }

}

void RemoveVal(int OneD[], int& size, int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; ++i) {
            OneD[i] = OneD[i + 1];
        }
        --size;
        cout << "Value at index " << index << " removed." << endl;
        cout << endl;
        //removes an index if it's chosen rather than 0
    }

    else {
        throw IndexOutOfBoundsException();
    }

}