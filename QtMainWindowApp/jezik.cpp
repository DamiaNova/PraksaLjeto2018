#include "jezik.h"
#include <QFile>

jezik::jezik()
{

}

void jezik::ucitavanjeParametara(QString putanja){
    this->putanja = putanja;
    QFile parametri (putanja);
    //otvaranje QFile-a u ReadOnly mode-u
    if(!parametri.open(QFile::ReadOnly | QFile::Text )){
        return;
    }
    while (!parametri.atEnd()) {
            QString linija = parametri.readLine();
            int prviNavodnici = linija.indexOf("\"", 0);
            int drugiNavodnici = linija.indexOf("\"", prviNavodnici+1);
            int duljinaPar = drugiNavodnici-prviNavodnici-1;
            QString s = QString::number(drugiNavodnici);
            QString par = linija.mid(prviNavodnici+1,duljinaPar);
                if (linija.contains("menuJezik:",Qt::CaseSensitive)){ menuJez = par;}
                else if (linija.contains("actionHrvatski:",Qt::CaseSensitive)){ actionHrv = par;}
                else if (linija.contains("actionEngleski:",Qt::CaseSensitive)){ actionEng = par;}
                else if (linija.contains("actionSpanjolski:",Qt::CaseSensitive)){ actionSpa = par;}
                else if (linija.contains("menuParametri:",Qt::CaseSensitive)){ menuPara = par;}
                else if (linija.contains("actionDefault:",Qt::CaseSensitive)){ actionDef = par;}
                else if (linija.contains("actionCustom:",Qt::CaseSensitive)){ actionCust = par;}
                else if (linija.contains("menuInfo:",Qt::CaseSensitive)){ menuInf = par;}
                else if (linija.contains("actionInfo:",Qt::CaseSensitive)){ actionInf = par;}
                else if (linija.contains("naslovProzora:",Qt::CaseSensitive)){ nasl = par;}
                else if (linija.contains("opisAplikacije:",Qt::CaseSensitive)){ opis = par;}
                else if (linija.contains("OKgumb:",Qt::CaseSensitive)){ OKgmb = par;}
                else if (linija.contains("obrisiGumb:",Qt::CaseSensitive)){ obrGmb = par;}
        }
}
