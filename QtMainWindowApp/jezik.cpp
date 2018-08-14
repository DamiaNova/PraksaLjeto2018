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
            if (linija.contains("menuJezik:",Qt::CaseSensitive))menuJez="blabla";
    }
}
