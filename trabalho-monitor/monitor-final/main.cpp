/*
 PARADIGMAS DE PROGRAMAÇÃO - DCA0201
 Autores: TAYNÁ GLICIA SANTOS DA SILVA GAMELEIRA e FELIPE MATHEUS COSTA SILVA
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
