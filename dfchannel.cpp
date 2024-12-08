#include "dfchannel.h"
#include "ui_dfchannel.h"
#include "qchartview.h"


//#include <iostream>
//#include <cmath>


int x_itr1=0, x_lop1=1;
float angle_to_add=0.1757;
int numSamples1 = 1000000;    // 1 million samples
double f11=400000000;
double f22=5900000000;
QVector<double> xxData;
QVector<double> yyData;
// QVector<double> xQData;
// QVector<double> yQData;
double dbval1=100;
// Global or class-level variables
QPolarChart *polarChart;
QLineSeries *series11;
QScatterSeries *series1;
QValueAxis *angularAxis;
QValueAxis *radialAxis;
QChartView *chartView;
#include <QtCharts/QSplineSeries>
QSplineSeries *series;

QVector<QPointF> newData1; // New vector to store the highest point


DFChannel::DFChannel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DFChannel)
{
    ui->setupUi(this);

    // Set stylesheet to customplot_9 to set the background image
    // this->setStyleSheet("background-image: url(:/jpgtopngconverter-com.jpg);"
    //                                 "background-repeat: no-repeat;"
    //                                 "background-position: center;");

    //ui->pushButton->setStyleSheet("background-color:red;"
                                   // );

    ui->customplot_1->addGraph();
    ui->customplot_1->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customplot_1->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    ui->customplot_2->addGraph();
    ui->customplot_2->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customplot_2->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    ui->customplot_3->addGraph();
    ui->customplot_3->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customplot_3->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    ui->customplot_4->addGraph();
    ui->customplot_4->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customplot_4->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_4->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    ui->customplot_5->addGraph();
    ui->customplot_5->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customplot_5->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_5->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    ui->customplot_6->addGraph();
    ui->customplot_6->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customplot_6->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_6->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    ui->customplot_7->addGraph();
    ui->customplot_7->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customplot_7->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_7->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    ui->customplot_8->addGraph();
    ui->customplot_8->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customplot_8->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_8->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);


    //========================================Polar Satart=========================================================


    // // Number of circles to plot
    // const int numCircles = 10;

    // // Create an empty curve object for each circle
    // QVector<QCPCurve*> circles;

    // // Generate and plot each circle
    // for (int circleIndex = 0; circleIndex < numCircles; ++circleIndex)
    // {
    //     // Calculate radius for current circle
    //     double radius = 100.0 - 10.0 * circleIndex;  // Adjust decrement as needed

    //     // Create curve object for the current circle
    //     QCPCurve *circleCurve = new QCPCurve(ui->customplot_9->xAxis, ui->customplot_9->yAxis);

    //     // Generate the curve data points for the current circle
    //     const int pointCount = 100;  // Reduce point count for a smoother circle
    //     QVector<QCPCurveData> dataCircle(pointCount);

    //     for (int i = 0; i < pointCount; ++i)
    //     {
    //         double angle = i / (double)(pointCount - 1) * 2 * M_PI;
    //         double x = radius * qCos(angle);
    //         double y = radius * qSin(angle);
    //         dataCircle[i] = QCPCurveData(i, x, y);
    //     }

    //     // Pass the data to the curve; set alreadySorted=true since 'i' is ascending
    //     circleCurve->data()->set(dataCircle, true);

    //     // Set the pen and brush for the current circle
    //     circleCurve->setPen(QPen(Qt::blue));
    //     //circleCurve->setBrush(QBrush(QColor(255, 255, 255, 20 + 10 * circleIndex)));  // Adjust alpha value

    //     // Add the current circle to the vector of circles
    //     circles.append(circleCurve);

    //     // Divide the outermost circle into 8 sectors with lines and labels
    //     if (circleIndex == 0)
    //     {
    //         for (int sector = 0; sector < 8; ++sector)
    //         {
    //             double angle = sector * M_PI / 4.0;  // Angle for each sector (45 degrees)
    //             double x1 = radius * qCos(angle);
    //             double y1 = radius * qSin(angle);
    //             double x2 = -radius * qCos(angle);  // Opposite point on circumference
    //             double y2 = -radius * qSin(angle);

    //             // Draw a line segment from (x1, y1) to (x2, y2)
    //             QCPItemLine *sectorLine = new QCPItemLine(ui->customplot_9);
    //             sectorLine->start->setCoords(x1, y1);
    //             sectorLine->end->setCoords(x2, y2);
    //             sectorLine->setPen(QPen(Qt::black));  // Set pen color

    //             // Add the sector line to the plot
    //             ui->customplot_9->setAutoAddPlottableToLegend(sectorLine);

    //             // Calculate label position slightly beyond the circle
    //             double labelRadius = radius + 10.0; // Adjust distance of label from circle
    //             double labelX = labelRadius * qCos(angle);
    //             double labelY = labelRadius * qSin(angle);

    //             // Create label text
    //             QString labelText = QString::number(sector * 45) + "°";

    //             // Add text label at the specified position
    //             QCPItemText *textLabel = new QCPItemText(ui->customplot_9);
    //             textLabel->position->setCoords(labelX, labelY); // Set label position
    //             textLabel->setText(labelText); // Set label text
    //             textLabel->setFont(QFont(font().family(), 10)); // Set font size

    //             // Add the text label to the plot
    //             ui->customplot_9->setAutoAddPlottableToLegend(textLabel);
    //         }
    //     }
    // }

    // // Adjust the plot ranges to fit all circles
    // double maxRadius = 100.0;  // Radius of the largest circle
    // ui->customplot_9->xAxis->setRange(-maxRadius, maxRadius);
    // ui->customplot_9->yAxis->setRange(-maxRadius, maxRadius);

    // // Set up the plot interactions and axis configuration
    // ui->customplot_9->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // ui->customplot_9->axisRect()->setupFullAxesBox();
    // ui->customplot_9->rescaleAxes();


    // // Create a polar chart
    // // Create a polar chart
    // QPolarChart *polarChart = new QPolarChart();
    // polarChart->setTitle("Direction Finder");

    // // Create angular and radial axes
    // QValueAxis *angularAxis = new QValueAxis();
    // angularAxis->setTickCount(9); // 8 sectors + 1 to complete the circle
    // angularAxis->setLabelFormat("%.0f");
    // angularAxis->setRange(0, 360);
    // polarChart->addAxis(angularAxis, QPolarChart::PolarOrientationAngular);

    // QValueAxis *radialAxis = new QValueAxis();
    // radialAxis->setTickCount(6);
    // radialAxis->setLabelFormat("%.1f");
    // radialAxis->setRange(0, 256); // Example range, can be adjusted
    // polarChart->addAxis(radialAxis,QPolarChart::PolarOrientationRadial);

    // // Create a scatter series to plot points in sector 7 (270 to 315 degrees)
    // QScatterSeries *series = new QScatterSeries();
    // series->setName("Ploting Channel 7");
    // series->append(270, 205); // Example point (angle, radius)
    // series->append(280, 6);
    // series->append(290, 117);
    // series->append(300, 8);
    // series->append(310, 9);
    // series->append(290, 125);
    // series->append(290, 128);
    // series->append(290, 139);

    // // Set the outline color of the points to black
    // QPen black_pen = *new QPen();
    // black_pen = series->pen(); // Get current pen settings
    // black_pen.setColor(Qt::black); // Set outline color to black
    // black_pen.setWidth(1); // Set outline width (optional)
    // series->setPen(black_pen); // Apply the updated pen to the series


    // polarChart->addSeries(series);

    // // Attach the series to the axes
    // series->attachAxis(angularAxis);
    // series->attachAxis(radialAxis);

    // // Create a chart view with zooming enabled
    // QChartView *chartView = new QChartView(polarChart);
    // chartView->setRenderHint(QPainter::Antialiasing);
    // chartView->setRubberBand(QChartView::RectangleRubberBand); // Enable zooming

    // chartView->setMinimumSize(200, 350);

    // ui->horizontalLayout->addWidget(chartView);


    polarChart = new QPolarChart();
   // polarChart->setTitle("Direction Finder");
    QColor rgbaColor(0, 0, 0); // Red color with 50% transparency
    rgbaColor.setAlpha(100);
    QBrush brush(rgbaColor);
    polarChart->setBackgroundBrush(brush);


    // // Create angular and radial axes
    angularAxis = new QValueAxis();
    angularAxis->setTickCount(9); // 8 sectors + 1 to complete the circle
    angularAxis->setLabelFormat("%.0f");
    angularAxis->setRange(0, 360);
    angularAxis->setLabelsColor(Qt::white);
    angularAxis->setGridLineColor(Qt::green);
    polarChart->addAxis(angularAxis, QPolarChart::PolarOrientationAngular);

    radialAxis = new QValueAxis();
    radialAxis->setTickCount(10);
    radialAxis->setLabelFormat("%.1f");
    radialAxis->setRange(0, 256); // Example range, can be adjusted
    radialAxis->setLabelsColor(Qt::white);
    radialAxis->setGridLineColor(Qt::green);
    polarChart->addAxis(radialAxis,QPolarChart::PolarOrientationRadial);

    // // Create a scatter series to plot points in sector 7 (270 to 315 degrees)
    //series = new QScatterSeries();
    //series = new QLineSeries();
    series = new QSplineSeries();
    series->setPointsVisible(false);
    series->setMarkerSize(8);
    series->setName("Ploting Channel 7");
    series->append(45, 205); // Example point (angle, radius)
    series->append(75, 150);
    series->append(115, 50);
    series->append(0, 0);
    series->append(0, 0);
    series->append(225, 50); // main lobe start
    series->append(250, 100); // maib lobe mid
    series->append(275, 50); // main lobe end
    series->append(0, 0);
    series->append(0, 0);
    series->append(360,0);
    series->append(15, 105); //back lobe
    series->append(45, 205); //backlobe

    // series->sortByAngle();

    // // Set series properties
    // series->setConnectPoints(true); // Enable line connections between points
    // series->setWrapAround(true);

    QBrush markerBrush(Qt::green);
    series->setBrush(markerBrush);
    // // Set the outline color of the points to black
    QPen black_pen = *new QPen();
    black_pen = series->pen(); // Get current pen settings
    black_pen.setColor(Qt::white); // Set outline color to black
    //black_pen.brush()
    black_pen.setWidth(2); // Set outline width (optional)
    series->setPen(black_pen); // Apply the updated pen to the series


    polarChart->addSeries(series);

    // Attach the series to the axes
    series->attachAxis(angularAxis);
    series->attachAxis(radialAxis);

    // // Create a chart view with zooming enabled
    chartView = new QChartView(polarChart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QColor rgbaColor2(0, 0, 0); // Red color with 50% transparency
    rgbaColor2.setAlpha(100);
    QBrush brush2(rgbaColor2);

    chartView->setBackgroundBrush(brush2);

    //chartView->setMinimumSize(200, 380);

    ui->gridLayout_2->addWidget(chartView);


    //=====================================End Polar******************************************************************



    socket1 = new QUdpSocket(this);
    //udpSocket->bind(QHostAddress("http://"+hostid), portid); // Bind to the specified local host address and port 7

    socket1->bind(QHostAddress::LocalHost, 4021); // Bind to localhost on port 4021
    //ui->radioButton->setStyleSheet("QRadioButton::indicator {width: 15px; height: 15px;border-radius: 7px; background-color: #1bc43a; }");
    connect(socket1, &QUdpSocket::readyRead, this, &DFChannel::readDatagrams1);


}

