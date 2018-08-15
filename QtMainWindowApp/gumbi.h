#ifndef GUMBI_H
#define GUMBI_H
#include <QString>


class gumbi
{
public:
    gumbi();
    void ucitavanjeGumbPar();
    int pretvorbaInt(QString);
    bool pretvorbaBool(QString);
        bool disbld;
        bool autoFillBg;
        int R;
        int G;
        int B;
        int visina;
        int sirina;
        int maxVis;
        int maxSir;
        int minVis;
        int minSir;
        QString fontFam;
        int fontSiz;
        bool fontKer;
        bool fontIta;
        bool fontBol;
        bool fontStrik;
        bool fontUnderl;
        int pointSiz;
};

#endif // GUMBI_H
