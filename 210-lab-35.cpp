#include <iostream>
#include <string>
#include <fstream>
#include "StringBinaryTree.h"
using namespace std;

int main()
{
    // Test StringBinaryTree class
    StringBinaryTree tree;

    // Open codes.txt to read strings into tree.
    ifstream inFile("codes.txt");
    if (!inFile)
    {
        cerr << "Error opening file." << endl; // Check if file opened successfully
        return 1;
    }
    string code;
    while (inFile >> code)
    {
        tree.insertNode(code); // Insert each code into the tree
    }
    inFile.close(); // Close the file after reading

    // Display the tree contents using In-order traversal so strings are displayed in non-decreasing order. I prefer saying increasing order.
    cout << "In-order Traversal:" << endl;
    tree.displayInOrder();
    



    return 0;
}