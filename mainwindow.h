#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_linked_list_test_button_clicked();

    void on_binary_tree_test_button_clicked();

    void on_stack_test_button_clicked();

    void on_bubble_sort_test_button_clicked();

    void on_selection_sort_test_button_clicked();

    void on_quick_sort_test_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
