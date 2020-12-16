#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

#include "binaryTree.h"
#include "huffmanTree.h"

using namespace std;

// MODIFIES: text nodeVector
// EFFECTS: read the character from iFile and insert elements into text and nodeVector
void readfile(ifstream& iFile, vector<string>& text, vector<Node*>& nodeVector);

// MODIFIES: nodeVector
// EFFECTS: return the ç
HuffmanTree generateTree(vector<Node*>& nodeVector);

// EFFECTS: return true if node1 has higher frequency
bool sort_helper(Node* node1, Node* node2);

int main(int argc, char *argv[]) {
    string filename;
    if (argc == 2)
        filename = argv[1];
    else
        filename = argv[2];
    ifstream iFile;
    iFile.open(filename);
    vector<string> text;
    vector<Node*> nodeVector;
    readfile(iFile, text, nodeVector);
    iFile.close();
    iFile.clear();
    HuffmanTree tree = generateTree(nodeVector);
    if (argc == 3) {
        tree.printTree();
        return 0;
    } else {
        for (auto i = text.begin(); i != text.end() ; ++i) {
            cout << tree.findPath(*i) + " ";
        }
        return 0;
    }

}

// read the character from iFile
void readfile(ifstream& iFile, vector<string>& text, vector<Node*>& nodeVector) {
    char cha;
    string str;
    bool flag = true;
    while (iFile.get(cha)) {
        str = cha;
        text.push_back(str);
        for (auto i = nodeVector.begin(); i != nodeVector.end(); ++i) {
            if ((*i)->getstr() == str) {
                (*i)->incnum();
                flag = false;
                break;
            }
        }
        if (flag) {
            Node* node = new Node(str, 1);
            nodeVector.push_back(node);
        }
        flag = true;
    }
}

// generate HuffmanTree
HuffmanTree generateTree(vector<Node*>& nodeVector) {
    Node* right;
    Node* left;
    while (nodeVector.size() > 1) {
        sort(nodeVector.begin(), nodeVector.end(), sort_helper);
        right = nodeVector.back();
        nodeVector.pop_back();
        left = nodeVector.back();
        nodeVector.pop_back();
        nodeVector.emplace_back(Node::mergeNodes(left, right));
    }
    HuffmanTree tree(nodeVector.front());
    return tree;
}

// return true if node1 > node2
bool sort_helper(Node* node1, Node* node2) {
    if (node1->getnum() > node2->getnum())
        return true;
    else if (node1->getnum() == node2->getnum())
        return node1->getstr()[0] > node2->getstr()[0];
    else
        return false;
}