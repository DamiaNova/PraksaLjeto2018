#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "jezik.h"
#include "jezik.cpp"
#include "inputline.h"
#include "inputline.cpp"
#include "gumbi.h"
#include "ostaliparametri.h"
#include "messagebox.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), //konstruktor
    ui(new Ui::MainWindow) //inicijalizira ui objekt sa novim MainWindow-om
{
    ui->setupUi(this); //objekt se zove "setupUi" koji otvara naš prozor

     ui->actionHrvatski->triggered(true);
     mBox.ucitavanjeMsgBoxPar();

    //parametri za InputLine (LineEdit widget)
    inputline inputPar;
    inputPar.ucitavanjeInputPar();
    ui->InputLine->setPlaceholderText(inputPar.placeholderTxt);
    ilFont.setFamily(inputPar.fontFam);
    ilFont.setPixelSize(inputPar.fontSiz);
    ilFont.setKerning(inputPar.fontKer);
    ilFont.setItalic(inputPar.fontIta);
    ilFont.setBold(inputPar.fontBol);
    ilFont.setStrikeOut(inputPar.fontStrik);
    ilFont.setUnderline(inputPar.fontUnderl);
    ui->InputLine->setFont(ilFont);
    int x = inputPar.xPoz;
    int y = inputPar.yPoz;
    int width=inputPar.sirina;
    int height=inputPar.visina;
    ui->InputLine->setGeometry(x,y,width,height);
    ui->InputLine->setMaximumHeight(inputPar.maxVis);
    ui->InputLine->setMaximumWidth(inputPar.maxSir);
    ui->InputLine->setMinimumHeight(inputPar.minVis);
    ui->InputLine->setMinimumWidth(inputPar.minSir);

    //stvaranje liste koja sadrži oba QPushButton-a
    QPushButton *gumb;
    QPushButton *OK =ui->OKgumb;
    QPushButton *Obrisi = ui->ObrisiGumb;
    QList <QPushButton *> gumbici = { OK, Obrisi };
    gumbi gmb;
    gmb.ucitavanjeGumbPar();

    for (int i=0;i<2;i++){
        //parametri za gumbe
        gumb=gumbici[i];
        gumb->setDisabled(gmb.disbld);
        gumb->setAutoFillBackground(gmb.autoFillBg);
        QPalette pal = gumb->palette();
        pal.setColor(QPalette::Button, QColor(gmb.R,gmb.G,gmb.B));
        gumb->setPalette(pal);
        gumb->setFixedHeight(gmb.visina);
        gumb->setFixedWidth(gmb.sirina);
        gumb->setMaximumHeight(gmb.maxSir);
        gumb->setMaximumWidth(gmb.maxVis);
        gumb->setMinimumHeight(gmb.minVis);
        gumb->setMinimumWidth(gmb.minSir);
        fontGumb.setFamily(gmb.fontFam);
        fontGumb.setPixelSize(gmb.fontSiz);
        fontGumb.setKerning(gmb.fontKer);
        fontGumb.setItalic(gmb.fontIta);
        fontGumb.setBold(gmb.fontBol);
        fontGumb.setStrikeOut(gmb.fontStrik);
        fontGumb.setUnderline(gmb.fontUnderl);
        fontGumb.setPointSize(gmb.pointSiz);
        gumb->setFont(fontGumb);
    }

    //stvaranje liste koja sadrži oba QLabel-a
    QLabel *etiketa;
    QLabel *naslov =ui->Naslov;
    QLabel *opis = ui->OpisApp;
    QList <QLabel *> etikete  = { naslov, opis };

    ostaliparametri ostPar;
    ostPar.ucitavanjeOstalihPar();

    for (int i=0;i<2;i++){
        //parametri za etikete
        etiketa=etikete[i];
        etiketa->setStyleSheet(ostPar.stylSheetLabel);
    }

    //parametri za QGroupBox
    ui->groupBox->setStyleSheet(ostPar.stylSheetGrpBox);

    //parametri za QMenuBar
    fontMenu.setFamily(ostPar.fontFam);
    fontMenu.setPixelSize(ostPar.fontSiz);
    fontMenu.setKerning(ostPar.fontKer);
    fontMenu.setItalic(ostPar.fontIta);
    fontMenu.setBold(ostPar.fontBol);
    fontMenu.setStrikeOut(ostPar.fontStrik);
    fontMenu.setUnderline(ostPar.fontUnderl);
    fontMenu.setPointSize(ostPar.pointSiz);
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
    fontMsgBox.setFamily(mBox.fontFam);
    fontMsgBox.setPixelSize(mBox.fontSiz);
    fontMsgBox.setKerning(mBox.fontKer);
    fontMsgBox.setItalic(mBox.fontIta);
    fontMsgBox.setBold(mBox.fontBol);
    fontMsgBox.setStrikeOut(mBox.fontStrik);
    fontMsgBox.setUnderline(mBox.fontUnderl);
    fontMsgBox.setPointSize(mBox.pointSiz);
    msgBox.setFont(fontMsgBox);
    msgBox.setButtonText(1,mBox.btnTxt);

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
    prozor.setWindowTitle(engleski.msgBoxNaslov);
    prozor.setText(engleski.prozorTekst);
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
    prozor.setWindowTitle(hrvatski.msgBoxNaslov);
    prozor.setText(hrvatski.prozorTekst);
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
    prozor.setWindowTitle(spanjolski.msgBoxNaslov);
    prozor.setText(spanjolski.prozorTekst);
    tekst = spanjolski.msgBxTekst;
    krivi_unos = spanjolski.msgBxKrivo;
    prazan_unos = spanjolski.msgBxPrazno;
}


void MainWindow::on_actionInfo_triggered()
{
    QPixmap ikonaProzor (":/resursi/icons/turtle.ico");
    prozor.setWindowIcon(ikonaProzor);
    fontProzor.setFamily(mBox.fontFam);
    fontProzor.setPixelSize(mBox.fontSiz);
    fontProzor.setKerning(mBox.fontKer);
    fontProzor.setItalic(mBox.fontIta);
    fontProzor.setBold(mBox.fontBol);
    fontProzor.setStrikeOut(mBox.fontStrik);
    fontProzor.setUnderline(mBox.fontUnderl);
    fontProzor.setPointSize(mBox.pointSiz);
    prozor.setFont(fontProzor);
    prozor.setButtonText(1,mBox.btnTxt);
    prozor.setIconPixmap(QPixmap(mBox.putanjaIcon));
    prozor.exec();
}
