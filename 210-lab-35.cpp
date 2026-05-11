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
    cout << "Preorder traversal of the tree:" << endl;
    tree.displayPreOrder(); // Display the tree in preorder

    cout << "\nInorder traversal of the tree:" << endl;
    tree.displayInOrder(); // Display the tree in inorder

    cout << "\nPostorder traversal of the tree:" << endl;
    tree.displayPostOrder(); // Display the tree in postorder

    return 0;
}