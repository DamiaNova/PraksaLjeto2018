#include "inputline.h"
#include <QFile>

inputline::inputline()
{

}

int inputline::pretvorbaInt(QString tekst){
    int velicina = tekst.toInt();
    return velicina;
}

bool inputline::pretvorbaBool(QString tekst){
    bool izraz;
    if (tekst=="true"){ izraz=true; }
    else { izraz=false; }
    return izraz;
}

void inputline::ucitavanjeInputPar(){

    QString putanjaInputLine=":/resursi/parametri/QLineEdit.txt";
    QFile inputLinePar(putanjaInputLine);
    if(!inputLinePar.open(QFile::ReadOnly | QFile::Text )){ return; }
    while (!inputLinePar.atEnd()) {
            QString linija = inputLinePar.readLine();
            int prviNavodnici = linija.indexOf("\"", 0);
            int drugiNavodnici = linija.indexOf("\"", prviNavodnici+1);
            QString s = QString::number(drugiNavodnici);
            int duljinaPar = drugiNavodnici-prviNavodnici-1;
            QString par = linija.mid(prviNavodnici+1,duljinaPar);
                if (linija.contains("placeholderText:",Qt::CaseSensitive)){ placeholderTxt = par;}
                else if (linija.contains("fontFamily:",Qt::CaseSensitive)){ fontFam = par;}
                else if (linija.contains("fontPixelSize:",Qt::CaseSensitive)){ fontSiz = pretvorbaInt(par); }
                else if (linija.contains("fontKerning:",Qt::CaseSensitive)){ fontKer = pretvorbaBool(par);}
                else if (linija.contains("fontItalic:",Qt::CaseSensitive)){ fontIta = pretvorbaBool(par);}
                else if (linija.contains("fontBold:",Qt::CaseSensitive)){ fontBol = pretvorbaBool(par);}
                else if (linija.contains("fontStrikeout:",Qt::CaseSensitive)){ fontStrik = pretvorbaBool(par);}
                else if (linija.contains("fontUnderline:",Qt::CaseSensitive)){ fontUnderl = pretvorbaBool(par);}
                else if (linija.contains("X-poicija:",Qt::CaseSensitive)){ xPoz = pretvorbaInt(par); }
                else if (linija.contains("Y-pozicija:",Qt::CaseSensitive)){ yPoz = pretvorbaInt(par); }
                else if (linija.contains("širina:",Qt::CaseSensitive)){ sirina = pretvorbaInt(par); }
                else if (linija.contains("visina:",Qt::CaseSensitive)){ visina = pretvorbaInt(par); }
                else if (linija.contains("maxVisina:",Qt::CaseSensitive)){ maxVis = pretvorbaInt(par); }
                else if (linija.contains("maxŠirina:",Qt::CaseSensitive)){ maxSir = pretvorbaInt(par); }
                else if (linija.contains("minVisina:",Qt::CaseSensitive)){ minVis = pretvorbaInt(par); }
                else if (linija.contains("minŠirina:",Qt::CaseSensitive)){ minSir = pretvorbaInt(par); }
        }
}
