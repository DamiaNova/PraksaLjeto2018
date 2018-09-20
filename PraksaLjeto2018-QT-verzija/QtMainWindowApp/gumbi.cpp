#include "gumbi.h"
#include <QFile>
#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>

gumbi::gumbi()
{

}

int gumbi::pretvorbaInt(QString tekst){
    int velicina = tekst.toInt();
    return velicina;
}

bool gumbi::pretvorbaBool(QString tekst){
    bool izraz;
    if (tekst=="true"){ izraz=true; }
    else { izraz=false; }
    return izraz;
}

void gumbi::ucitavanjeGumbPar(){
    QFile gumbiFile2("C:/Users/Mia/Desktop/PraksaLjeto2018-QT-verzija/QtMainWindowApp/parametri/gumbi.txt");
    if(!gumbiFile2.open(QFile::ReadOnly | QFile::Text )){ return; }
    while (!gumbiFile2.atEnd()) {
            QString linija = gumbiFile2.readLine();
            int prviNavodnici = linija.indexOf("\"", 0);
            int drugiNavodnici = linija.indexOf("\"", prviNavodnici+1);
            QString s = QString::number(drugiNavodnici);
            int duljinaPar = drugiNavodnici-prviNavodnici-2;
            QString par = linija.mid(prviNavodnici+1,duljinaPar);
                if (linija.contains("disabled:",Qt::CaseSensitive)){ disbld = pretvorbaBool(par);}
                else if (linija.contains("autoFillBackground:",Qt::CaseSensitive)){ autoFillBg = pretvorbaBool(par);}
                else if (linija.contains("R:",Qt::CaseSensitive)){ R = pretvorbaInt(par); }
                else if (linija.contains("G:",Qt::CaseSensitive)){ G = pretvorbaInt(par);}
                else if (linija.contains("B:",Qt::CaseSensitive)){ B = pretvorbaInt(par);}
                else if (linija.contains("height:",Qt::CaseSensitive)){ visina = pretvorbaInt(par);}
                else if (linija.contains("width:",Qt::CaseSensitive)){ sirina = pretvorbaInt(par);}
                else if (linija.contains("maxVisina:",Qt::CaseSensitive)){ maxVis = pretvorbaInt(par);}
                else if (linija.contains("maxŠirina:",Qt::CaseSensitive)){ maxSir = pretvorbaInt(par); }
                else if (linija.contains("minVisina:",Qt::CaseSensitive)){ minVis = pretvorbaInt(par); }
                else if (linija.contains("minŠirina:",Qt::CaseSensitive)){ minSir = pretvorbaInt(par); }
                else if (linija.contains("fontFamily:",Qt::CaseSensitive)){ fontFam = par; }
                else if (linija.contains("fontPixelSize:",Qt::CaseSensitive)){ fontPixSiz = pretvorbaInt(par); }
                else if (linija.contains("fontKerning:",Qt::CaseSensitive)){ fontKer = pretvorbaBool(par); }
                else if (linija.contains("fontItalic:",Qt::CaseSensitive)){ fontIta = pretvorbaBool(par); }
                else if (linija.contains("fontBold:",Qt::CaseSensitive)){ fontBol = pretvorbaBool(par); }
                else if (linija.contains("fontStrikeout:",Qt::CaseSensitive)){ fontStrik = pretvorbaBool(par); }
                else if (linija.contains("fontUnderline:",Qt::CaseSensitive)){ fontUnderl = pretvorbaBool(par); }
                else if (linija.contains("fontSize:",Qt::CaseSensitive)){ fontSiz = pretvorbaInt(par); }
        }
    gumbiFile2.close();
}
