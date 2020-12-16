//
// Created by 朱星宇 on 2020/7/17.
//
#include <iostream>
#include "binaryTree.h"
using namespace std;

int main() {
    Node* a = new Node("a", 1);
    Node* b = new Node("b", 2);
    Node* c = new Node("c", 3);
    Node* d = new Node("d", 4);
    Node* e = new Node("e", 5);
    Node* f = new Node("f", 6);
    Node* g = new Node("g", 7);
    Node* h = new Node("h", 8);
    e->setleft(g);
    e->setright(h);
    b->setleft(d);
    b->setright(e);
    c->setleft(f);
    a->setleft(b);
    a->setright(c);
    BinaryTree tree(a);

//    Node* a1 = new Node("a", 1);
//    Node* b1 = new Node("b", 2);
//    Node* c1 = new Node("c", 3);
//    Node* d1 = new Node("d", 4);
//    Node* e1 = new Node("e", 5);
//    Node* f1 = new Node("f", 6);
//    Node* g1 = new Node("g", 7);
//    Node* h1 = new Node("h", 8);
//    d1->setleft(g1);
//    d1->setright(h1);
//    b1->setleft(e1);
//    b1->setright(d1);
//    c1->setright(f1);
//    a1->setleft(b1);
//    a1->setright(c1);
//    BinaryTree tree1(a1);

    cout << tree.findPath("g") << endl;
    cout << tree.findPath("z") << endl;
    cout << tree.sum() << endl;
    cout << tree.depth() << endl;
    tree.preorder_num();
    tree.inorder_str();
    tree.postorder_num();
    cout << tree.allPathSumGreater(6) << endl;
    cout << tree.allPathSumGreater(7) << endl;
    BinaryTree tree1 = tree.copy();
    cout << tree1.covered_by(tree) << endl;
    cout << tree1.contained_by(tree) << endl;
    return 0;
}
