/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QListView *listView;
    QTextEdit *textEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QListView *listViewMinute;
    QListView *listViewHour;
    QListView *listViewDay;
    QListView *listViewMonth;
    QListView *listViewWeekday;
    QMenuBar *menuBar;
    QMenu *menuCronJob_Manager;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(649, 520);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 30, 321, 20));
        QFont font;
        font.setFamily(QStringLiteral("Sans Serif"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(60, 60, 551, 81));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(60, 180, 551, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 160, 111, 16));
        QFont font1;
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 220, 59, 14));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 220, 60, 14));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(300, 220, 31, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(390, 220, 41, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(490, 220, 61, 16));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(50, 370, 241, 51));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(320, 370, 241, 51));
        listViewMinute = new QListView(centralWidget);
        listViewMinute->setObjectName(QStringLiteral("listViewMinute"));
        listViewMinute->setGeometry(QRect(80, 240, 81, 111));
        listViewHour = new QListView(centralWidget);
        listViewHour->setObjectName(QStringLiteral("listViewHour"));
        listViewHour->setGeometry(QRect(180, 240, 81, 111));
        listViewDay = new QListView(centralWidget);
        listViewDay->setObjectName(QStringLiteral("listViewDay"));
        listViewDay->setGeometry(QRect(280, 240, 81, 111));
        listViewMonth = new QListView(centralWidget);
        listViewMonth->setObjectName(QStringLiteral("listViewMonth"));
        listViewMonth->setGeometry(QRect(380, 240, 91, 111));
        listViewWeekday = new QListView(centralWidget);
        listViewWeekday->setObjectName(QStringLiteral("listViewWeekday"));
        listViewWeekday->setGeometry(QRect(490, 240, 101, 111));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 649, 19));
        menuCronJob_Manager = new QMenu(menuBar);
        menuCronJob_Manager->setObjectName(QStringLiteral("menuCronJob_Manager"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCronJob_Manager->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "CronTabs scheduled on your OS:", 0));
        textEdit_2->setPlaceholderText(QApplication::translate("MainWindow", "Command to be executed", 0));
        label_2->setText(QApplication::translate("MainWindow", "Add CrontTab:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Minute", 0));
        label_4->setText(QApplication::translate("MainWindow", "Hour", 0));
        label_5->setText(QApplication::translate("MainWindow", "Day", 0));
        label_6->setText(QApplication::translate("MainWindow", "Month", 0));
        label_7->setText(QApplication::translate("MainWindow", "Week Day", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Add Cron Job", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Delete Selected Cron Job", 0));
        menuCronJob_Manager->setTitle(QApplication::translate("MainWindow", "CronJob Manager", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
