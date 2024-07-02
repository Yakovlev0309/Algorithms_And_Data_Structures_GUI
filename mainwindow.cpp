#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

#include "data_structures/linked_list.h"
#include "data_structures/binary_tree.h"

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
}

void MainWindow::on_binary_tree_test_button_clicked()
{
    BinaryTree<int> t;
    t.add_node(5);
    t.add_node(3);
    t.add_node(8);
    t.add_node(2);
    // print_container(t.to_array(), t.size(), typeid(t).name());
    t.print_nodes_preorder();
}
