#include "binaryTree.h"

// Implement the following methods listed below.
// You don't need to implement the other methods.
// If you decide to implement the other methods,
// DON'T INCLUDE THEM IN YOUR SUBMISSION.
//
// In your implementations, you can call any other
// methods, even those you don't need to implement.

BinaryTree::node *BinaryTree::copyAll(const BinaryTree::node *n){
    if (root){
        root->left = copyAll(root->left);
        root->right = copyAll(root->right);
        return root;
    }
    else
        return nullptr;
}

unsigned int BinaryTree::count(BinaryTree::node *n){
    if (root)
        return 1+count(root->left)+ count(root->right);
    else
        return 0;
}

bool BinaryTree::isSorted(BinaryTree::node *n){
    if (root)
        return isSorted(root->left)&& isSorted(root->left);
    else
        return true;
}

BinaryTree &BinaryTree::operator=(const BinaryTree &bt){
   removeAll();
   copyAll(bt.root);
    return *this;
}

unsigned int BinaryTree::count(){
    return count(root);
}

bool BinaryTree::isSorted(){
    return isSorted(root);
}
