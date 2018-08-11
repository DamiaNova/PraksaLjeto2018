#include "glavniprozor.h"
#include "ui_glavniprozor.h"

GlavniProzor::GlavniProzor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GlavniProzor)
{
    ui->setupUi(this);
}

GlavniProzor::~GlavniProzor()
{
    delete ui;
}
