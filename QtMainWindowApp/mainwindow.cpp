#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "jezik.h"
#include "jezik.cpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), //konstruktor
    ui(new Ui::MainWindow) //inicijalizira ui objekt sa novim MainWindow-om
{
    ui->setupUi(this); //objekt se zove "setupUi" koji otvara naš prozor

     ui->actionHrvatski->triggered(true);

    //parametri za InputLine (LineEdit widget)
    ui->InputLine->setPlaceholderText("");
    ilFont.setFamily("MS Shell Dig 2");
    ilFont.setPixelSize(13);
    ilFont.setKerning(true);
    ilFont.setItalic(false);
    ilFont.setBold(false);
    ilFont.setStrikeOut(false);
    ilFont.setUnderline(false);
    ui->InputLine->setFont(ilFont);
    ilKursor.setShape(Qt::SizeVerCursor);
    ui->InputLine->setCursor(ilKursor);
    int x = 60;
    int y = 300;
    int width=351;
    int height=31;
    ui->InputLine->setGeometry(x,y,width,height);
    ui->InputLine->setMaximumHeight(100);
    ui->InputLine->setMaximumWidth(500);
    ui->InputLine->setMinimumHeight(20);
    ui->InputLine->setMinimumWidth(100);

    //stvaranje liste koja sadrži oba QPushButton-a
    QPushButton *gumb;
    QPushButton *OK =ui->OKgumb;
    QPushButton *Obrisi = ui->ObrisiGumb;
    QList <QPushButton *> gumbi = { OK, Obrisi };
    //parametri za oba QPushButton-a
    for (int i=0;i<2;i++){
        //parametri za gumbe
        gumb=gumbi[i];
        gumb->setDisabled(false);
        gumb->setAutoFillBackground(true);
        QPalette pal = gumb->palette();
        pal.setColor(QPalette::Button, QColor(Qt::blue));
        gumb->setAutoFillBackground(true);
        gumb->setPalette(pal);
        gumb->setFixedHeight(61);
        gumb->setFixedWidth(121);
        fontGumb.setFamily("MS Shell Dig 2");
        fontGumb.setPixelSize(8);
        fontGumb.setKerning(true);
        fontGumb.setItalic(false);
        fontGumb.setBold(false);
        fontGumb.setStrikeOut(false);
        fontGumb.setUnderline(false);
        fontGumb.setPointSize(9);
        gumb->setFont(fontGumb);
    }

    //stvaranje liste koja sadrži oba QLabel-a
    QLabel *etiketa;
    QLabel *naslov =ui->Naslov;
    QLabel *opis = ui->OpisApp;
    QList <QLabel *> etikete  = { naslov, opis };
    for (int i=0;i<2;i++){
        //parametri za etikete
        etiketa=etikete[i];
        etiketa->setStyleSheet("QLabel { color : black; }");
    }

    //parametri za QGroupBox
    ui->groupBox->setStyleSheet("background-color: lightgrey ;");

    //parametri za QMenuBar
    fontMenu.setFamily("MS Shell Dig 2");
    fontMenu.setPixelSize(10);
    fontMenu.setKerning(true);
    fontMenu.setItalic(false);
    fontMenu.setBold(false);
    fontMenu.setStrikeOut(false);
    fontMenu.setUnderline(false);
    fontMenu.setPointSize(9);
    ui->menuBar->setFont(fontMenu);

}

MainWindow::~MainWindow() //destrukor
{
    delete ui;
}

//kada kliknemo gumb Obriši
void MainWindow::on_ObrisiGumb_clicked()
{
    ui->InputLine->selectAll();
    ui->InputLine->del();
}

//kada kliknemo gumb OK
void MainWindow::on_OKgumb_clicked()
{
    //parametri za QMessageBox
    QPixmap ikonaMsgBox (":/resursi/icons/cat.ico");
    if (msgBox.windowTitle()=="") { msgBox.setWindowTitle("Prozor"); }
    msgBox.setWindowIcon(ikonaMsgBox);
    fontMsgBox.setFamily("MS Shell Dig 2");
    fontMsgBox.setPixelSize(10);
    fontMsgBox.setKerning(true);
    fontMsgBox.setItalic(false);
    fontMsgBox.setBold(false);
    fontMsgBox.setStrikeOut(false);
    fontMsgBox.setUnderline(false);
    fontMsgBox.setPointSize(9);
    msgBox.setFont(fontMsgBox);
    msgBox.setButtonText(1,"OK");

    rijec = ui->InputLine->text(); //unesena riječ
    int duljinaRijeci = rijec.length();
    rijec.insert(0,tekst);
    rijec.append("'");

    if ( (duljinaRijeci > 0) && (duljinaRijeci <= 200)) msgBox.setText(rijec);
    else if(duljinaRijeci > 200) msgBox.setText(krivi_unos);
    else msgBox.setText(prazan_unos);

    msgBox.exec(); //prikazivanje MessageBox-a
}


