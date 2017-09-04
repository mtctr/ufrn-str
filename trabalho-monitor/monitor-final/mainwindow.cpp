#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QProcess>
#include <regex>
#include <signal.h>
#include <sched.h>
#define _GNU_SOURCE


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->pausarButton->setEnabled(false);
    ui->continuarButton->setEnabled(false);
    ui->trocarCpuButton->setEnabled(false);
    ui->encerrarButton->setEnabled(false);


    ui->cpuUsage_1->setRange(0,100);
    ui->cpuUsage_2->setRange(0,100);
    ui->cpuUsage_3->setRange(0,100);
    ui->cpuUsage_4->setRange(0,100);

    for(int i=0;i< 120; i++){
        amostras.enqueue(0);
    }

    ui->tableWidget->setColumnCount(11);
    ui->tableWidget->setColumnWidth(0, 40);
    ui->tableWidget->setColumnWidth(1, 40);
    ui->tableWidget->setColumnWidth(2, 50);
    ui->tableWidget->setColumnWidth(3, 30);
    ui->tableWidget->setColumnWidth(4, 50);
    ui->tableWidget->setColumnWidth(5, 85);
    ui->tableWidget->setColumnWidth(6, 50);
    ui->tableWidget->setColumnWidth(7, 60);
    ui->tableWidget->setColumnWidth(8, 75);
    ui->tableWidget->setColumnWidth(9, 85);
    ui->tableWidget->setColumnWidth(10, 399);

    QStringList header;
    ui->tableWidget->verticalHeader()->setVisible(false);

    header << "UID"<< "PID" << "PPID"<< "CPU" << "%CPU" << "STATE" << "RSS" << "VSZ"  << "STIME" << "TIME" << "COMMAND";
    ui->tableWidget->setHorizontalHeaderLabels(header);

    start();
}

void MainWindow::start() {
        running = true;
        timerID = startTimer(500);
        qDebug() << "Started";
}



void MainWindow::timerEvent(QTimerEvent *) {
    getData();
    cpuUsage();
}

void MainWindow::cpuUsage(){
    QString stdout;
    QString stderr;

    QStringList list;
    QProcess ps;

    ps.start("ps -e -o psr= -o %cpu=");
    ps.waitForFinished(-1);
    stdout = ps.readAllStandardOutput();
    stderr = ps.readAllStandardError();


    list = stdout.split(QRegExp("\\s|\\n"), QString::SkipEmptyParts);

    int cpuUsage_1 = 0;
    int cpuUsage_2 = 0;
    int cpuUsage_3 = 0;
    int cpuUsage_4 = 0;
    int cpuUsage_soma = 0;
    for(int i = 1; i < list.length(); i+=2){
        if(list.at(i-1) == "0"){
            cpuUsage_1 += list.at(i).toDouble();
        }else if(list.at(i-1) == "1"){
            cpuUsage_2 += list.at(i).toDouble();
        }else if(list.at(i-1) == "2"){
            cpuUsage_3 += list.at(i).toDouble();
        }else if(list.at(i-1) == "3"){
            cpuUsage_4 += list.at(i).toDouble();
        }
        cpuUsage_soma += list.at(i).toDouble();
    }


    ui->cpuUsage_1->setValue(cpuUsage_1);
    ui->cpuUsage_2->setValue(cpuUsage_2);
    ui->cpuUsage_3->setValue(cpuUsage_3);
    ui->cpuUsage_4->setValue(cpuUsage_4);

     QVector<double> q = QVector<double>::fromList(amostras);

    if(q.size() >= 120){
        amostras.dequeue();
        amostras.enqueue(cpuUsage_soma);
    }else
        amostras.enqueue(cpuUsage_soma);
    q = QVector<double>::fromList(amostras);


    // add two new graphs and set their look:
    ui->plot->addGraph();
    ui->plot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    ui->plot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue

    // generate some points of data (y0 for first, y1 for second graph):
    QVector<double> x(120), y1(100);
    for (int i=0; i<120; ++i)
    {
      x[i] = i;
    }
    for (int i=0; i<100; ++i)
    {
      y1[i] = i+(2*i);
    }
    // configure right and top axis to show ticks but no labels:
    // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
    ui->plot->xAxis2->setVisible(true);
    ui->plot->xAxis2->setTickLabels(false);
    ui->plot->yAxis2->setVisible(true);
    ui->plot->yAxis2->setTickLabels(false);
    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(ui->plot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->plot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->yAxis2, SLOT(setRange(QCPRange)));

    ui->plot->xAxis->setRange(0, 120);
    ui->plot->yAxis->setRange(0, 100);
    ui->plot->xAxis->setTickLabels(false);
    ui->plot->setContentsMargins(0,0,0,0);
    // pass data points to graphs:
    ui->plot->graph(0)->setData(x, q);
    ui->plot->replot();


}

