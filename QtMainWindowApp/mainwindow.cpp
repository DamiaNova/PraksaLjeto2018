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

void MainWindow::on_ObrisiGumb_clicked()
{
    ui->InputLine->selectAll();
    ui->InputLine->del();
}

//kada kliknemo gumb OK
void MainWindow::on_OKgumb_clicked()
{
    QMessageBox msgBox; //objekt klase QMessageBox
    msgBox.setWindowTitle("Prozor"); //postavljanje naslova
    QString tekst="Unesli ste sljedeći tekst: \'";
    QString rijec = ui->InputLine->text(); //unesena riječ
    rijec.append("\'");
    if ( (rijec.size() > 1) && (rijec.size() <= 200)) msgBox.setText(tekst.append(rijec));
    else if(rijec.size() > 200) msgBox.setText("Uneseni tekst ne smije biti dulji od 200 znakova.");
    else msgBox.setText("Niste unesli tekst.");
    msgBox.exec(); //prikazivanje MessageBox-a
}
