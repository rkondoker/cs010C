#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

Node::Node(){
    count = 0;
    data = "";
    left = nullptr;
    right = nullptr;
}

Node::Node(string m){
    count = 0;
    data = m;
    left = nullptr;
    right = nullptr;
}
Node::Node(string m, int n){
    count = n;
    data = m;
    left = nullptr;
    right = nullptr;
}

string Node::GetData(){
    return data;
}

int Node::GetCount(){
    return count;
}

void Node::SetData(string m){
    data = m;
}

void Node::UpCount(){
    count = count + 1;
}

void Node::DownCount(){
    count -= 1;
}

