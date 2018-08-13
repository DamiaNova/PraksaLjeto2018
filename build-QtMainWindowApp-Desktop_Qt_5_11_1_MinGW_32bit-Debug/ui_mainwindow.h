/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHrvatski;
    QAction *actionEngleski;
    QAction *actionJapanski;
    QAction *actionDefault;
    QAction *actionCustom;
    QAction *actionInfo;
    QAction *actionO_Qt_platformi;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *Naslov;
    QLabel *OpisApp;
    QLineEdit *InputLine;
    QPushButton *OKgumb;
    QPushButton *OdustaniGumb;
    QMenuBar *menuBar;
    QMenu *menuJezik;
    QMenu *menuParametri;
    QMenu *menuInfo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(471, 538);
        actionHrvatski = new QAction(MainWindow);
        actionHrvatski->setObjectName(QStringLiteral("actionHrvatski"));
        actionEngleski = new QAction(MainWindow);
        actionEngleski->setObjectName(QStringLiteral("actionEngleski"));
        actionJapanski = new QAction(MainWindow);
        actionJapanski->setObjectName(QStringLiteral("actionJapanski"));
        actionDefault = new QAction(MainWindow);
        actionDefault->setObjectName(QStringLiteral("actionDefault"));
        actionCustom = new QAction(MainWindow);
        actionCustom->setObjectName(QStringLiteral("actionCustom"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        actionO_Qt_platformi = new QAction(MainWindow);
        actionO_Qt_platformi->setObjectName(QStringLiteral("actionO_Qt_platformi"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 40, 391, 221));
        groupBox->setAlignment(Qt::AlignCenter);
        Naslov = new QLabel(groupBox);
        Naslov->setObjectName(QStringLiteral("Naslov"));
        Naslov->setGeometry(QRect(20, 30, 331, 61));
        QFont font;
        font.setPointSize(17);
        Naslov->setFont(font);
        Naslov->setAlignment(Qt::AlignCenter);
        OpisApp = new QLabel(groupBox);
        OpisApp->setObjectName(QStringLiteral("OpisApp"));
        OpisApp->setGeometry(QRect(30, 90, 311, 111));
        QFont font1;
        font1.setPointSize(10);
        OpisApp->setFont(font1);
        OpisApp->setLayoutDirection(Qt::LeftToRight);
        OpisApp->setAlignment(Qt::AlignCenter);
        OpisApp->setWordWrap(true);
        InputLine = new QLineEdit(centralWidget);
        InputLine->setObjectName(QStringLiteral("InputLine"));
        InputLine->setGeometry(QRect(60, 300, 351, 31));
        InputLine->setAlignment(Qt::AlignCenter);
        OKgumb = new QPushButton(centralWidget);
        OKgumb->setObjectName(QStringLiteral("OKgumb"));
        OKgumb->setGeometry(QRect(310, 370, 111, 61));
        QFont font2;
        font2.setPointSize(9);
        OKgumb->setFont(font2);
        OdustaniGumb = new QPushButton(centralWidget);
        OdustaniGumb->setObjectName(QStringLiteral("OdustaniGumb"));
        OdustaniGumb->setGeometry(QRect(50, 370, 121, 61));
        OdustaniGumb->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 471, 26));
        menuJezik = new QMenu(menuBar);
        menuJezik->setObjectName(QStringLiteral("menuJezik"));
        menuJezik->setGeometry(QRect(339, 116, 159, 126));
        menuParametri = new QMenu(menuBar);
        menuParametri->setObjectName(QStringLiteral("menuParametri"));
        menuParametri->setGeometry(QRect(386, 116, 159, 102));
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QStringLiteral("menuInfo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuJezik->menuAction());
        menuBar->addAction(menuParametri->menuAction());
        menuBar->addAction(menuInfo->menuAction());
        menuJezik->addAction(actionHrvatski);
        menuJezik->addAction(actionEngleski);
        menuJezik->addAction(actionJapanski);
        menuParametri->addAction(actionDefault);
        menuParametri->addAction(actionCustom);
        menuInfo->addAction(actionInfo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "My App", nullptr));
        actionHrvatski->setText(QApplication::translate("MainWindow", "Hrvatski", nullptr));
        actionEngleski->setText(QApplication::translate("MainWindow", "Engleski", nullptr));
        actionJapanski->setText(QApplication::translate("MainWindow", "Japanski", nullptr));
        actionDefault->setText(QApplication::translate("MainWindow", "Zadani", nullptr));
        actionCustom->setText(QApplication::translate("MainWindow", "Prilago\304\221eni...", nullptr));
        actionInfo->setText(QApplication::translate("MainWindow", "O aplikaciji", nullptr));
        actionO_Qt_platformi->setText(QApplication::translate("MainWindow", "O Qt platformi", nullptr));
        groupBox->setTitle(QString());
        Naslov->setText(QApplication::translate("MainWindow", "Dobrodo\305\241li u Qt aplikaciju!", nullptr));
        OpisApp->setText(QApplication::translate("MainWindow", "Molimo unesite neku rije\304\215 ili re\304\215enicu (do 200 slova) i pritisnite \"OK\" gumb za nastavak. Za brisanje unesene rije\304\215i pritisnite \"Odustani\".", nullptr));
        OKgumb->setText(QApplication::translate("MainWindow", "OK", nullptr));
        OdustaniGumb->setText(QApplication::translate("MainWindow", "Odustani", nullptr));
        menuJezik->setTitle(QApplication::translate("MainWindow", "Jezik", nullptr));
        menuParametri->setTitle(QApplication::translate("MainWindow", "Parametri", nullptr));
        menuInfo->setTitle(QApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
