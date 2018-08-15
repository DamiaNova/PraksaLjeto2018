#ifndef IZBORIKONA_H
#define IZBORIKONA_H

#include <QDialog>

namespace Ui {
class izborIkona;
}

class izborIkona : public QDialog
{
    Q_OBJECT

public:
    explicit izborIkona(QWidget *parent = nullptr);
    ~izborIkona();

private slots:
    void on_odustaniGmb_clicked();

private:
    Ui::izborIkona *ui;
};

#endif // IZBORIKONA_H
