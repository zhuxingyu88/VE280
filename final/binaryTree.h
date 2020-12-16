#ifndef BST_H
#define BST_H

#include <cstddef> // for definition of NULL

// DON'T MODIFY THIS HEADER FILE

// Instances of node are dynamically allocated
class BinaryTree{
   struct node{
      int v;
      node *left; // All nodes are dynamically allocated
      node *right; // All nodes are dynamically allocated
   };
   node *root; // All nodes are dynamically allocated
   node *copyAll(const node *n); // TODO
   // REQUIRES: root to be NULL
   // MODIFIES: this
   // EFFECTS: returns a pointer to a new tree, which is
   //          a deep copy of the tree pointed by n
   void removeAll(node *n);
   // MODIFIES: n
   // EFFECTS: delete all the nodes in the tree pointed
   //          by n
   unsigned int count(node *n); // TODO
   // EFFECTS: returns the total number of nodes
   bool isSorted(node *n); // TODO
   // EFFECTS: returns true if the tree pointed by n is
   //          sorted (see below)
public:
   BinaryTree();
   // EFFECTS: builds an empty binary tree
   BinaryTree(int v, const BinaryTree &left, 
         const BinaryTree &right); 
   // EFFECTS: builds a new tree whose root contains
   //          value v, its left subtree is a deep copy
   //          of left, its right subtree is a deep copy
   //          of right
   BinaryTree(const BinaryTree &bt);
   // EFFECTS: deep copy constructor from binary tree bt
   BinaryTree &operator=(const BinaryTree &bt); // TODO
   // MODIFIES: this
   // EFFECTS: deep copies from binary tree bt
   ~BinaryTree(); 

   void removeAll(); 
   // MODIFIES: this
   // EFFECTS: deallocates all the nodes

   // Other methods skipped

   unsigned int count();
   // EFFECTS: returns the number of elements in the tree

   bool isSorted();
   // EFFECTS: returns true if the binary tree is such 
   //          that v in the root node is larger or equal
   //          to any values in the nodes of the left
   //          subtree, and it is smaller or equal to 
   //          any values in the nodes of the right 
   //          subtree.
   //          This ordering property applies recursively
   //          to the left and right subtrees.
};

#endif
