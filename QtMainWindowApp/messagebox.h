#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H
#include <QString>


class messagebox2
{
public:
    messagebox2();
    void ucitavanjeMsgBoxPar();
    int pretvorbaInt(QString);
    bool pretvorbaBool(QString);
        QString fontFam;
        int fontSiz;
        bool fontKer;
        bool fontIta;
        bool fontBol;
        bool fontStrik;
        bool fontUnderl;
        int pointSiz;
        QString btnTxt;
        QString putanjaIcon;
};

#endif // MESSAGEBOX_H
