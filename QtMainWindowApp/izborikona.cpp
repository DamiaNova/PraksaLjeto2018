#include "izborikona.h"
#include "ui_izborikona.h"
#include <QPixmap>
#include <QCloseEvent>

izborIkona::izborIkona(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::izborIkona)
{
    ui->setupUi(this);
    QPixmap slika11(":/resursi/icons/computer.ico");
    ui->slika1->setPixmap(slika11.scaled(101,91,Qt::KeepAspectRatio));
    QPixmap slika22(":/resursi/icons/computer2.ico");
    ui->slika2->setPixmap(slika22.scaled(101,91,Qt::KeepAspectRatio));
    QPixmap slika33(":/resursi/icons/computer3.ico");
    ui->slika3->setPixmap(slika33.scaled(101,91,Qt::KeepAspectRatio));
    this->setWindowTitle("Izbor ikone");
    this->setWindowIcon(QIcon(":/resursi/icons/bird.ico"));
}

izborIkona::~izborIkona()
{
    delete ui;
}

void izborIkona::on_odustaniGmb_clicked()
{
    QDialog::close();
}
