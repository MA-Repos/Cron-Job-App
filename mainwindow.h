#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QFileDialog>
#include <QStringListModel>
#include <QDebug>
#include <QString>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void refreshList();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
