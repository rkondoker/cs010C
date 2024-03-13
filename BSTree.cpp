#include "BSTree.h"
#include <iostream>
using namespace std;

BSTree::BSTree(){
    root = nullptr;
}

BSTree::~BSTree(){
    destroy(root);
}


void BSTree::insert(const string &key){
    Node *newNode = new Node(key);
    if (this->root==nullptr){
        this->root = newNode;
        newNode->UpCount();
    }
    else if (search(key)){
        search(root, key)->UpCount();
    }
    else{
        Node *curr = root;
        while(curr != nullptr){
                if (key < curr->GetData()){
                    if (curr->left==nullptr){
                        curr->left = newNode;
                        curr = nullptr;
                    }
            }
            else {
                if (curr->right == nullptr){
                    curr->right = newNode;
                    curr = nullptr;
                }
            }
        }

    }
}

bool BSTree::search(const string &key) const{
    Node* node = search(this->root, key);
    return node != nullptr;   
}

string BSTree::largest() const{
    Node *curr = root;
    if (curr == nullptr){
        return "";
    }
    else {
        while (curr->right != nullptr){
            curr = curr->right;
        }
        return curr->GetData();
    }
}

string BSTree::smallest() const {
    Node *curr = root;
    if (curr == nullptr){
        return "";
    }
    else {
        while (curr->left != nullptr){
            curr = curr->left;
        }
        return curr->GetData();
    }
}

int BSTree::height(const string &key) const {
    if (!search(key)){
        return -1;
    }
    else {
        Node *curr = root;
        int count = 0;
        while(curr->GetData() != key){
            if (key < curr->GetData()){
                curr = curr->left;
            }
            else if (key > curr->GetData()){
                curr = curr->right;
            }
            count += 1;
        }
        return count;
    }
}


void BSTree::remove(const string& key){
    Node* curr = root;
    Node* parent = nullptr;
    while (curr != nullptr){
        if (curr->GetData() == key){
            if (curr->left == nullptr && curr->right == nullptr){ //leaf node
                if (parent == nullptr){
                    if (curr->GetCount() > 1){    // count stuff
                        curr->DownCount();
                    }
                    else if (curr->GetCount() == 1){
                        delete curr;
                        root = nullptr;
                    }
                }
                else if (parent->left == curr){
                    if (curr->GetCount() > 1){    //count stuff
                        curr->DownCount();
                    }
                    else if (curr->GetCount() == 1){
                        delete curr;
                        root = nullptr;
                    }
                }
                else{
                    delete curr;
                    parent->right =nullptr;
                }
            }
            else if (curr->right == nullptr){ // only has left child
                if (parent == nullptr){
                    root = curr->left;
                }
                else if (parent->left == curr){
                    parent->left = curr->left;
                }
                else{
                    parent->right = curr->left;
                }
            }
            else if (curr->left == nullptr){ //only has right child
                if (parent == nullptr){
                    root = curr->right;
                }
                else if (parent->left == curr){
                    parent->left = curr->right;
                }
                else{
                    parent->right = curr->right;
                }
            }
            else{
                Node* successor = curr->right;
                while (successor->left != nullptr){
                    successor = successor->left;
                    string successorData = successor->GetData();
                    remove(successor->GetData());
                    curr->SetData(successorData);
                }
            }
        }
        else if (curr->GetData() < key){
            parent = curr;
            curr = curr->right;
        }
        else{
            parent = curr;
            curr = curr->left;
        }
    }
}

void BSTree::preOrder() const{
    preOrder(root);
}

void BSTree::preOrder(Node* curr) const{
    cout << curr->GetData() << '(' << curr->GetCount() << "), ";
    if (curr->left) preOrder(curr->left);
    if (curr->right) preOrder(curr->right);
}

void BSTree::postOrder() const{
    postOrder(root);
}

void BSTree::postOrder(Node* curr) const{
    if (curr->left) postOrder(curr->left);
    if (curr->right) postOrder(curr->right);
    cout << curr->GetData() << '(' << curr->GetCount() << "), ";
}

void BSTree::inOrder() const{
    inOrder(root);
}

void BSTree::inOrder(Node* curr) const{
    if (curr->left) inOrder(curr->left);
    cout << curr->GetData() << '(' << curr->GetCount() << "), ";
    if (curr->right) inOrder(curr->right);
}



//helper functions

void BSTree::destroy(Node* remNode){
    if(remNode){
        destroy(remNode->left);
        destroy(remNode->right);
        delete remNode;
    }
}

Node *BSTree::search(Node* node, const string &key) const{
    if (node == nullptr){
        return nullptr;
    }
    else if (node->GetData() == key){
        return node;
    }
    else if(key < node->GetData()){
        return search(node->left, key);
    }
    else {
        return search(node->right, key);
    }
}

