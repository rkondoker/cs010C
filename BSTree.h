#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
#ifndef _BSTREE_H_
#define _BSTREE_H_


class BSTree {
    private:
        Node *root;  
    public:
        BSTree();
        ~BSTree();
        void insert(const string &);
        bool search(const string &) const;
        string largest( ) const;
        string smallest( ) const;
        int height(const string &) const;
        void remove(const string &);
        void preOrder() const; 
        void postOrder() const;
        void inOrder() const;
    private: //helpers
        void preOrder(Node*) const;
        void postOrder(Node*) const;
        void inOrder(Node*) const;
        void destroy(Node*); //destructor helper
        Node* search(Node*, const string& ) const;
};
#endif
