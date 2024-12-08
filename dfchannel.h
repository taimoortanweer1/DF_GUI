#ifndef DFCHANNEL_H
#define DFCHANNEL_H

#include "qudpsocket.h"
#include <QWidget>
#include <QtCharts/QPolarChart>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QLineSeries>
#include <QElapsedTimer>
#include <QDebug>
#include <QtCharts/QSplineSeries>



namespace Ui {
class DFChannel;
}

class DFChannel : public QWidget
{
    Q_OBJECT

public:
    explicit DFChannel(QWidget *parent = nullptr);
    ~DFChannel();
private slots:
    void readDatagrams1();

private:
    Ui::DFChannel *ui;
    QUdpSocket *socket1;

};

#endif // DFCHANNEL_H
