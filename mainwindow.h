#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QChartView>
#include <QSplineSeries>
#include <QScatterSeries>
#include <QDebug>
#include <QValueAxis>
#include <QTimer>
#include <QMainWindow>

using namespace QtCharts;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void receivedData(int);
    int maxSize;
    int maxX;
    int maxY;
    QValueAxis *axisY;
    QValueAxis *axisX;
    QList<int> data;
    QSplineSeries *splineSeries;
    QChart *chart;
    QChartView *chartView;
    QTimer *timer;

private slots:
    void timerTimeOut();

};

#endif // MAINWINDOW_H
