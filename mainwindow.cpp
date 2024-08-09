#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

#include <typeinfo>

#include "data_structures/linked_list.hpp"
#include "data_structures/binary_tree.hpp"
#include "data_structures/stack.hpp"
#include "data_structures/queue.hpp"

#include "algorithms/sortings.hpp"
#include "algorithms/searchings.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

template <typename T>
void print_container(T* arr, size_t size, const std::string& container_name = "container")
{
    if (size > 0)
    {
        QDebug debug(QtMsgType::QtDebugMsg);
        debug.setAutoInsertSpaces(false);
        debug << container_name.c_str() << "(size: " << size << ", values: {";
        for (size_t i = 0; i < size - 1; ++i)
        {
            debug << arr[i] << ", ";
        }
        debug << arr[size - 1] << "})";
    }
    else
    {
        QDebug debug(QtMsgType::QtDebugMsg);
        debug << container_name.c_str() << "(size = 0, values = {})";
    }
}

void MainWindow::on_linked_list_test_button_clicked()
{
    LinkedList<int> l = {3, 1, 4, 1, 5};
    print_container(l.to_array(), l.size());
    l.append_back(926535);
    print_container(l.to_array(), l.size(), typeid(l).name());
    qDebug() << "element at index 2 =" << l[2];
    l.remove_back();
    print_container(l.to_array(), l.size(), typeid(l).name());
    qDebug() << "contains 3 =" << l.contains(3);
    l.remove_front();
    print_container(l.to_array(), l.size(), typeid(l).name());
    qDebug() << "contains 3 =" << l.contains(3);
}

void MainWindow::on_binary_tree_test_button_clicked()
{
    // unique_lock<mutex> ul(console_mutex);
    BinaryTree<int> t;
    t.add_node(5);
    t.add_node(3);
    t.add_node(8);
    t.add_node(2);
    // print_container(t.to_array(), t.size(), typeid(t).name());
    t.print_nodes_preorder();
}

void MainWindow::on_stack_test_button_clicked()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    qDebug() << "is empty =" << s.is_empty();

    print_container(s.to_array(), s.size(), typeid(s).name());
    qDebug() << "contains 5 =" << s.contains(5);

    s.pop();
    print_container(s.to_array(), s.size(), typeid(s).name());
    qDebug() << "contains 5 =" << s.contains(5);
    qDebug() << "top element =" << s.peek();

    while (s.size() > 0)
    {
        s.pop();
    }
    print_container(s.to_array(), s.size(), (typeid(s).name()));
    qDebug() << "is empty =" << s.is_empty();
    qDebug() << "top element =" << s.peek();
}

void MainWindow::on_queue_test_button_clicked()
{
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    qDebug() << "is empty =" << q.is_empty();

    print_container(q.to_array(), q.size(), typeid(q).name());
    qDebug() << "contains 5 =" << q.contains(5);

    q.pop();
    print_container(q.to_array(), q.size(), typeid(q).name());
    qDebug() << "contains 5 =" << q.contains(5);
    qDebug() << "top element =" << q.peek();

    while (q.size() > 0)
    {
        q.pop();
    }
    print_container(q.to_array(), q.size(), (typeid(q).name()));
    qDebug() << "is empty =" << q.is_empty();
    qDebug() << "top element =" << q.peek();
}

void MainWindow::on_bubble_sort_test_button_clicked()
{
    int* arr = new int[]{5, 2, 6, 1, 8, 2, 9, 11};
    int size = 8;
    print_container(arr, size);
    Sortings::bubble_sort(arr, size);
    print_container(arr, size);
    delete[] arr;
}

void MainWindow::on_selection_sort_test_button_clicked()
{
    int* arr = new int[]{5, 2, 6, 1, 8, 2, 9, 11};
    int size = 8;
    print_container(arr, size);
    Sortings::selection_sort(arr, size);
    print_container(arr, size);
    delete[] arr;
}

void MainWindow::on_quick_sort_test_button_clicked()
{
    int* arr = new int[]{5, 2, 6, 1, 8, 2, 9, 11};
    int size = 8;
    print_container(arr, size);
    Sortings::quick_sort(arr, size);
    print_container(arr, size);
    delete[] arr;
}

void MainWindow::on_linear_search_test_button_clicked()
{
    int* arr = new int[]{5, 2, 6, 1, 8, 2, 9, 11};
    int size = 8;
    print_container(arr, size);
    int value = 6;
    size_t index = Searchings::linear_search(arr, size, value);
    qDebug() << "Index of first" << value << "=" << index;
    delete[] arr;
}

void MainWindow::on_binary_search_test_button_clicked()
{
    int* arr = new int[]{5, 2, 6, 1, 8, 2, 9, 11};
    int size = 8;
    print_container(arr, size);
    Sortings::quick_sort(arr, size);
    print_container(arr, size);
    int value = 5;
    size_t index = Searchings::binary_search(arr, size, value);
    qDebug() << value << "=" << index;
    delete[] arr;
}
