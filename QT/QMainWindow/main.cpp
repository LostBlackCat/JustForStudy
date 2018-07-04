#include "mainwindow.h"
#include <QApplication>
#include<QSplitter>
#include<QTextEdit>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font ("ZYSong18030",12);
    a.setFont(font);
    //Left
    QSplitter *splitterMain=new QSplitter(Qt::Horizontal,0);
    QTextEdit *textLeft=new QTextEdit(QObject::tr("Left Widget:"),splitterMain);
    textLeft->setAlignment(Qt::AlignCenter);
    //Right
    QSplitter *splitterRight=new QSplitter(Qt::Vertical,splitterMain);
    splitterRight->setOpaqueResize(false);
    QTextEdit *textUp=new QTextEdit(QObject::tr("Top Widget",splitterRight));
    textUp->setAlignment(Qt::AlignCenter);
    QTextEdit *textBottom=new QTextEdit(QObject::tr("Bottom Widget"),splitterRight);
    textBottom->set
    MainWindow w;
    w.show();

    return a.exec();
}
