#include <iostream>
#include <string>
using namespace std;

#ifndef _NODE_H_
#define _NODE_H_

class Node {
    private:
        int count;
        string data;
    public:
        Node *left;
        Node *right;
        Node();
        Node(string);
        Node(string, int);
        string GetData();
        int GetCount();
        void SetData(string);
        void UpCount();
        void DownCount();
};

#endif