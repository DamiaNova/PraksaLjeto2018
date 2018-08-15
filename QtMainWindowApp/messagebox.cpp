#include "messagebox.h"
#include <QFile>

messagebox2::messagebox2()
{

}

int messagebox2::pretvorbaInt(QString tekst){
    int velicina = tekst.toInt();
    return velicina;
}

bool messagebox2::pretvorbaBool(QString tekst){
    bool izraz;
    if (tekst=="true"){ izraz=true; }
    else { izraz=false; }
    return izraz;
}

void messagebox2::ucitavanjeMsgBoxPar(){

    QString putanjaMsgBox=":/resursi/parametri/messageBox.txt";
    QFile msgBxPar(putanjaMsgBox);
    if(!msgBxPar.open(QFile::ReadOnly | QFile::Text )){ return; }
    while (!msgBxPar.atEnd()) {
            QString linija = msgBxPar.readLine();
            int prviNavodnici = linija.indexOf("\"", 0);
            int drugiNavodnici = linija.indexOf("\"", prviNavodnici+1);
            QString s = QString::number(drugiNavodnici);
            int duljinaPar = drugiNavodnici-prviNavodnici-1;
            QString par = linija.mid(prviNavodnici+1,duljinaPar);
                if (linija.contains("fontFamily:",Qt::CaseSensitive)){ fontFam = par;}
                else if (linija.contains("fontPixelSize:",Qt::CaseSensitive)){ fontSiz = pretvorbaInt(par); }
                else if (linija.contains("fontKerning:",Qt::CaseSensitive)){ fontKer = pretvorbaBool(par);}
                else if (linija.contains("fontItalic:",Qt::CaseSensitive)){ fontIta = pretvorbaBool(par);}
                else if (linija.contains("fontBold:",Qt::CaseSensitive)){ fontBol = pretvorbaBool(par);}
                else if (linija.contains("fontStrikeout:",Qt::CaseSensitive)){ fontStrik = pretvorbaBool(par);}
                else if (linija.contains("fontUnderline:",Qt::CaseSensitive)){ fontUnderl = pretvorbaBool(par);}
                else if (linija.contains("fontPointSize:",Qt::CaseSensitive)){ pointSiz = pretvorbaInt(par); }
                else if (linija.contains("buttonText:",Qt::CaseSensitive)){ btnTxt = par; }
                else if (linija.contains("putanjaIkone:",Qt::CaseSensitive)){ putanjaIcon = par; }
        }
}
