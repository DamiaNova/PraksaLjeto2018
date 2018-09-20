#include "ostaliparametri.h"
#include <QFile>

ostaliparametri::ostaliparametri()
{

}

int ostaliparametri::pretvorbaInt(QString tekst){
    int velicina = tekst.toInt();
    return velicina;
}

bool ostaliparametri::pretvorbaBool(QString tekst){
    bool izraz;
    if (tekst=="true"){ izraz=true; }
    else { izraz=false; }
    return izraz;
}

void ostaliparametri::ucitavanjeOstalihPar(){
    QFile ostaliPar("C:/Users/Mia/Desktop/PraksaLjeto2018-QT-verzija/QtMainWindowApp/parametri/ostaliParametri.txt");
    if(!ostaliPar.open(QFile::ReadOnly | QFile::Text )){ return; }
    while (!ostaliPar.atEnd()) {
            QString linija = ostaliPar.readLine();
            int prviNavodnici = linija.indexOf("\"", 0);
            int drugiNavodnici = linija.indexOf("\"", prviNavodnici+1);
            QString s = QString::number(drugiNavodnici);
            int duljinaPar = drugiNavodnici-prviNavodnici-2;
            QString par = linija.mid(prviNavodnici+1,duljinaPar);
                if (linija.contains("Style sheetQLabel:",Qt::CaseSensitive)){ stylSheetLabel = par;}
                else if (linija.contains("Style sheetQGroupBox:",Qt::CaseSensitive)){ stylSheetGrpBox = par;}
                else if (linija.contains("fontFamily:",Qt::CaseSensitive)){ fontFam = par;}
                else if (linija.contains("fontSize:",Qt::CaseSensitive)){ fontSiz = pretvorbaInt(par); }
                else if (linija.contains("fontKerning:",Qt::CaseSensitive)){ fontKer = pretvorbaBool(par);}
                else if (linija.contains("fontItalic:",Qt::CaseSensitive)){ fontIta = pretvorbaBool(par);}
                else if (linija.contains("fontBold:",Qt::CaseSensitive)){ fontBol = pretvorbaBool(par);}
                else if (linija.contains("fontStrikeout:",Qt::CaseSensitive)){ fontStrik = pretvorbaBool(par);}
                else if (linija.contains("fontUnderline:",Qt::CaseSensitive)){ fontUnderl = pretvorbaBool(par);}
                else if (linija.contains("pointSize:",Qt::CaseSensitive)){ pointSiz = pretvorbaInt(par); }
        }
    ostaliPar.close();
}
