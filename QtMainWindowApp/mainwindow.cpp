#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), //konstruktor
    ui(new Ui::MainWindow) //inicijalizira ui objekt sa novim MainWindow-om
{
    ui->setupUi(this); //objekt se zove "setupUi" koji otvara naš prozor
}

MainWindow::~MainWindow() //desktrukor
{
    delete ui;
}

void MainWindow::on_OKgumb_clicked()
{
    MyMessageBox msgBox;
    msgBox.setText("Unesli ste riječ: ");
    msgBox.exec();
}