DFChannel::~DFChannel()
{
    delete ui;
    delete socket1;

}



void DFChannel::readDatagrams1() {


    while (socket1->hasPendingDatagrams()) {
        QElapsedTimer timer;
        series->clear();
        // Start the timer before the loop starts
        timer.start();
        xxData.clear();
        yyData.clear();



        QByteArray datagram;
        datagram.resize(socket1->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        socket1->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        // Ensure the size of the received data is a multiple of 4 bytes (size of int32_t)
        if (datagram.size() % sizeof(int32_t) != 0) {
            qDebug() << "Received data size is not a multiple of 4 bytes";
            continue;
        }

        // Interpret the received data as int32_t values
        const int32_t *intArray = reinterpret_cast<const int32_t*>(datagram.constData());
        int numInts = datagram.size() / sizeof(int32_t);

        // If there are less than 8 values, discard the packet
        if (numInts <= 8) {
            qDebug() << "Received data packet has less than 8 values, discarding...";
            continue;
        }




        //float x_freq=(f22-f11)/8192;
        int chnl_nbr=0;
        //if (x_lop1<=32){
            //x_lop1=x_lop1+1;
            for (int i = 8; i < numInts; ++i) {
                //float xfreq=f11+(x_freq*x_itr1);
                //std::cout << "x freq is: " << xfreq << std::endl;
                //xxData.append(xfreq);

                xxData.append(i-7);
                yyData.append(intArray[i]);

                //x_itr1=x_itr1+1;

                xxData.reserve(numSamples1);
                yyData.reserve(numSamples1);

            }
            chnl_nbr=intArray[7];
            //std::cout << "x chnl is: " << chnl_nbr << std::endl;

            if(chnl_nbr==8){
                float Qs=315.0;
                QPointF highestPoint8;
                qreal maxY = std::numeric_limits<qreal>::lowest();

                ui->customplot_1->graph(0)->setData(xxData, yyData);
                // Set plot labels and titles
                ui->customplot_1->xAxis->setLabel("Frequency (MHz/GHz)");
                ui->customplot_1->yAxis->setLabel("Amplitude (Db)");


                // Set font color to white for x-axis label
                ui->customplot_1->xAxis->setLabelColor(QColor(27, 196, 145));

                // Set font color to white for y-axis label
                ui->customplot_1->yAxis->setLabelColor(QColor(27, 196, 145));

                // Set font color to white for graph text
                ui->customplot_1->graph(0)->setPen(QColor(27, 196, 145));

                // Set font color to white for axis ticks and labels
                ui->customplot_1->xAxis->setTickLabelColor(QColor(27, 196, 145));
                ui->customplot_1->yAxis->setTickLabelColor(QColor(27, 196, 145));

                // Set font color to white for axis line
                ui->customplot_1->xAxis->setBasePen(QColor(27, 196, 145));
                ui->customplot_1->yAxis->setBasePen(QColor(27, 196, 145));

                // Set font color to white for axis grid lines
                ui->customplot_1->xAxis->grid()->setPen(QColor(27, 196, 145));
                ui->customplot_1->yAxis->grid()->setPen(QColor(27, 196, 145));

                // Set font color to white for legend
                ui->customplot_1->legend->setBrush(QColor(27, 196, 145));
                ui->customplot_1->legend->setTextColor(QColor(27, 196, 145));

                ui->customplot_1->xAxis->setRange(0,264);
                //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
                ui->customplot_1->yAxis->setRange(-250,50); // Adjust range as needed
                ui->customplot_1->replot();
                //x_lop1=x_lop1+1;

                //polar ploting channel 8
                float detaa=Qs+angle_to_add;
                QVector<QPointF> newData;

                series->setName("Ploting Channel 8");
                for(int z=0;z<yyData.size();++z){
                    newData.append(QPointF(detaa, qAbs(yyData[z])));

                    //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                    // series->append(detaa,yyData[z]);
                    detaa=detaa+angle_to_add;

                }

                for (const QPointF &point : newData) {
                    if (point.y() > maxY) {
                        maxY = point.y();
                        highestPoint8 = point;
                    }
                }

                // Store the highest point in newData1
                newData1.append(highestPoint8);
                float ypeak=(highestPoint8.y()+newData1.at(0).y())/2;
                float xpeak=((360-highestPoint8.x())/2)+highestPoint8.x();
                QPointF midangle(xpeak,highestPoint8.y());
                qDebug() << " MID Value values ch 8 "<<midangle;

                qDebug() << " Y high values ch 8 "<<highestPoint8;

                newData1.append(midangle);

                float xpeak2=((360-xpeak)/2)+xpeak;
                QPointF midangle2(xpeak2,highestPoint8.y());
                newData1.append(midangle2);


                float xpeak3=((360-xpeak2)/2)+xpeak2;
                QPointF midangle3(xpeak3,highestPoint8.y());
                newData1.append(midangle3);

                float xpeak4=((360-xpeak3)/2)+xpeak3;
                QPointF midangle4(xpeak4,highestPoint8.y());
                newData1.append(midangle4);

                newData1.append(QPointF(360,ypeak));


                newData1.append(QPointF(0, ypeak));
                newData1.append(newData1.at(0));
                qDebug() << "new Data 0  Values: " << newData1[0] << " NewData1 Size "<<newData1.size();



                series->replace(newData1);
                newData1.clear();
                //series->append(newData1);
                polarChart->update();
                chartView->update();

                newData.clear();
                //highestPoint8.isNull();
                //series->clear();

                //polar ploting end



            }
            if(chnl_nbr==1){

                float Qs=0.0;
                QPointF highestPoint;
                qreal maxY = std::numeric_limits<qreal>::lowest();


                ui->customplot_2->graph(0)->setData(xxData, yyData);
                // Set plot labels and titles
                ui->customplot_2->xAxis->setLabel("Frequency (MHz/GHz)");
                ui->customplot_2->yAxis->setLabel("Amplitude (Db)");


                // Set font color to white for x-axis label
                ui->customplot_2->xAxis->setLabelColor(QColor(27, 196, 145));

                // Set font color to white for y-axis label
                ui->customplot_2->yAxis->setLabelColor(QColor(27, 196, 145));

                // Set font color to white for graph text
                ui->customplot_2->graph(0)->setPen(QColor(27, 196, 145));

                // Set font color to white for axis ticks and labels
                ui->customplot_2->xAxis->setTickLabelColor(QColor(27, 196, 145));
                ui->customplot_2->yAxis->setTickLabelColor(QColor(27, 196, 145));

                // Set font color to white for axis line
                ui->customplot_2->xAxis->setBasePen(QColor(27, 196, 145));
                ui->customplot_2->yAxis->setBasePen(QColor(27, 196, 145));

                // Set font color to white for axis grid lines
                ui->customplot_2->xAxis->grid()->setPen(QColor(27, 196, 145));
                ui->customplot_2->yAxis->grid()->setPen(QColor(27, 196, 145));

                // Set font color to white for legend
                ui->customplot_2->legend->setBrush(QColor(27, 196, 145));
                ui->customplot_2->legend->setTextColor(QColor(27, 196, 145));

                ui->customplot_2->xAxis->setRange(0,264);
                //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
                ui->customplot_2->yAxis->setRange(-250,250); // Adjust range as needed
                ui->customplot_2->replot();
                //x_lop1=x_lop1+1;

                //polar ploting

                float detaa=Qs+angle_to_add;
                QVector<QPointF> newData;

                series->setName("Ploting Channel 1");
                for(int z=0;z<yyData.size();++z){
                    newData.append(QPointF(detaa, qAbs(yyData[z])));

                    //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                    // series->append(detaa,yyData[z]);
                    detaa=detaa+angle_to_add;

                }


                for (const QPointF &point : newData) {
                    if (point.y() > maxY) {
                        maxY = point.y();
                        highestPoint = point;
                    }
                }

                // Store the highest point in newData1
                newData1.append(highestPoint);
                //qDebug() << "new Data1 0  Values: " << newData1[0] << " Y high values "<<highestPoint;
                qDebug() << " Y high values ch 1 "<<highestPoint;


                //series->replace(newData);
                newData.clear();
                //polar ploting end






            }
            if(chnl_nbr==2){
                float Qs=45.0;
                QPointF highestPoint;
                qreal maxY = std::numeric_limits<qreal>::lowest();

                ui->customplot_3->graph(0)->setData(xxData, yyData);
                // Set plot labels and titles
                ui->customplot_3->xAxis->setLabel("Frequency (MHz/GHz)");
                ui->customplot_3->yAxis->setLabel("Amplitude (Db)");


                // Set font color to white for x-axis label
                ui->customplot_3->xAxis->setLabelColor(QColor(27, 196, 145));

                // Set font color to white for y-axis label
                ui->customplot_3->yAxis->setLabelColor(QColor(27, 196, 145));

                // Set font color to white for graph text
                ui->customplot_3->graph(0)->setPen(QColor(27, 196, 145));

                // Set font color to white for axis ticks and labels
                ui->customplot_3->xAxis->setTickLabelColor(QColor(27, 196, 145));
                ui->customplot_3->yAxis->setTickLabelColor(QColor(27, 196, 145));

                // Set font color to white for axis line
                ui->customplot_3->xAxis->setBasePen(QColor(27, 196, 145));
                ui->customplot_3->yAxis->setBasePen(QColor(27, 196, 145));

                // Set font color to white for axis grid lines
                ui->customplot_3->xAxis->grid()->setPen(QColor(27, 196, 145));
                ui->customplot_3->yAxis->grid()->setPen(QColor(27, 196, 145));

                // Set font color to white for legend
                ui->customplot_3->legend->setBrush(QColor(27, 196, 145));
                ui->customplot_3->legend->setTextColor(QColor(27, 196, 145));

                ui->customplot_3->xAxis->setRange(0,264);
                //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
                ui->customplot_3->yAxis->setRange(-250,250); // Adjust range as needed
                ui->customplot_3->replot();
                //x_lop1=x_lop1+1;


                //polar ploting
                float detaa=Qs+angle_to_add;
                QVector<QPointF> newData;

                series->setName("Ploting Channel 1");
                for(int z=0;z<yyData.size();++z){
                    newData.append(QPointF(detaa, qAbs(yyData[z])));

                    //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                    // series->append(detaa,yyData[z]);
                    detaa=detaa+angle_to_add;

                }


                for (const QPointF &point : newData) {
                    if (point.y() > maxY) {
                        maxY = point.y();
                        highestPoint = point;
                    }
                }

                // Store the highest point in newData1
                newData1.append(highestPoint);
                qDebug() << " Y high values ch 2 "<<highestPoint;

                //series->replace(newData);
                newData.clear();
                //polar plotting End




            }
            if(chnl_nbr==7){
                float Qs=270.0;
                QPointF highestPoint;
                qreal maxY = std::numeric_limits<qreal>::lowest();

                ui->customplot_4->graph(0)->setData(xxData, yyData);
                // Set plot labels and titles
                ui->customplot_4->xAxis->setLabel("Frequency (MHz/GHz)");
                ui->customplot_4->yAxis->setLabel("Amplitude (Db)");


                // Set font color to white for x-axis label
                ui->customplot_4->xAxis->setLabelColor(QColor(27, 196, 145));

                // Set font color to white for y-axis label
                ui->customplot_4->yAxis->setLabelColor(QColor(27, 196, 145));

                // Set font color to white for graph text
                ui->customplot_4->graph(0)->setPen(QColor(27, 196, 145));

                // Set font color to white for axis ticks and labels
                ui->customplot_4->xAxis->setTickLabelColor(QColor(27, 196, 145));
                ui->customplot_4->yAxis->setTickLabelColor(QColor(27, 196, 145));

                // Set font color to white for axis line
                ui->customplot_4->xAxis->setBasePen(QColor(27, 196, 145));
                ui->customplot_4->yAxis->setBasePen(QColor(27, 196, 145));

                // Set font color to white for axis grid lines
                ui->customplot_4->xAxis->grid()->setPen(QColor(27, 196, 145));
                ui->customplot_4->yAxis->grid()->setPen(QColor(27, 196, 145));

                // Set font color to white for legend
                ui->customplot_4->legend->setBrush(QColor(27, 196, 145));
                ui->customplot_4->legend->setTextColor(QColor(27, 196, 145));

                ui->customplot_4->xAxis->setRange(0,264);
                //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
                ui->customplot_4->yAxis->setRange(-250,250); // Adjust range as needed
                ui->customplot_4->replot();
                //x_lop1=x_lop1+1;

                //polar ploting
                float detaa=Qs+angle_to_add;
                QVector<QPointF> newData;

                series->setName("Ploting Channel 7");
                for(int z=0;z<yyData.size();++z){
                    newData.append(QPointF(detaa, qAbs(yyData[z])));

                    //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                    // series->append(detaa,yyData[z]);
                    detaa=detaa+angle_to_add;

                }


                for (const QPointF &point : newData) {
                    if (point.y() > maxY) {
                        maxY = point.y();
                        highestPoint = point;
                    }
                }

                // Store the highest point in newData1
                newData1.append(highestPoint);
                qDebug() << " Y high values ch 7 "<<highestPoint;

                //series->replace(newData);
                newData.clear();
                //polar plotting End




            }
            if(chnl_nbr==3){

                float Qs=90.0;
                QPointF highestPoint;
                qreal maxY = std::numeric_limits<qreal>::lowest();

                ui->customplot_5->graph(0)->setData(xxData, yyData);
                // Set plot labels and titles
                ui->customplot_5->xAxis->setLabel("Frequency (MHz/GHz)");
                ui->customplot_5->yAxis->setLabel("Amplitude (Db)");


                // Set font color to white for x-axis label
                ui->customplot_5->xAxis->setLabelColor(QColor(27, 196, 145));

                // Set font color to white for y-axis label
                ui->customplot_5->yAxis->setLabelColor(QColor(27, 196, 145));

                // Set font color to white for graph text
                ui->customplot_5->graph(0)->setPen(QColor(27, 196, 145));

                // Set font color to white for axis ticks and labels
                ui->customplot_5->xAxis->setTickLabelColor(QColor(27, 196, 145));
                ui->customplot_5->yAxis->setTickLabelColor(QColor(27, 196, 145));

                // Set font color to white for axis line
                ui->customplot_5->xAxis->setBasePen(QColor(27, 196, 145));
                ui->customplot_5->yAxis->setBasePen(QColor(27, 196, 145));

                // Set font color to white for axis grid lines
                ui->customplot_5->xAxis->grid()->setPen(QColor(27, 196, 145));
                ui->customplot_5->yAxis->grid()->setPen(QColor(27, 196, 145));

                // Set font color to white for legend
                ui->customplot_5->legend->setBrush(QColor(27, 196, 145));
                ui->customplot_5->legend->setTextColor(QColor(27, 196, 145));

                ui->customplot_5->xAxis->setRange(0,264);
                //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
                ui->customplot_5->yAxis->setRange(-250,250); // Adjust range as needed
                ui->customplot_5->replot();
                //x_lop1=x_lop1+1;

                //polar ploting
                float detaa=Qs+angle_to_add;
                QVector<QPointF> newData;

                series->setName("Ploting Channel 3");
                for(int z=0;z<yyData.size();++z){
                    newData.append(QPointF(detaa, qAbs(yyData[z])));

                    //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                    // series->append(detaa,yyData[z]);
                    detaa=detaa+angle_to_add;

                }


                for (const QPointF &point : newData) {
                    if (point.y() > maxY) {
                        maxY = point.y();
                        highestPoint = point;
                    }
                }

                // Store the highest point in newData1
                newData1.append(highestPoint);
                qDebug() << " Y high values ch 3 "<<highestPoint;

                //series->replace(newData);
                newData.clear();
                //polar plotting End


            }
            if(chnl_nbr==5){
                float Qs=180.0;
                QPointF highestPoint;
                qreal maxY = std::numeric_limits<qreal>::lowest();

                ui->customplot_6->graph(0)->setData(xxData, yyData);
                // Set plot labels and titles
                ui->customplot_6->xAxis->setLabel("Frequency (MHz/GHz)");
                ui->customplot_6->yAxis->setLabel("Amplitude (Db)");


                // Set font color to white for x-axis label
                ui->customplot_6->xAxis->setLabelColor(QColor(27, 196, 145));

                // Set font color to white for y-axis label
                ui->customplot_6->yAxis->setLabelColor(QColor(27, 196, 145));

                // Set font color to white for graph text
                ui->customplot_6->graph(0)->setPen(QColor(27, 196, 145));

                // Set font color to white for axis ticks and labels
                ui->customplot_6->xAxis->setTickLabelColor(QColor(27, 196, 145));
                ui->customplot_6->yAxis->setTickLabelColor(QColor(27, 196, 145));

                // Set font color to white for axis line
                ui->customplot_6->xAxis->setBasePen(QColor(27, 196, 145));
                ui->customplot_6->yAxis->setBasePen(QColor(27, 196, 145));

                // Set font color to white for axis grid lines
                ui->customplot_6->xAxis->grid()->setPen(QColor(27, 196, 145));
                ui->customplot_6->yAxis->grid()->setPen(QColor(27, 196, 145));

                // Set font color to white for legend
                ui->customplot_6->legend->setBrush(QColor(27, 196, 145));
                ui->customplot_6->legend->setTextColor(QColor(27, 196, 145));

                ui->customplot_6->xAxis->setRange(0,264);
                //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
                ui->customplot_6->yAxis->setRange(-250,250); // Adjust range as needed
                ui->customplot_6->replot();
                //x_lop1=x_lop1+1;

                //polar ploting
                float detaa=Qs+angle_to_add;
                QVector<QPointF> newData;

                series->setName("Ploting Channel 5");
                for(int z=0;z<yyData.size();++z){
                    newData.append(QPointF(detaa, qAbs(yyData[z])));

                    //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                    // series->append(detaa,yyData[z]);
                    detaa=detaa+angle_to_add;

                }


                for (const QPointF &point : newData) {
                    if (point.y() > maxY) {
                        maxY = point.y();
                        highestPoint = point;
                    }
                }

                // Store the highest point in newData1
                newData1.append(highestPoint);
                qDebug() << " Y high values ch 5 "<<highestPoint;

                //series->replace(newData);
                newData.clear();
                //polar plotting End



            }
            if(chnl_nbr==6){

                float Qs=225.0;
                QPointF highestPoint;
                qreal maxY = std::numeric_limits<qreal>::lowest();

                ui->customplot_7->graph(0)->setData(xxData, yyData);
                // Set plot labels and titles
                ui->customplot_7->xAxis->setLabel("Frequency (MHz/GHz)");
                ui->customplot_7->yAxis->setLabel("Amplitude (Db)");


                // Set font color to white for x-axis label
                ui->customplot_7->xAxis->setLabelColor(QColor(27, 196, 145));

                // Set font color to white for y-axis label
                ui->customplot_7->yAxis->setLabelColor(QColor(27, 196, 145));

                // Set font color to white for graph text
                ui->customplot_7->graph(0)->setPen(QColor(27, 196, 145));

                // Set font color to white for axis ticks and labels
                ui->customplot_7->xAxis->setTickLabelColor(QColor(27, 196, 145));
                ui->customplot_7->yAxis->setTickLabelColor(QColor(27, 196, 145));

                // Set font color to white for axis line
                ui->customplot_7->xAxis->setBasePen(QColor(27, 196, 145));
                ui->customplot_7->yAxis->setBasePen(QColor(27, 196, 145));

                // Set font color to white for axis grid lines
                ui->customplot_7->xAxis->grid()->setPen(QColor(27, 196, 145));
                ui->customplot_7->yAxis->grid()->setPen(QColor(27, 196, 145));

                // Set font color to white for legend
                ui->customplot_7->legend->setBrush(QColor(27, 196, 145));
                ui->customplot_7->legend->setTextColor(QColor(27, 196, 145));

                ui->customplot_7->xAxis->setRange(0,264);
                //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
                ui->customplot_7->yAxis->setRange(-250,250); // Adjust range as needed
                ui->customplot_7->replot();
                //x_lop1=x_lop1+1;

                //polar ploting
                float detaa=Qs+angle_to_add;
                QVector<QPointF> newData;

                series->setName("Ploting Channel 6");
                for(int z=0;z<yyData.size();++z){
                    newData.append(QPointF(detaa, qAbs(yyData[z])));

                    //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                    // series->append(detaa,yyData[z]);
                    detaa=detaa+angle_to_add;

                }


                for (const QPointF &point : newData) {
                    if (point.y() > maxY) {
                        maxY = point.y();
                        highestPoint = point;
                    }
                }

                // Store the highest point in newData1
                newData1.append(highestPoint);
                qDebug() << " Y high values ch 6 "<<highestPoint;

                //series->replace(newData);
                newData.clear();
                //polar plotting End



            }
            if(chnl_nbr==4){

                float Qs=135.0;
                QPointF highestPoint;
                qreal maxY = std::numeric_limits<qreal>::lowest();

                //x_lop1=0;
                ui->customplot_8->graph(0)->setData(xxData, yyData);
                // Set plot labels and titles
                ui->customplot_8->xAxis->setLabel("Frequency (MHz/GHz)");
                ui->customplot_8->yAxis->setLabel("Amplitude (Db)");


                // Set font color to white for x-axis label
                ui->customplot_8->xAxis->setLabelColor(QColor(27, 196, 145));

                // Set font color to white for y-axis label
                ui->customplot_8->yAxis->setLabelColor(QColor(27, 196, 145));

                // Set font color to white for graph text
                ui->customplot_8->graph(0)->setPen(QColor(27, 196, 145));

                // Set font color to white for axis ticks and labels
                ui->customplot_8->xAxis->setTickLabelColor(QColor(27, 196, 145));
                ui->customplot_8->yAxis->setTickLabelColor(QColor(27, 196, 145));

                // Set font color to white for axis line
                ui->customplot_8->xAxis->setBasePen(QColor(27, 196, 145));
                ui->customplot_8->yAxis->setBasePen(QColor(27, 196, 145));

                // Set font color to white for axis grid lines
                ui->customplot_8->xAxis->grid()->setPen(QColor(27, 196, 145));
                ui->customplot_8->yAxis->grid()->setPen(QColor(27, 196, 145));

                // Set font color to white for legend
                ui->customplot_8->legend->setBrush(QColor(27, 196, 145));
                ui->customplot_8->legend->setTextColor(QColor(27, 196, 145));

                ui->customplot_8->xAxis->setRange(0,264);
                //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
                ui->customplot_8->yAxis->setRange(-250,250); // Adjust range as needed
                ui->customplot_8->replot();

                //polar ploting
                float detaa=Qs+angle_to_add;
                QVector<QPointF> newData;

                series->setName("Ploting Channel 4");
                for(int z=0;z<yyData.size();++z){
                    newData.append(QPointF(detaa, qAbs(yyData[z])));

                    //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                    // series->append(detaa,yyData[z]);
                    detaa=detaa+angle_to_add;

                }


                for (const QPointF &point : newData) {
                    if (point.y() > maxY) {
                        maxY = point.y();
                        highestPoint = point;
                    }
                }

                // Store the highest point in newData1
                newData1.append(highestPoint);
                qDebug() << " Y high values ch 4 "<<highestPoint;

                //series->replace(newData);
                newData.clear();
                //polar plotting End

            }

            // xxData.clear();
            // yyData.clear();

            // Calculate the elapsed time in milliseconds
            //qint64 elapsed = timer.nsecsElapsed() / 1000000; // Convert nanoseconds to milliseconds

            // Output the elapsed time for one iteration of the loop
            //qDebug() << "Time taken for one Channel: " << elapsed << " milliseconds";
            //x_lop1=x_lop1+1;






    }
}