void MainWindow::on_actionEngleski_triggered()
{
    QString putanja = ":/resursi/parametri/engleski.txt";
    jezik engleski;
    engleski.ucitavanjeParametara(putanja);
    //parametri za tekst
    ui->menuJezik->setTitle(engleski.menuJez);
    ui->actionHrvatski->setText(engleski.actionHrv);
    ui->actionEngleski->setText(engleski.actionEng);
    ui->actionSpanjolski->setText(engleski.actionSpa);
    ui->menuInfo->setTitle(engleski.menuInf);
    ui->actionInfo->setText(engleski.actionInf);
    ui->menuParametri->setTitle(engleski.menuPara);
    ui->actionCustom->setText(engleski.actionCust);
    ui->actionDefault->setText(engleski.actionDef);
    ui->Naslov->setText(engleski.nasl);
    ui->OpisApp->setText(engleski.opis);
    ui->OKgumb->setText(engleski.OKgmb);
    ui->ObrisiGumb->setText(engleski.obrGmb);
    this->setWindowTitle(engleski.MainWinNaslov);
    msgBox.setWindowTitle(engleski.msgBoxNaslov);
    tekst = engleski.msgBxTekst;
    krivi_unos = engleski.msgBxKrivo;
    prazan_unos = engleski.msgBxPrazno;
}

void MainWindow::on_actionHrvatski_triggered()
{
    QString putanja = ":/resursi/parametri/hrvatski.txt";
    jezik hrvatski;
    hrvatski.ucitavanjeParametara(putanja);

    //parametri za tekst
    ui->menuJezik->setTitle(hrvatski.menuJez);
    ui->actionHrvatski->setText(hrvatski.actionHrv);
    ui->actionEngleski->setText(hrvatski.actionEng);
    ui->actionSpanjolski->setText(hrvatski.actionSpa);
    ui->menuInfo->setTitle(hrvatski.menuInf);
    ui->actionInfo->setText(hrvatski.actionInf);
    ui->menuParametri->setTitle(hrvatski.menuPara);
    ui->actionCustom->setText(hrvatski.actionCust);
    ui->actionDefault->setText(hrvatski.actionDef);
    ui->Naslov->setText(hrvatski.nasl);
    ui->OpisApp->setText(hrvatski.opis);
    ui->OKgumb->setText(hrvatski.OKgmb);
    ui->ObrisiGumb->setText(hrvatski.obrGmb);
    this->setWindowTitle(hrvatski.MainWinNaslov);
    msgBox.setWindowTitle(hrvatski.msgBoxNaslov);
    tekst = hrvatski.msgBxTekst;
    krivi_unos = hrvatski.msgBxKrivo;
    prazan_unos = hrvatski.msgBxPrazno;
}

void MainWindow::on_actionSpanjolski_triggered()
{
    QString putanja = ":/resursi/parametri/španjolski.txt";
    jezik spanjolski;
    spanjolski.ucitavanjeParametara(putanja);

    //parametri za tekst
    ui->menuJezik->setTitle(spanjolski.menuJez);
    ui->actionHrvatski->setText(spanjolski.actionHrv);
    ui->actionEngleski->setText(spanjolski.actionEng);
    ui->actionSpanjolski->setText(spanjolski.actionSpa);
    ui->menuInfo->setTitle(spanjolski.menuInf);
    ui->actionInfo->setText(spanjolski.actionInf);
    ui->menuParametri->setTitle(spanjolski.menuPara);
    ui->actionCustom->setText(spanjolski.actionCust);
    ui->actionDefault->setText(spanjolski.actionDef);
    ui->Naslov->setText(spanjolski.nasl);
    ui->OpisApp->setText(spanjolski.opis);
    ui->OKgumb->setText(spanjolski.OKgmb);
    ui->ObrisiGumb->setText(spanjolski.obrGmb);
    this->setWindowTitle(spanjolski.MainWinNaslov);
    msgBox.setWindowTitle(spanjolski.msgBoxNaslov);
    tekst = spanjolski.msgBxTekst;
    krivi_unos = spanjolski.msgBxKrivo;
    prazan_unos = spanjolski.msgBxPrazno;
}

