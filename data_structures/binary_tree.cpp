#include "binary_tree.h"
#include <QDebug>

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T &value, BinaryTreeNode<T> *parent)
{
    this->parent = parent;
    this->value = value;
    left = nullptr;
    right = nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree()
{
    current = root = nullptr;
}

template <typename T>
void BinaryTree<T>::traceroute_recursive_preorder(BinaryTreeNode<T> *node)
{
    if (node != nullptr)
    {
        qDebug() << node->value;
        traceroute_recursive_preorder(node->left);
        traceroute_recursive_preorder(node->right);
    }
}

template <typename T>
void BinaryTree<T>::print_nodes_preorder()
{
    traceroute_recursive_preorder(root);
}

template <typename T>
void BinaryTree<T>::traceroute_recursive_inorder(BinaryTreeNode<T> *node)
{
    if (node != nullptr)
    {
        traceroute_recursive_inorder(node->left);
        qDebug() << node->value;
        traceroute_recursive_inorder(node->right);
    }
}

template <typename T>
void BinaryTree<T>::print_nodes_inorder()
{
    traceroute_recursive_inorder(root);
}

template <typename T>
void BinaryTree<T>::traceroute_recursive_postorder(BinaryTreeNode<T> *node)
{
    if (node != nullptr)
    {
        traceroute_recursive_postorder(node->left);
        traceroute_recursive_postorder(node->right);
        qDebug() << node->value;
    }
}

template <typename T>
void BinaryTree<T>::print_nodes_postorder()
{
    traceroute_recursive_postorder(root);
}

template <typename T>
void BinaryTree<T>::add_node(T value)
{
    if (root == nullptr)
    {
        root = new BinaryTreeNode<T>(value);
    }
    else
    {
        add_node(value, root);
    }
}

template <typename T>
void BinaryTree<T>::add_node(T value, BinaryTreeNode<T> *parent)
{
    if (value > parent->value)
    {
        if (parent->right == nullptr)
        {
            parent->right = new BinaryTreeNode<T>(value, parent);
        }
        else
        {
            add_node(value, parent->right);
        }
    }
    else
    {
        if (parent->left == nullptr)
        {
            parent->left = new BinaryTreeNode<T>(value, parent);
        }
        else
        {
            add_node(value, parent->left);
        }
    }
}

template <typename T>
void BinaryTree<T>::traceroute_node(T value)
{
    traceroute_node(value, root);
}

template <typename T>
void BinaryTree<T>::traceroute_node(T value, BinaryTreeNode<T> *parent)
{
    if (parent == nullptr)
    {
        qDebug() << "There is no such value in binary tree.";
        return;
    }
    qDebug() << parent->value;
    if (value > parent->value)
    {
        traceroute_node(value, parent->right);
    }
    else if (value < parent->value)
    {
        traceroute_node(value, parent->left);
    }
    else
    {
        return;
    }
}

template <typename T>
bool BinaryTree<T>::contains(T value)
{
    return contains(value, root);
}

template <typename T>
bool BinaryTree<T>::contains(T value, BinaryTreeNode<T> *parent)
{
    if (parent == nullptr)
    {
        return false;
    }
    if (value > parent->value)
    {
        return contains(value, parent->right);
    }
    else if (value < parent->value)
    {
        return contains(value, parent->left);
    }
    else
    {
        return true;
    }
}

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<double>;
