#ifndef BINARYTREE_H
#define BINARYTREE_H

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

#endif // BINARYTREE_H
