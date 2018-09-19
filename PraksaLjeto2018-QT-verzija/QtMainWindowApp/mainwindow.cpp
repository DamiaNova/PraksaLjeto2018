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
#include "izborikona.h"
#include <QPixmap>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), //konstruktor
    ui(new Ui::MainWindow) //inicijalizira ui objekt sa novim MainWindow-om
{
    ui->setupUi(this); //objekt se zove "setupUi" koji otvara naš prozor

    //TIMER
    timer = new QTimer(this); //inicijalizacija timer
    connect(timer, &QTimer::timeout,this,&MainWindow::funkcija);
    timer->start(500); //vrijeme u milisekundama

    //TIMER ENGLESKI
    on_click_timer_eng = new QTimer(this);
    connect(on_click_timer_eng,&QTimer::timeout,this,&MainWindow::on_click_funkcija_engleski);

    //TIMER HRVATSKI
    on_click_timer_hrv = new QTimer(this);
    connect(on_click_timer_hrv,&QTimer::timeout,this,&MainWindow::on_click_funkcija_hrvatski);

    //TIMER ŠPANJOLSKI
    on_click_timer_spa = new QTimer(this);
    connect(on_click_timer_spa,&QTimer::timeout,this,&MainWindow::on_click_funkcija_spanjolski);

    //TIMER MESSAGE BOX OK
    on_click_timer_msgBox_OK = new QTimer(this);
    connect(on_click_timer_msgBox_OK,&QTimer::timeout,this,&MainWindow::on_click_funkcija_msgBox_OK);

    //TIMER MESSAGE BOX INFO
    on_click_timer_msgBox_Info = new QTimer(this);
    connect(on_click_timer_msgBox_Info,&QTimer::timeout,this,&MainWindow::on_click_funkcija_msgBox_Info);

     ui->actionHrvatski->triggered(true); //defaultno odabrani jezik je hrvatski

    //parametri za InputLine (LineEdit widget)
    //INICIJALNI PARAMETRI ZA INPUT LINE
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
    //ZA GUMBE:
    OK =ui->OKgumb;
    Obrisi = ui->ObrisiGumb;
    gumbici = { OK, Obrisi };

    //ZA OSTALE PARAMETRE:
    naslov =ui->Naslov;
    opis = ui->OpisApp;
    etikete  = { naslov, opis };

    //INICIJALNI PARAMETRI
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


//Postavljanje parametara svakih 0.5 sekundi
void MainWindow::funkcija()
{
    //GUMBI:
    g.ucitavanjeGumbPar();
    for (int i=0;i<2;i++){
        //parametri za gumbe
        gumb=gumbici[i];
        gumb->setDisabled(g.disbld);
        gumb->setAutoFillBackground(g.autoFillBg);
        QPalette pal = gumb->palette();
        pal.setColor(QPalette::Button, QColor(g.R,g.G,g.B));
        gumb->setPalette(pal);
        gumb->setFixedHeight(g.visina);
        gumb->setFixedWidth(g.sirina);
        gumb->setMaximumHeight(g.maxSir);
        gumb->setMaximumWidth(g.maxVis);
        gumb->setMinimumHeight(g.minVis);
        gumb->setMinimumWidth(g.minSir);
        fontGumb.setFamily(g.fontFam);
        fontGumb.setPixelSize(g.fontPixSiz);
        fontGumb.setKerning(g.fontKer);
        fontGumb.setItalic(g.fontIta);
        fontGumb.setBold(g.fontBol);
        fontGumb.setStrikeOut(g.fontStrik);
        fontGumb.setUnderline(g.fontUnderl);
        fontGumb.setPointSize(g.fontSiz);
        gumb->setFont(fontGumb);
    }

    //OSTALI PARAMETRI (LABEL, GROUP, MENU BAR):
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
    //ZA INPUT LINE (Q LINE EDIT):
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
}


//kada kliknemo gumb Obriši
void MainWindow::on_ObrisiGumb_clicked()
{
    ui->InputLine->selectAll();
    ui->InputLine->del();
}

void MainWindow::on_click_funkcija_msgBox_OK(){
    //parametri za OK gumb
    mBox.ucitavanjeMsgBoxPar();
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

}

void MainWindow::on_click_funkcija_msgBox_Info(){
    //parametri za Info prozor
    mBox.ucitavanjeMsgBoxPar();
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
}

//kada kliknemo gumb OK
void MainWindow::on_OKgumb_clicked()
{
    //pokreće timer koji pokreće učitavanje i postavljanje parametara
    on_click_timer_msgBox_OK->start(100);

    rijec = ui->InputLine->text(); //unesena riječ
    int duljinaRijeci = rijec.length();
    rijec.insert(0,tekst);
    rijec.append("'");

    if ( (duljinaRijeci > 0) && (duljinaRijeci <= 200)) msgBox.setText(rijec);
    else if(duljinaRijeci > 200) msgBox.setText(krivi_unos);
    else msgBox.setText(prazan_unos);

    msgBox.exec(); //prikazivanje MessageBox-a
}


//ENGLESKI
void MainWindow::on_actionEngleski_triggered()
{
    for (int i=0;i<2;i++){
        if(on_click_timer_spa->isActive()) on_click_timer_spa->stop();
        else if(on_click_timer_hrv->isActive()) on_click_timer_hrv->stop();
        else if (!on_click_timer_eng->isActive()) on_click_timer_eng->start(100);
        else return;
    }
}
void MainWindow::on_click_funkcija_engleski(){
    putanja =  "C:/Users/Mia/Desktop/PraksaLjeto2018-QT-verzija/QtMainWindowApp/parametri/engleski.txt";
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

//HRVATSKI
void MainWindow::on_actionHrvatski_triggered()
{      
    for (int i=0;i<2;i++){
        if(on_click_timer_spa->isActive()) on_click_timer_spa->stop();
        else if(on_click_timer_eng->isActive()) on_click_timer_eng->stop();
        else if (!on_click_timer_hrv->isActive()) on_click_timer_hrv->start(100);
        else return;
    }
}
void MainWindow::on_click_funkcija_hrvatski(){
    putanja = "C:/Users/Mia/Desktop/PraksaLjeto2018-QT-verzija/QtMainWindowApp/parametri/hrvatski.txt";
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

//ŠPANJOLSKI
void MainWindow::on_actionSpanjolski_triggered()
{
    for (int i=0;i<2;i++){
        if(on_click_timer_hrv->isActive()) on_click_timer_hrv->stop();
        else if(on_click_timer_eng->isActive()) on_click_timer_eng->stop();
        else if (!on_click_timer_spa->isActive()) on_click_timer_spa->start(100);
        else return;
    }
}
void MainWindow::on_click_funkcija_spanjolski(){
    putanja = "C:/Users/Mia/Desktop/PraksaLjeto2018-QT-verzija/QtMainWindowApp/parametri/španjolski.txt";
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
    on_click_timer_msgBox_Info->start();
    prozor.exec();
}

void MainWindow::on_actionCustom_triggered()
{
    izborIkona izbIkona;
    izbIkona.setModal(true);
    izbIkona.exec();
}
