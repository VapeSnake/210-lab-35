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

    // Test searchNode function
    string searchCode = "HotDog";
    if (tree.searchNode(searchCode))
    {
        cout << "\nCode found in the tree." << endl; // Notifies if code/string is found in tree, otherwise says not found.
    }
    else
    {
        cout << "\nCode not found in the tree." << endl;
    }

    // Test remove function
    string removeCode = "zzzvpPa2";
    
    tree.remove(removeCode); // Remove the specified code from the tree
    cout << "\nInorder traversal after removing " << removeCode << ":" << endl;
    tree.displayInOrder(); // Display the tree in inorder after removal

    // Test Insert.
    string newCode = "zzzzNewCode123";
    tree.insertNode(newCode); // Insert the new code into the tree
    cout << "\nInorder traversal after inserting " << newCode << ":" << endl;
    tree.displayInOrder(); // Display the tree in inorder after insertion

    tree.displayPostOrder(); // Display the tree in postorder

    // Features confirmed working: insertNode, searchNode, remove, displayInOrder, displayPreOrder and displayPostOrder.


    return 0;
}