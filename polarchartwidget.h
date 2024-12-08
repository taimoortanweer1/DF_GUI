#ifndef POLARCHARTWIDGET_H
#define POLARCHARTWIDGET_H

#include <QtCharts/QPolarChart>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QChartView>
#include <QWidget>

QT_CHARTS_USE_NAMESPACE

class PolarChartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PolarChartWidget(QWidget *parent = nullptr);

private:
    QPolarChart *chart;
    QChartView *chartView;
};

#endif // POLARCHARTWIDGET_H
