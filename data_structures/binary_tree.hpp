#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <QDebug>

template <typename T>
class BinaryTreeNode
{
public:
    BinaryTreeNode(const T &value, BinaryTreeNode<T> *parent = nullptr);

    T value;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode<T> *parent;
};

template <typename T>
class BinaryTree
{
public:
    BinaryTree();

    void traceroute_recursive_preorder(BinaryTreeNode<T> *node) const;
    void print_nodes_preorder() const;
    void traceroute_recursive_inorder(BinaryTreeNode<T> *node) const;
    void print_nodes_inorder() const;
    void traceroute_recursive_postorder(BinaryTreeNode<T> *node) const;
    void print_nodes_postorder() const;

    // TODO переделать все tracetoure'ы в to_array'и
    // TODO сделать общий интерфейс Container, который должны реализовывать все контейнеры (структуры данных)

    void add_node(T value);
    void remove_node(T value);

    void traceroute_node(T value) const;
    bool contains(T value) const;

private:
    void add_node(T value, BinaryTreeNode<T> *parent);
    void traceroute_node(T value, BinaryTreeNode<T> *parent) const;
    bool contains(T value, BinaryTreeNode<T> *parent) const;

private:
    BinaryTreeNode<T> *root;
    BinaryTreeNode<T> *current;
};

// ----------

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
void BinaryTree<T>::traceroute_recursive_preorder(BinaryTreeNode<T> *node) const
{
    if (node != nullptr)
    {
        qDebug() << node->value;
        traceroute_recursive_preorder(node->left);
        traceroute_recursive_preorder(node->right);
    }
}

template <typename T>
void BinaryTree<T>::print_nodes_preorder() const
{
    traceroute_recursive_preorder(root);
}

template <typename T>
void BinaryTree<T>::traceroute_recursive_inorder(BinaryTreeNode<T> *node) const
{
    if (node != nullptr)
    {
        traceroute_recursive_inorder(node->left);
        qDebug() << node->value;
        traceroute_recursive_inorder(node->right);
    }
}

template <typename T>
void BinaryTree<T>::print_nodes_inorder() const
{
    traceroute_recursive_inorder(root);
}

template <typename T>
void BinaryTree<T>::traceroute_recursive_postorder(BinaryTreeNode<T> *node) const
{
    if (node != nullptr)
    {
        traceroute_recursive_postorder(node->left);
        traceroute_recursive_postorder(node->right);
        qDebug() << node->value;
    }
}

template <typename T>
void BinaryTree<T>::print_nodes_postorder() const
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
void BinaryTree<T>::traceroute_node(T value) const
{
    traceroute_node(value, root);
}

template <typename T>
void BinaryTree<T>::traceroute_node(T value, BinaryTreeNode<T> *parent) const
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
bool BinaryTree<T>::contains(T value) const
{
    return contains(value, root);
}

template <typename T>
bool BinaryTree<T>::contains(T value, BinaryTreeNode<T> *parent) const
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

#endif // BINARYTREE_H