void MainWindow::filtrar(){
    command = ui->command->text();
}
void MainWindow::validarPID(){
    QString stdout;
    QString stderr;

    QString stdoutStatus;
    QString stderrStatus;

    QStringList list;
    QProcess ps, status;

    ps.start("ps -e -o pid=");
    ps.waitForFinished(-1);

    stdout = ps.readAllStandardOutput();
    stderr = ps.readAllStandardError();


   list = stdout.split(QRegExp("\\s|\\n"), QString::SkipEmptyParts);

    if(list.contains(ui->pidText->text())){
        status.start("ps -o state= -p " + ui->pidText->text());
        status.waitForFinished(-1);

        stdoutStatus = status.readAllStandardOutput();
        stderrStatus = status.readAllStandardError();

        QString s = stdoutStatus.at(0);
        ui->encerrarButton->setEnabled(true);

        if(s == "T"){
            ui->pausarButton->setEnabled(false);
            ui->continuarButton->setEnabled(true);
        }else{
            ui->pausarButton->setEnabled(true);
            ui->continuarButton->setEnabled(false);
        }
    }else{
        ui->pausarButton->setEnabled(false);
        ui->continuarButton->setEnabled(false);
        ui->encerrarButton->setEnabled(false);

    }

}
void MainWindow::validarPidCpu(){
    QString stdout;
    QString stderr;

    QString stdoutStatus;
    QString stderrStatus;

    QStringList list;
    QProcess ps, cpu;

    ps.start("ps -e -o pid=");
    ps.waitForFinished(-1);

    stdout = ps.readAllStandardOutput();
    stderr = ps.readAllStandardError();

    cpu.start("nproc");
    cpu.waitForFinished(-1);
    stdoutStatus = cpu.readAllStandardOutput();
    stderrStatus = cpu.readAllStandardError();
    qDebug() << ui->cpuText->text().toInt();

    list = stdout.split(QRegExp("\\s|\\n"), QString::SkipEmptyParts);
    if(list.contains(ui->pidCpuText->text()) && (ui->cpuText->text().toInt() < (stdoutStatus.toInt())) && !ui->cpuText->text().isEmpty() ){
        ui->trocarCpuButton->setEnabled(true);
    }else{
        ui->trocarCpuButton->setEnabled(false);
    }
}

void MainWindow::trocarCpu() {
    cpu_set_t  mask;
    CPU_ZERO(&mask);
    CPU_SET(ui->cpuText->text().toInt() - 1, &mask);
    sched_setaffinity(ui->pidCpuText->text().toInt(), sizeof(mask), &mask);
}
void MainWindow::pausarProcesso() {
    kill(ui->pidText->text().toInt(), SIGSTOP);
    ui->continuarButton->setEnabled(true);
    ui->pausarButton->setEnabled(false);

}
void MainWindow::continuarProcesso() {
    kill(ui->pidText->text().toInt(), SIGCONT);
    ui->pausarButton->setEnabled(true);
    ui->continuarButton->setEnabled(false);

}
void MainWindow::matarProcesso() {
    kill(ui->pidText->text().toInt(), SIGKILL);
    ui->encerrarButton->setEnabled(false);

}

void MainWindow::getData() {
    QProcess ps, grep;

    if(!command.isEmpty())
        ps.setStandardOutputProcess(&grep);

    ps.start("ps -e -o uid= -o pid= -o ppid= -o psr= -o %cpu= -o state= -o rss= -o vsz= -o stime= -o time= -o  comm= ");
    grep.start("grep " + command);

    ps.waitForFinished(-1);
    grep.waitForFinished(-1);


    QString stdout;
    QString stderr;

    if(command.isEmpty()){
       stdout = ps.readAllStandardOutput();
       stderr = ps.readAllStandardError();
    }else{
        stdout = grep.readAllStandardOutput();
        stderr = grep.readAllStandardError();

    }

   stdout = stdout.replace(QRegExp("([a-zA-Z]|[.,\/#!$%\^&\*;:{}=\-_`~()<>])\\s(?=([a-zA-Z]|[.,\/#!$%\^&\*;:{}=\-_`~()<>]))"),"_");

    QStringList list = stdout.split(QRegExp("\\s|\\n"), QString::SkipEmptyParts);

    ui->tableWidget->setRowCount(list.length()/11);

    int columnCount = 0;
    int rowCount = 0;
    for(int i = 0; i<list.length(); i++){
       if(columnCount == 5){
           if(list.at((rowCount * 11)+columnCount) == "R"){
                ui->tableWidget->setItem(rowCount, columnCount, new QTableWidgetItem("RODANDO"));
           }else if(list.at((rowCount * 11)+columnCount)== "S"){
               ui->tableWidget->setItem(rowCount, columnCount, new QTableWidgetItem("RODANDO"));
           }else if(list.at((rowCount * 11)+columnCount) == "D"){
               ui->tableWidget->setItem(rowCount, columnCount, new QTableWidgetItem("MORTO"));
           }else if(list.at((rowCount * 11)+columnCount) == "T"){
               ui->tableWidget->setItem(rowCount, columnCount, new QTableWidgetItem("PARADO"));
           }else if(list.at((rowCount * 11)+columnCount) == "Z"){
               ui->tableWidget->setItem(rowCount, columnCount, new QTableWidgetItem("ERROR"));
           }
       }else if(columnCount == 3){
           if(list.at((rowCount * 11)+columnCount) == "0"){
                ui->tableWidget->setItem(rowCount, columnCount, new QTableWidgetItem("1"));
           }else if(list.at((rowCount * 11)+columnCount)== "1"){
               ui->tableWidget->setItem(rowCount, columnCount, new QTableWidgetItem("2"));
           }else if(list.at((rowCount * 11)+columnCount) == "2"){
               ui->tableWidget->setItem(rowCount, columnCount, new QTableWidgetItem("3"));
           }else if(list.at((rowCount * 11)+columnCount) == "3"){
               ui->tableWidget->setItem(rowCount, columnCount, new QTableWidgetItem("4"));
           }
       }else
            ui->tableWidget->setItem(rowCount, columnCount, new QTableWidgetItem(list.at((rowCount * 11)+columnCount)));
               columnCount++;
       if(columnCount != 11)
           ui->tableWidget->item(rowCount,columnCount-1)->setTextAlignment(Qt::AlignCenter);
       if(columnCount == 11){
           rowCount++;
           columnCount = 0;
        }
    }
}

MainWindow::~MainWindow() {
    delete ui;
}
