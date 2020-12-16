#include <iostream>
#include <fstream>
#include "binaryTree.h"
#include "huffmanTree.h"

using namespace std;

// EFFECTS: return the character represented by path
string findstr(const string& path, const Node* root);

int main(int argc, char *argv[]) {
    string treefile = argv[1];
    string binaryfile = argv[2];
    HuffmanTree tree(treefile);
    ifstream iFile;
    iFile.open(binaryfile);
    string path;
    while (iFile >> path) {
        cout << findstr(path, tree.root);
    }
    iFile.close();
}

// decompress the binary value
string findstr(const string& path, const Node* root) {
    Node* temp = const_cast<Node *>(root);
    for (int i = 0; i < path.length(); ++i) {
        if (path[i] == '1')
            temp = temp->rightSubtree();
        else
            temp = temp->leftSubtree();
    }
    return temp->getstr();
}