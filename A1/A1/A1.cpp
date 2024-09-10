#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>   
#include "Header2.h"
using namespace std;

int main() {
    int OneD[Input_Size]; //name of array and space inside
    int size = 0; // Current size of the array, starting from 0 since nothing inside yet

    // Read data from the input file
    ReadFile("A1input.txt", OneD, size);

    // characters/integers that will determine our inputs answer
    int c, index, value; 

    //Menu asking what of the following you'd want to do
    while (true) {
        cout << "1. Check an integer\n";
        cout << "2. Modify a value\n";
        cout << "3. Add a new integer\n";
        cout << "4. Remove/0 an integer\n";
        cout << "5. Exit\n";
        cout << "Enter a number between 1 and 5: "; 
        cin >> c;
        cout << endl;

        //Checked on a case statement, checking if anything could be wrong
        //if right, they're sent to the functions defined in Header2.h
        try {
            switch (c) {
            case 1:
                cout << "Enter integer to find/check: ";
                cin >> value;

                index = FindIndex(OneD, size, value);
                if (index != -1) {
                    cout << "Integer exist, found at index: " << index << endl;
                }
                else {
                    cout << "Integer does not exist" << endl;
                }
                break;

            case 2:
                cout << "Enter index(placement) to modify: ";
                cin >> index;

                if (index >= 0 && index < size) {
                    cout << "Enter new value: ";
                    cin >> value;
                    ModVal(OneD, size, index, value);
                }
                else {
                    throw IndexOutOfBoundsException();
                    //if the index far exceed or lower than the array size
                }
                break;

            case 3:
                if (size < Input_Size) {
                    cout << "Enter value to add: ";
                    cin >> value;
                    AddVal(OneD, size, value);
                }
                else {
                    throw ArrayFullException();
                    //If all the spots of an array is filled, meaning no more can be added in
                }
                break;

            case 4:
                cout << "Enter index to remove or zero: ";
                cin >> index;

                if (index >= 0 && index < size) {
                    cout << "Enter 0 to zero, 1 to remove: ";
                    int option;
                    cin >> option;
                    if (option == 0) {
                        OneD[index] = 0;
                        cout << "Value at index " << index << " set to 0." << endl;
                    }
                    else if (option == 1) {
                        RemoveVal(OneD, size, index);
                    }
                    else {
                        cout << "Must choose 0 or 1!" << endl;
                    }
                }
                else {
                    throw IndexOutOfBoundsException();
                    //if not a possible index is chosen.
                }
                break;

            case 5:
                return 0;

            default:
                cout << "Please enter a number between 1 and 5." << endl;
                break;
                //if a number is chosen outside of 1 to 5
            }
        }
        catch (const IndexOutOfBoundsException& e) {
            cout << e.what() << endl;
        }
        catch (const ArrayFullException& e) {
            cout << e.what() << endl;
        }
        catch (const exception& e) {
            cout << "An unexpected error occurred: " << e.what() << endl;
        }
        //still an error if a char is chosen.
    }
    return 0;
}

