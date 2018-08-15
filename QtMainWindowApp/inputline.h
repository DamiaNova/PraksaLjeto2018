#ifndef INPUTLINE_H
#define INPUTLINE_H
#include <QString>


class inputline
{
public:
    inputline();
    void ucitavanjeInputPar();
    int pretvorbaInt(QString);
    bool pretvorbaBool(QString);
        QString placeholderTxt;
        QString fontFam;
        int fontSiz;
        bool fontKer;
        bool fontIta;
        bool fontBol;
        bool fontStrik;
        bool fontUnderl;
        int xPoz;
        int yPoz;
        int sirina;
        int visina;
        int maxVis;
        int maxSir;
        int minVis;
        int minSir;
};

#endif // INPUTLINE_H
