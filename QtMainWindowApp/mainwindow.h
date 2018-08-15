#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QLineEdit>
#include <QFont>

namespace Ui {
    class MainWindow; //govori mainwindow.ui file-u da uključi MainWindow u sebe
}

class MainWindow : public QMainWindow //nasljeđuje od QMainWindow klase
{
    Q_OBJECT //MOC = Meta-Object Compiler, čita C++ header dokumente
    //korištene varijable u programu:
    QMessageBox msgBox;
    QString tekst;
    QString krivi_unos;
    QString prazan_unos;
    QString rijec;
    QFont fontMsgBox;
    QFont fontMenu;
    QFont fontGumb;
    QFont ilFont;
    QCursor ilKursor;

public:
    explicit MainWindow(QWidget *parent = nullptr); //konstruktor
    ~MainWindow(); //destruktor

private slots:
    void on_OKgumb_clicked();
    void on_ObrisiGumb_clicked();

    void on_actionEngleski_triggered();

    void on_actionHrvatski_triggered();

private:
    Ui::MainWindow *ui; //objekt MainWindow-a imena "ui", preko njega se pristupa svim widgetima
};

#endif // MAINWINDOW_H
