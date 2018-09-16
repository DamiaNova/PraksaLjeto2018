#ifndef OSTALIPARAMETRI_H
#define OSTALIPARAMETRI_H
#include <QString>

class ostaliparametri
{
public:
    ostaliparametri();
    void ucitavanjeOstalihPar();
    int pretvorbaInt(QString);
    bool pretvorbaBool(QString);
        QString stylSheetLabel;
        QString stylSheetGrpBox;
        QString fontFam;
        int fontSiz;
        bool fontKer;
        bool fontIta;
        bool fontBol;
        bool fontStrik;
        bool fontUnderl;
        int pointSiz;
};

#endif // OSTALIPARAMETRI_H
