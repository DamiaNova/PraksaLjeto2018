#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "messagebox.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QLineEdit>
#include <QTimer>
#include <QFont>
#include "gumbi.h"

namespace Ui {
    class MainWindow; //govori mainwindow.ui file-u da uključi MainWindow u sebe
}

class MainWindow : public QMainWindow //nasljeđuje od QMainWindow klase
{
    Q_OBJECT //MOC = Meta-Object Compiler, čita C++ header dokumente
    //korištene varijable u programu:
    QMessageBox msgBox;
    messagebox2 mBox;
    QMessageBox prozor;
    QString tekst;
    QString krivi_unos;
    QString prazan_unos;
    QString rijec;
    QFont fontMsgBox;
    QFont fontProzor;
    QFont fontMenu;
    QFont fontGumb;
    QFont ilFont;
    QCursor ilKursor;
    //zbog timer-a
    gumbi g;
    QPushButton *gumb;
    QPushButton *OK;
    QPushButton *Obrisi;
    QList <QPushButton *> gumbici;

public:
    explicit MainWindow(QWidget *parent = nullptr); //konstruktor
    ~MainWindow(); //destruktor

public slots:
    void funkcija();

private slots:
    void on_OKgumb_clicked();
    void on_ObrisiGumb_clicked();
    void on_actionEngleski_triggered();
    void on_actionHrvatski_triggered();
    void on_actionSpanjolski_triggered();
    void on_actionInfo_triggered();
    void on_actionCustom_triggered();

private:
    Ui::MainWindow *ui; //objekt MainWindow-a imena "ui", preko njega se pristupa svim widgetima
    QTimer *timer;
};

#endif // MAINWINDOW_H
