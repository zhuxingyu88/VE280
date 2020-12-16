#include "binaryTree.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

/* ================================== Node =================================== */

// constructor for node
Node::Node(const std::string &str, int num, Node *left, Node *right): str(str), num(num), left(left), right(right) {
}

// Return the pointer to the left child of the node.
Node* Node::leftSubtree() const{
    return left;
}

// set the left child of the node to be n.
void Node::setleft(Node *n) {
    left = n;
}

// Return the pointer to the right child of the node.
Node* Node::rightSubtree() const{
    return right;
}

// set the right child of the node to be n.
void Node::setright(Node *n) {
    right = n;
}

// Return “str”
string Node::getstr() const {
    return str;
}

// Return "num"
int Node::getnum() const {
    return num;
}

// num += 1
void Node::incnum() {
    num += 1;
}

// merge the two nodes
Node *Node::mergeNodes(Node *leftNode, Node *rightNode) {
    Node* nd = new Node(leftNode->str + rightNode->str, leftNode->num + rightNode->num, leftNode, rightNode);
    return nd;
}

/* =============================== Binary Tree =============================== */

// constructor
BinaryTree::BinaryTree(Node *rootNode){
    root = rootNode;
}

// MODIFIES: root
// EFFECTS: helper function for ~BinaryTree
void destructor_helper(Node* root) {
    if (!root)
        return;
    destructor_helper(root->leftSubtree());
    destructor_helper(root->rightSubtree());
    delete root;
}

// destructor
BinaryTree::~BinaryTree() {
    destructor_helper(root);
}

// EFFECTS: helper function for findpath
bool findPath_helper(Node* root, const string &s, vector<string>* path) {
    if (!root)
        return false;
    if (root->getstr() == s)
        return true;
    bool flag = false;
    if(root->leftSubtree() && findPath_helper(root->leftSubtree(), s, path)) {
        path->push_back("0");
        flag = true;
    }
    if(root->rightSubtree() && !flag && findPath_helper(root->rightSubtree(), s, path)){
        path->push_back("1");
        flag = true;
    }
    return flag;
}

// Return the path from the root node to the node with the string s.
string BinaryTree::findPath(const string &s) const{
    vector<string> path;
    path.emplace_back("");
    if(findPath_helper(root, s, &path)) {
        string string1;
        for (auto j = path.rbegin(); j != path.rend(); ++j)
            string1 += *j;
        return string1;
    } else
        return "-1";
}

// EFFECTS: helper function for sum
int sum_helper(Node* root) {
    if (!root)
        return 0;
    return sum_helper(root->leftSubtree()) + root->getnum() + sum_helper(root->rightSubtree());
}

// Returns the sum of "num" values of all nodes in the tree
int BinaryTree::sum() const {
    return sum_helper(root);
}

// EFFECTS: helper function for depth
int depth_helper(Node* root) {
    if (!root)
        return 0;
    return depth_helper(root->leftSubtree()) > depth_helper(root->rightSubtree()) ?
    depth_helper(root->leftSubtree()) + 1 : depth_helper(root->rightSubtree()) + 1;
}

// Returns the depth of the tree
int BinaryTree::depth() const {
    return depth_helper(root);
}

// EFFECTS: helper function for preorder number print
void preorder_num_helper(Node* root, vector<int>* num) {
    if (!root)
        return;
    num->push_back(root->getnum());
    preorder_num_helper(root->leftSubtree(), num);
    preorder_num_helper(root->rightSubtree(), num);
}

// Prints the "num" component of each node using a pre-order traversal.
void BinaryTree::preorder_num() const {
    vector<int> num;
    preorder_num_helper(root, &num);
    for (auto i = num.begin(); i != num.end() ; ++i) {
        cout << *i;
        if (i != num.end() - 1)
            cout << ' ';
    }
    cout << endl;
}

// EFFECTS: helper function for inorder string print
void inorder_str_helper(Node* root, vector<string>* str) {
    if (!root)
        return;
    inorder_str_helper(root->leftSubtree(), str);
    str->push_back(root->getstr());
    inorder_str_helper(root->rightSubtree(), str);
}

// Prints the "str" component of each node using an in-order traversal
void BinaryTree::inorder_str() const {
    vector<string> str;
    inorder_str_helper(root, &str);
    for (auto i = str.begin(); i != str.end() ; ++i) {
        cout << *i;
        if (i != str.end() - 1)
            cout << ' ';
    }
    cout << endl;
}

// EFFECTS: helper function for postorder number print
void postorder_num_helper(Node* root, vector<int>* num) {
    if (!root)
        return;
    postorder_num_helper(root->leftSubtree(), num);
    postorder_num_helper(root->rightSubtree(), num);
    num->push_back(root->getnum());
}

// Prints the "num" component of each node using a post-order traversal.
void BinaryTree::postorder_num() const {
    vector<int> num;
    postorder_num_helper(root, &num);
    for (auto i = num.begin(); i != num.end() ; ++i) {
        cout << *i;
        if (i != num.end() - 1)
            cout << ' ';
    }
    cout << endl;
}

// EFFECTS: helper function of allPathSumGreater
bool allPathSumGreater_hepler(Node* root, int sum, int pathsum){
    if (!(root->leftSubtree() || root->rightSubtree()))
        return pathsum + root->getnum() > sum;
    else if (!root->leftSubtree() && root->rightSubtree())
        return allPathSumGreater_hepler(root->rightSubtree(), sum, pathsum + root->getnum());
    else if (root->leftSubtree() && !root->rightSubtree())
        return allPathSumGreater_hepler(root->leftSubtree(), sum, pathsum + root->getnum());
    else
        return allPathSumGreater_hepler(root->leftSubtree(), sum, pathsum + root->getnum())
        && allPathSumGreater_hepler(root->rightSubtree(), sum, pathsum + root->getnum());
}

// Returns true if and only if for each root-to-leaf path of the tree,
// the sum of "num" of all nodes along the path is greater than "sum".
bool BinaryTree::allPathSumGreater(int sum) const {
    return allPathSumGreater_hepler(root, sum, 0);
}

// EFFECTS: helper function of covered_by
bool covered_by_helper(Node* root, Node* tree) {
    if (!root)
        return true;
    if (!tree) {
        return false;
    }
    return root->getnum() == tree->getnum() && covered_by_helper(root->leftSubtree(), tree->leftSubtree()) &&
    covered_by_helper(root->rightSubtree(), tree->rightSubtree());
}

// Returns true if this tree is covered by the input binary tree "tree"
bool BinaryTree::covered_by(const BinaryTree &tree) const {
    return covered_by_helper(root, tree.root);
}

// EFFECTS: helper function of covered_by
bool contained_by_helper(Node* root, Node* tree) {
    if (covered_by_helper(root, tree))
        return true;
    if (!tree)
        return false;
    return contained_by_helper(root, tree->leftSubtree()) || contained_by_helper(root, tree->rightSubtree());
}

// Returns true if this tree is contained by the input binary tree "tree".
bool BinaryTree::contained_by(const BinaryTree &tree) const {
    return contained_by_helper(root, tree.root);
}

// EFFECTS: helper function of copy
Node* copy_helper(Node* root) {
    if (!root)
        return nullptr;
    Node* node = new Node(root->getstr(), root->getnum());
    node->setleft(copy_helper(root->leftSubtree()));
    node->setright(copy_helper(root->rightSubtree()));
    return node;
}

BinaryTree BinaryTree::copy() const {
    return BinaryTree(copy_helper(root));
}
