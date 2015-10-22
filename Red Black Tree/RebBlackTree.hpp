//
//  RebBlackTree.hpp
//  Red Black Tree
//
//  Created by Diogo  Martins on 10/19/15.
//  Copyright © 2015 Diogo Magalhães Martins. All rights reserved.
//

#ifndef RebBlackTree_hpp
#define RebBlackTree_hpp

#include <stdio.h>

enum NodeColor{
    RED,
    BLACK
};

template<typename T>
struct Node
{
    T data;
    NodeColor color;
    Node<T> * parent;
    Node<T> * leftChild;
    Node<T> * rightChild;
    Node(T data): data(data), leftChild(nullptr), rightChild(nullptr){}
    bool operator == (const Node& node) { return data == node->data; }
    bool operator != (const Node& node) { return data != node->data; }
    bool operator < (const Node& node) { return data < node->data; }
    bool operator > (const Node& node) { return data > node->data; }
    bool operator <= (const Node& node) { return data <= node->data; }
    bool operator >= (const Node& node) { return data >= node->data; }
};


/*
 Properties:
 1: Every node is either BLACK or RED
 2: The root is BLACK
 3: From any node, the path between the node to its descendents nodes contains the same amount of BLACK nodes
 4: If a node is RED, both its childs are BLACK
 */
template <typename T>
class RedBlackTree {

public:
    RedBlackTree() { root = nullptr; }
    void insert(const T& value);
    void remove(T value);
    bool empty();
protected:
    Node<T> *root;
private:
    Node<T>* sibling(Node<T> *node) const;
    Node<T>* uncle(Node<T> *node) const;
    Node<T>* grandparent(Node<T> *node) const;
    void swapValues(Node<T> *&node1, Node<T> *&node2);
};

#endif /* RebBlackTree_hpp */
