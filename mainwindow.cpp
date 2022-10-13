#include "mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    maxSize = 51;
    maxX = 5000;
    maxY = 40;
    splineSeries = new QSplineSeries();
    chart = new QChart();
    chartView = new QChartView();
    axisX = new QValueAxis();
    axisX = new QValueAxis();
    timer = new QTimer(this);
    chart->legend()->hide();
    chart->setTitle("动态曲线");
    chart->addSeries(splineSeries);
    axisY->setLabelFormat("%i");
    axisY->setTitleText("温度/℃");
    chart->addAxis(axisY, Qt::AlignLeft);
    axisY->setRange(0, maxY);
    splineSeries->attachAxis(axisY);
    axisX->setLabelFormat("%i");
    axisX->setTitleText("时间/ms");
    chart->addAxis(axisX, Qt::AlignBottom);
    axisX->setRange(0, maxX);
    splineSeries->attachAxis(axisX);
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
    timer->start(200);
    connect(timer, &QTimer::timeout, this, &MainWindow::timerTimeOut);
    qsrand(time(NULL));
}

MainWindow::~MainWindow()
{
th
}

void MainWindow::timerTimeOut()
{
    receivedData(qrand() % maxY );
}

void MainWindow::receivedData(int value)
{
    data.append(value);
    while (data.size() > maxSize) {
        data.removeFirst();
    }
    splineSeries->clear();
    int xSpace = maxX / (maxSize - 1);
    for (int i = 0; i < data.size(); ++i) {
        splineSeries->append(xSpace * i, data.at(i));
    }
}

