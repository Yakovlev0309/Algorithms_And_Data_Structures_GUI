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

    void traceroute_recursive_preorder(BinaryTreeNode<T> *node);
    void print_nodes_preorder();
    void traceroute_recursive_inorder(BinaryTreeNode<T> *node);
    void print_nodes_inorder();
    void traceroute_recursive_postorder(BinaryTreeNode<T> *node);
    void print_nodes_postorder();

    void add_node(T value);
    void remove_node(T value);

    void traceroute_node(T value);
    bool contains(T value);

private:
    void add_node(T value, BinaryTreeNode<T> *parent);
    void traceroute_node(T value, BinaryTreeNode<T> *parent);
    bool contains(T value, BinaryTreeNode<T> *parent);

private:
    BinaryTreeNode<T> *root;
    BinaryTreeNode<T> *current;
};


#endif // BINARYTREE_H
