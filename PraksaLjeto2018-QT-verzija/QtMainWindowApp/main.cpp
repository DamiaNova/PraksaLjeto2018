#include "mainwindow.h" //header file
#include <QApplication>
#include <QFont>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //parametri za Main Window
    w.setFixedHeight(538);
    w.setFixedWidth(471);
    w.setWindowTitle("Moja prva aplikacija");
    QFont font;
    font.setFamily("MS Shell Dig 2");
    font.setPixelSize(8);
    font.setKerning(true);
    font.setItalic(false);
    font.setBold(false);
    font.setStrikeOut(false);
    font.setUnderline(false);
    w.setFont(font);
    QCursor kursor;
    kursor.setShape(Qt::ArrowCursor);
    w.setCursor(kursor);
    QPixmap ikona (":/resursi/icons/pingu.ico");
    w.setWindowIcon(ikona);
    w.setMaximumHeight(1000);
    w.setMaximumWidth(1000);

    w.show();
    return a.exec(); //vraća objekt QAppliacation-a
}
