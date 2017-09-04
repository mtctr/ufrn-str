/*
 PARADIGMAS DE PROGRAMAÇÃO - DCA0201
 Autores: TAYNÁ GLICIA SANTOS DA SILVA GAMELEIRA e FELIPE MATHEUS COSTA SILVA
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTime>
#include <QQueue>
namespace Ui {
/**
 * @brief The MainWindow class shows the GUI defined by mainwindow.ui
 * for the QtTcpClientConsumer.
 */
class MainWindow;
}

class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief MainWindow() is the class constructor.
     */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();public slots:

    /**
     * @brief getList() retrieves the server for the providers' adresses.
     * connection.
     */
    /**
     * @brief getData() reads the full message history availlable at the server and
     * sends the last 10 samples for the Grafico::plot() method for plotting purposes.
     */
    void getData();
    /**
     * @brief timerEvent(QTimerEvent *e) handles the timed event by calling the
     * getData method.
     * @param *e is the event listener
     */
    void timerEvent(QTimerEvent *e);
     /**
     * @brief start() triggers the data receving process to the connected server
     * from a specified sender (as selected on the providers list).
     */
    void start();
    /**
     * @brief stop() pauses the data receiving process.
     */

    void filtrar();

    void validarPID();
    void pausarProcesso();
    void continuarProcesso();
    void matarProcesso();
    void validarPidCpu();
    void trocarCpu();
    void cpuUsage();

private:
    Ui::MainWindow *ui;
    int timerID;
    bool running;
    QString command = "";
    QQueue<double> amostras;
    QVector<double> amostrasVector;

};

#endif // MAINWINDOW_H
