//
// Created by 朱星宇 on 2020/7/17.
//
#include <iostream>
#include "binaryTree.h"
using namespace std;

int main() {
    BinaryTree tree;
    cout << tree.findPath("g") << endl;
    cout << tree.findPath("z") << endl;
    cout << tree.sum() << endl;
    cout << tree.depth() << endl;
    tree.preorder_num();
    tree.inorder_str();
    tree.postorder_num();

}
