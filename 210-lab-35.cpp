// COMSC-210 | Lab 35 | Noel Mier-Luna
#include <iostream>
#include <string>
#include <fstream>
#include "StringBinaryTree.h"
using namespace std;

int main() {
    // Create an instance of StringBinaryTree to hold the codes read from the file and user input.
    StringBinaryTree tree;

    // Open codes.txt to read strings into tree.
    ifstream inFile("codes.txt");
    if (!inFile) {
        cerr << "Error opening file." << endl; // Check if file opened successfully
        return 1;
    }
    string code;
    while (inFile >> code) {
        tree.insertNode(code); // Insert each code into the tree
    }
    inFile.close(); // Close the file after reading

    // Display the tree contents using In-order traversal so strings are displayed in non-decreasing order. I prefer saying increasing order.
    cout << "In-order Traversal:" << endl;
    tree.displayInOrder();

    // Main menu that allows user to add, search for, or delete a node in the tree.
    int choice;
    do {
        cout << "\nMain Menu:" << endl;
        cout << "1. Add a code" << endl;
        cout << "2. Search for a code" << endl;
        cout << "3. Delete a code" << endl;
        cout << "4. Display the tree" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice)) // Validate that input is an integer to prevent infinite loop on invalid input
        {
            cout << "Invalid input. Please enter a number: ";
            cin.clear(); // Clear the error flag
            cin.ignore(1000, '\n'); // Discard invalid input.
        }
        switch (choice) {
        case 1:
            // Add a code
            cout << "Enter a code to add: ";
            cin >> code; // Allows user to input a code to add to the tree
            tree.insertNode(code);
            cout << code << " added to the tree." << endl;

            break;
        case 2:
            // Search for a code
            cout << "Enter a code to search for: ";
            cin >> code;
            if (tree.searchNode(code)) // Check if code exists in the tree
            {
                cout << code << " found in the tree." << endl;
            } else {
                cout << code << " not found in the tree." << endl;
            }
            break;
        case 3:
            // Delete a code
            cout << "Enter a code to delete: ";
            cin >> code;
            if (tree.searchNode(code)) // Check if code exists before attempting to delete
            {
                tree.remove(code);
                cout << code << " deleted from the tree." << endl;
            } else {
                cout << code << " not found in the tree." << endl;
            }
            break;
        case 4:
            // Display the tree
            cout << "Tree contents:" << endl;
            tree.displayInOrder();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl; // Handle invalid menu choices
            break;
        }
    } while (choice != 5);

    return 0;
}