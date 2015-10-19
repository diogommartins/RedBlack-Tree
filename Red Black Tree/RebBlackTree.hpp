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
    T value;
    NodeColor color;
    Node<T> * left;
    Node<T> * right;
    Node(T value): value(value), left(nullptr), right(nullptr){}
};

template <typename T>
class RedBlackTree {

public:
    RedBlackTree() { root = nullptr; }
    void insert(T value);
    void remove(T value);
protected:
    Node<T> *root;
private:
    Node<T>*& sibling(Node<T> *node);
    Node<T>*& uncle(Node<T> *node);
    Node<T>*& grandparent(Node<T> *node);
};

#endif /* RebBlackTree_hpp */
