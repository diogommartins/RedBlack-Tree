//
//  RebBlackTree.cpp
//  Red Black Tree
//
//  Created by Diogo  Martins on 10/19/15.
//  Copyright © 2015 Diogo Magalhães Martins. All rights reserved.
//

#include "RebBlackTree.hpp"

template <typename T>
bool RedBlackTree<T>::empty()
{
    return root == nullptr;
}

template <typename T>
Node<T>* RedBlackTree<T>::grandparent(Node<T> *node) const
{
    if ((node != nullptr) && (node->parent != nullptr) && (node->parent->parent != nullptr))
        return node->parent->parent;
    return nullptr;
}

template <typename T>
Node<T>* RedBlackTree<T>::uncle(Node<T> *node) const
{
    Node<T> *grandparentNode = grandparent(node);
    if (grandparentNode)
    {
        if (grandparentNode->rightChild == node->parent)
            return grandparentNode->leftChild;
        else
            return grandparentNode->rightChild;
    }
    return nullptr;
}

template <typename T>
Node<T>* RedBlackTree<T>::sibling(Node<T> *node) const
{
    if (!node || !node->parent)
        return nullptr;
    
    if (node->parent->leftChild == node)
        return node->parent->rightChild;
    else
        return node->parent->leftChild;
}

template <typename T>
void RedBlackTree<T>::swapValues(Node<T> *&node1, Node<T> *&node2)
{
    T temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;

}

template class RedBlackTree<int>;
template class RedBlackTree<float>;
template class RedBlackTree<double>;
template class RedBlackTree<long>;
template class RedBlackTree<long long>;