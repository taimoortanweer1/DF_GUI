#include "polarchartwidget.h"
#include <QHBoxLayout>

PolarChartWidget::PolarChartWidget(QWidget *parent) : QWidget(parent)
{
    chart = new QPolarChart();

    QScatterSeries *series = new QScatterSeries();
    series->append(0, 5);
    series->append(45, 7);
    series->append(90, 6);
    series->append(135, 8);
    series->append(180, 5);
    series->append(225, 6);
    series->append(270, 7);
    series->append(315, 8);

    chart->addSeries(series);

    QValueAxis *radialAxis = new QValueAxis();
    radialAxis->setTickCount(6);
    radialAxis->setLabelFormat("%d");
    radialAxis->setRange(0, 10);
    chart->addAxis(radialAxis, QPolarChart::PolarOrientationRadial);
    series->attachAxis(radialAxis);

    QCategoryAxis *angularAxis = new QCategoryAxis();
    angularAxis->setTickCount(9);
    angularAxis->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);
    angularAxis->append("0°", 0);
    angularAxis->append("45°", 45);
    angularAxis->append("90°", 90);
    angularAxis->append("135°", 135);
    angularAxis->append("180°", 180);
    angularAxis->append("225°", 225);
    angularAxis->append("270°", 270);
    angularAxis->append("315°", 315);
    angularAxis->setRange(0, 360);
    chart->addAxis(angularAxis, QPolarChart::PolarOrientationAngular);
    series->attachAxis(angularAxis);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Set preferred size for the chart view
    chartView->setMinimumSize(500, 300);  // Example size: 800x600

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(chartView);
    setLayout(layout);

    // Optionally, set a preferred size for the whole widget
    setMinimumSize(500, 300);  // Example size: 800x600
}
