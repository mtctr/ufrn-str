/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QCustomPlot *plot;
    QLabel *label_3;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pausarButton;
    QLineEdit *pidText;
    QPushButton *continuarButton;
    QLabel *label_2;
    QPushButton *encerrarButton;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *cpuText;
    QPushButton *trocarCpuButton;
    QLineEdit *pidCpuText;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *command;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QLabel *label_8;
    QProgressBar *cpuUsage_1;
    QLabel *label_9;
    QLabel *label_4;
    QProgressBar *cpuUsage_2;
    QProgressBar *cpuUsage_3;
    QProgressBar *cpuUsage_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1009, 679);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 981, 351));
        tableWidget->setSortingEnabled(false);
        plot = new QCustomPlot(centralWidget);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setGeometry(QRect(220, 380, 381, 171));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(620, 370, 191, 16));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(620, 390, 141, 162));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pausarButton = new QPushButton(gridLayoutWidget);
        pausarButton->setObjectName(QStringLiteral("pausarButton"));

        gridLayout->addWidget(pausarButton, 4, 1, 1, 1);

        pidText = new QLineEdit(gridLayoutWidget);
        pidText->setObjectName(QStringLiteral("pidText"));

        gridLayout->addWidget(pidText, 0, 1, 1, 1);

        continuarButton = new QPushButton(gridLayoutWidget);
        continuarButton->setObjectName(QStringLiteral("continuarButton"));

        gridLayout->addWidget(continuarButton, 1, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        encerrarButton = new QPushButton(gridLayoutWidget);
        encerrarButton->setObjectName(QStringLiteral("encerrarButton"));

        gridLayout->addWidget(encerrarButton, 5, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(780, 390, 153, 121));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        cpuText = new QLineEdit(gridLayoutWidget_2);
        cpuText->setObjectName(QStringLiteral("cpuText"));

        gridLayout_2->addWidget(cpuText, 1, 1, 1, 1);

        trocarCpuButton = new QPushButton(gridLayoutWidget_2);
        trocarCpuButton->setObjectName(QStringLiteral("trocarCpuButton"));

        gridLayout_2->addWidget(trocarCpuButton, 4, 1, 1, 1);

        pidCpuText = new QLineEdit(gridLayoutWidget_2);
        pidCpuText->setObjectName(QStringLiteral("pidCpuText"));

        gridLayout_2->addWidget(pidCpuText, 0, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 370, 201, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        command = new QLineEdit(horizontalLayoutWidget);
        command->setObjectName(QStringLiteral("command"));

        horizontalLayout->addWidget(command);

        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(220, 560, 381, 61));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(gridLayoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);

        gridLayout_3->addWidget(label_7, 0, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        cpuUsage_1 = new QProgressBar(gridLayoutWidget_3);
        cpuUsage_1->setObjectName(QStringLiteral("cpuUsage_1"));
        cpuUsage_1->setValue(24);

        gridLayout_3->addWidget(cpuUsage_1, 0, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        gridLayout_3->addWidget(label_9, 1, 2, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        cpuUsage_2 = new QProgressBar(gridLayoutWidget_3);
        cpuUsage_2->setObjectName(QStringLiteral("cpuUsage_2"));
        cpuUsage_2->setValue(24);

        gridLayout_3->addWidget(cpuUsage_2, 0, 3, 1, 1);

        cpuUsage_3 = new QProgressBar(gridLayoutWidget_3);
        cpuUsage_3->setObjectName(QStringLiteral("cpuUsage_3"));
        cpuUsage_3->setValue(24);

        gridLayout_3->addWidget(cpuUsage_3, 1, 1, 1, 1);

        cpuUsage_4 = new QProgressBar(gridLayoutWidget_3);
        cpuUsage_4->setObjectName(QStringLiteral("cpuUsage_4"));
        cpuUsage_4->setValue(24);

        gridLayout_3->addWidget(cpuUsage_4, 1, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1009, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(command, SIGNAL(textEdited(QString)), MainWindow, SLOT(filtrar()));
        QObject::connect(pidText, SIGNAL(textEdited(QString)), MainWindow, SLOT(validarPID()));
        QObject::connect(pausarButton, SIGNAL(clicked()), MainWindow, SLOT(pausarProcesso()));
        QObject::connect(continuarButton, SIGNAL(clicked()), MainWindow, SLOT(continuarProcesso()));
        QObject::connect(pidCpuText, SIGNAL(textEdited(QString)), MainWindow, SLOT(validarPidCpu()));
        QObject::connect(cpuText, SIGNAL(textEdited(QString)), MainWindow, SLOT(validarPidCpu()));
        QObject::connect(trocarCpuButton, SIGNAL(clicked()), MainWindow, SLOT(trocarCpu()));
        QObject::connect(encerrarButton, SIGNAL(clicked()), MainWindow, SLOT(matarProcesso()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Monitor de Processos", 0));
        label_3->setText(QApplication::translate("MainWindow", "Gerenciar Processos:", 0));
        pausarButton->setText(QApplication::translate("MainWindow", "Pausar", 0));
        continuarButton->setText(QApplication::translate("MainWindow", "Continuar", 0));
        label_2->setText(QApplication::translate("MainWindow", "PID:", 0));
        encerrarButton->setText(QApplication::translate("MainWindow", "Encerrar", 0));
        trocarCpuButton->setText(QApplication::translate("MainWindow", "Trocar CPU", 0));
        label_5->setText(QApplication::translate("MainWindow", "PID:", 0));
        label_6->setText(QApplication::translate("MainWindow", "CPU:", 0));
        label->setText(QApplication::translate("MainWindow", "Filtrar:", 0));
        label_7->setText(QApplication::translate("MainWindow", "CPU 2:", 0));
        label_8->setText(QApplication::translate("MainWindow", "CPU 3:", 0));
        label_9->setText(QApplication::translate("MainWindow", "CPU 4:", 0));
        label_4->setText(QApplication::translate("MainWindow", "CPU 1:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
