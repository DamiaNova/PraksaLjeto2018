#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
    class MainWindow; //govori mainwindow.ui file-u da uključi MainWindow u sebe
}

class MainWindow : public QMainWindow //nasljeđuje od QMainWindow klase
{
    Q_OBJECT //MOC=Meta-Object Compiler, čita C++ header dokumente

public:
    explicit MainWindow(QWidget *parent = nullptr); //konstruktor
    ~MainWindow(); //destruktor

private slots:
    void on_OKgumb_clicked();

    void on_ObrisiGumb_clicked();

private:
    Ui::MainWindow *ui; //objekt MainWindow-a imena "ui", preko njega se pristupa svim widgetima
};

#endif // MAINWINDOW_H
