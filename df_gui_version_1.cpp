#include "df_gui_version_1.h"
#include "qchartview.h"
#include "ui_df_gui_version_1.h"
// #include "qthread.h"
#include <QDebug>
#include <iostream>
//#include <iostream>
int x_itr=0, x_lop=0,top_count;
int numSamples = 1000000;    // 1 million samples
double f1=400000000.0;
double f2=5900000000.0;
QVector<double> xData;
QVector<double> yData;
int record_data =0;
#include <QTimer>
int fileCounter_scanner = 1;
int fileCounter_df = 1;
QTimer *blinkTimer;
bool isRed = true; // To track the blinking state

double dbval=40;

//double f1=4000000,f2=5900000000;

int x_itr1z=0, x_lop1z=1;
float angle_to_addz=0.1757;
QVector<double> xxDataz;
QVector<double> yyDataz;
QPolarChart *polarChartz;
QLineSeries *series11z;
QScatterSeries *series1z;
QValueAxis *angularAxisz;
QValueAxis *radialAxisz;
QChartView *chartViewz;
#include <QtCharts/QSplineSeries>
QSplineSeries *seriez;
QSplineSeries *seriez_c2;
QSplineSeries *seriez_c3;
QSplineSeries *seriez_c4;

// QSplineSeries *seriez2;
QSplineSeries *seriez3;
QSplineSeries *seriez_t4;
QSplineSeries *seriez_t2;
QSplineSeries *seriez_t3;




QVector<QPointF> newData1z; // New vector to store the highest point




df_gui_version_1::df_gui_version_1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::df_gui_version_1)
{

    ui->setupUi(this);
    //ui->pushButton_6->setVisible(false);
    ui->customplot_2->setVisible(false);
    ui->frame_21->setVisible(false);
    ui->frame_22->setVisible(false);
    ui->checkBox->setVisible(false);
    ui->checkBox_2->setVisible(false);
    ui->checkBox_3->setVisible(false);
    ui->checkBox_4->setVisible(false);
    ui->lineEdit_5->setVisible(false);
    ui->lineEdit_7->setVisible(false);
    ui->lineEdit_5->setText("0");
    ui->lineEdit_7->setText("Test_1");


    ui->lineEdit->setStyleSheet(
        "QLineEdit {"
        "    border: 1px solid gray;"
        "    border-radius: 5px;"  // Rounded corners
        "    padding: 5px;"
        "}"
        "QLineEdit:hover {"
        "    border: 1px solid blue;"  // Highlight border on hover
        "    border-radius: 5px;"
        "}"
        );
    ui->lineEdit_2->setStyleSheet(
        "QLineEdit {"
        "    border: 1px solid gray;"
        "    border-radius: 5px;"  // Rounded corners
        "    padding: 5px;"
        "}"
        "QLineEdit:hover {"
        "    border: 1px solid blue;"  // Highlight border on hover
        "    border-radius: 5px;"
        "}"
        );
    ui->lineEdit_3->setStyleSheet(
        "QLineEdit {"
        "    border: 1px solid gray;"
        "    border-radius: 5px;"  // Rounded corners
        "    padding: 5px;"
        "}"
        "QLineEdit:hover {"
        "    border: 1px solid blue;"  // Highlight border on hover
        "    border-radius: 5px;"
        "}"
        );
    ui->lineEdit_4->setStyleSheet(
        "QLineEdit {"
        "    border: 1px solid gray;"
        "    border-radius: 5px;"  // Rounded corners
        "    padding: 5px;"
        "}"
        "QLineEdit:hover {"
        "    border: 1px solid blue;"  // Highlight border on hover
        "    border-radius: 5px;"
        "}"
        );
    ui->lineEdit_6->setStyleSheet(
        "QLineEdit {"
        "    border: 1px solid gray;"
        "    border-radius: 5px;"  // Rounded corners
        "    padding: 5px;"
        "}"
        "QLineEdit:hover {"
        "    border: 1px solid blue;"  // Highlight border on hover
        "    border-radius: 5px;"
        "}"
        );


    QIntValidator *validator = new QIntValidator(0, 5900, ui->lineEdit);
    ui->lineEdit->setValidator(validator);
    ui->lineEdit->setCursorPosition(0);

    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_2->setCursorPosition(0);

    ui->lineEdit_3->setValidator(validator);
    ui->lineEdit_3->setCursorPosition(0);

    ui->lineEdit_4->setValidator(validator);
    ui->lineEdit_4->setCursorPosition(0);

    ui->lineEdit_6->setValidator(validator);
    ui->lineEdit_6->setCursorPosition(0);


    // ui->lineEdit->setInputMask  ("00000");  // Only allows 4 digits (e.g., 123456)
    // ui->lineEdit->setCursorPosition(0);   // Set the cursor to the leftmost position

    // ui->lineEdit_2->setInputMask("00000");  // Only allows 4 digits (e.g., 123456)
    // ui->lineEdit_2->setCursorPosition(0);   // Set the cursor to the leftmost position

    // ui->lineEdit_3->setInputMask("00000");  // Only allows 6 digits (e.g., 123456)
    // ui->lineEdit_3->setCursorPosition(0);   // Set the cursor to the leftmost position

    // ui->lineEdit_4->setInputMask("0000");  // Only allows 4 digits (e.g., 123456)
    // ui->lineEdit_4->setCursorPosition(0);   // Set the cursor to the leftmost position

    // ui->lineEdit_6->setInputMask("000");  // Only allows 4 digits (e.g., 123456)
    // ui->lineEdit_6->setCursorPosition(0);   // Set the cursor to the leftmost position



    //8 QcustomPlots Initlization------------
    // ui->customplot_9->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    // ui->customplot_9->addGraph();
    // ui->customplot_9->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    // ui->customplot_9->graph(0)->setLineStyle(QCPGraph::lsLine);
    // ui->customplot_9->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // // Set plot labels and titles
    // ui->customplot_9->xAxis->setLabel("Frequency (GHz)");
    // ui->customplot_9->yAxis->setLabel("Amplitude (dBm)");


    // // Set font color to white for x-axis label
    // ui->customplot_9->xAxis->setLabelColor(QColor(27, 196, 145));

    // // Set font color to white for y-axis label
    // ui->customplot_9->yAxis->setLabelColor(QColor(27, 196, 145));

    // // Set font color to white for graph text
    // ui->customplot_9->graph(0)->setPen(QColor(27, 196, 145));

    // // Set font color to white for axis ticks and labels
    // ui->customplot_9->xAxis->setTickLabelColor(QColor(27, 196, 145));
    // ui->customplot_9->yAxis->setTickLabelColor(QColor(27, 196, 145));

    // // Set font color to white for axis line
    // ui->customplot_9->xAxis->setBasePen(QColor(27, 196, 145));
    // ui->customplot_9->yAxis->setBasePen(QColor(27, 196, 145));

    // // Set font color to white for axis grid lines
    // ui->customplot_9->xAxis->grid()->setPen(QColor(27, 196, 145));
    // ui->customplot_9->yAxis->grid()->setPen(QColor(27, 196, 145));

    // // Set font color to white for legend
    // ui->customplot_9->legend->setBrush(QColor(27, 196, 145));
    // ui->customplot_9->legend->setTextColor(QColor(27, 196, 145));


    ui->customplot_9->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    ui->customplot_9->addGraph();
    ui->customplot_9->addGraph();  // Graph 1
    ui->customplot_9->addGraph();  // Graph 2
    ui->customplot_9->addGraph();  // Graph 3

    // Set scatter style (none in this case) and line style (line)
    ui->customplot_9->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_9->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_9->graph(1)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_9->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_9->graph(2)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_9->graph(2)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_9->graph(3)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_9->graph(3)->setLineStyle(QCPGraph::lsLine);

    // Set different colors for each graph
    //ui->customplot_8->graph(0)->setPen(QPen(Qt::red));   // Graph 0 - Red
    ui->customplot_9->graph(1)->setPen(QPen(QColor(0, 0, 255))); // Graph 1 - Green
    ui->customplot_9->graph(2)->setPen(QPen(QColor(217, 145, 0)));  // Graph 2 - Blue
    ui->customplot_9->graph(3)->setPen(QPen(QColor(137, 126, 255))); // Graph 3 - Magenta

    ui->customplot_9->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // Set plot labels and titles
    ui->customplot_9->xAxis->setLabel("Frequency (Hz)");
    ui->customplot_9->yAxis->setLabel("Amplitude (dBm)");


    // Set font color to white for x-axis label
    ui->customplot_9->xAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for y-axis label
    ui->customplot_9->yAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for graph text
    ui->customplot_9->graph(0)->setPen(QColor(255, 0, 0));

    // Set font color to white for axis ticks and labels
    ui->customplot_9->xAxis->setTickLabelColor(QColor(255, 255, 255));
    ui->customplot_9->yAxis->setTickLabelColor(QColor(255, 255, 255));

    // Set font color to white for axis line
    ui->customplot_9->xAxis->setBasePen(QColor(255, 255, 255));
    ui->customplot_9->yAxis->setBasePen(QColor(255, 255, 255));

    // Set font color to white for axis grid lines
    //ui->customplot_9->xAxis->grid()->setPen(QColor(255, 255, 255));
    //ui->customplot_9->yAxis->grid()->setPen(QColor(255, 255, 255));

    // Set font color to white for legend
    ui->customplot_9->legend->setBrush(QColor(255, 255, 255));
    ui->customplot_9->legend->setTextColor(QColor(255, 255, 255));



    //=========================================*===================================================================

    // ui->customplot_2->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    // ui->customplot_2->addGraph();
    // ui->customplot_2->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    // ui->customplot_2->graph(0)->setLineStyle(QCPGraph::lsLine);
    // ui->customplot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // // Set plot labels and titles
    // ui->customplot_2->xAxis->setLabel("Frequency (GHz)");
    // ui->customplot_2->yAxis->setLabel("Amplitude (dBm)");


    // // Set font color to white for x-axis label
    // ui->customplot_2->xAxis->setLabelColor(QColor(27, 196, 145));

    // // Set font color to white for y-axis label
    // ui->customplot_2->yAxis->setLabelColor(QColor(27, 196, 145));

    // // Set font color to white for graph text
    // ui->customplot_2->graph(0)->setPen(QColor(27, 196, 145));

    // // Set font color to white for axis ticks and labels
    // ui->customplot_2->xAxis->setTickLabelColor(QColor(27, 196, 145));
    // ui->customplot_2->yAxis->setTickLabelColor(QColor(27, 196, 145));

    // // Set font color to white for axis line
    // ui->customplot_2->xAxis->setBasePen(QColor(27, 196, 145));
    // ui->customplot_2->yAxis->setBasePen(QColor(27, 196, 145));

    // // Set font color to white for axis grid lines
    // ui->customplot_2->xAxis->grid()->setPen(QColor(27, 196, 145));
    // ui->customplot_2->yAxis->grid()->setPen(QColor(27, 196, 145));

    // // Set font color to white for legend
    // ui->customplot_2->legend->setBrush(QColor(27, 196, 145));
    // ui->customplot_2->legend->setTextColor(QColor(27, 196, 145));


    ui->customplot_2->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    ui->customplot_2->addGraph();
    ui->customplot_2->addGraph();  // Graph 1
    ui->customplot_2->addGraph();  // Graph 2
    ui->customplot_2->addGraph();  // Graph 3

    // Set scatter style (none in this case) and line style (line)
    ui->customplot_2->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_2->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_2->graph(1)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_2->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_2->graph(2)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_2->graph(2)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_2->graph(3)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_2->graph(3)->setLineStyle(QCPGraph::lsLine);

    // Set different colors for each graph
    //ui->customplot_8->graph(0)->setPen(QPen(Qt::red));   // Graph 0 - Red
    ui->customplot_2->graph(1)->setPen(QPen(QColor(0, 0, 255))); // Graph 1 - Green
    ui->customplot_2->graph(2)->setPen(QPen(QColor(217, 145, 0)));  // Graph 2 - Blue
    ui->customplot_2->graph(3)->setPen(QPen(QColor(137, 126, 255))); // Graph 3 - Magenta

    ui->customplot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // Set plot labels and titles
    ui->customplot_2->xAxis->setLabel("Frequency (Hz)");
    ui->customplot_2->yAxis->setLabel("Amplitude (dBm)");


    // Set font color to white for x-axis label
    ui->customplot_2->xAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for y-axis label
    ui->customplot_2->yAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for graph text
    ui->customplot_2->graph(0)->setPen(QColor(255, 0, 0));

    // Set font color to white for axis ticks and labels
    ui->customplot_2->xAxis->setTickLabelColor(QColor(255, 255, 255));
    ui->customplot_2->yAxis->setTickLabelColor(QColor(255, 255, 255));

    // Set font color to white for axis line
    ui->customplot_2->xAxis->setBasePen(QColor(255, 255, 255));
    ui->customplot_2->yAxis->setBasePen(QColor(255, 255, 255));

    // Set font color to white for axis grid lines
    //ui->customplot_2->xAxis->grid()->setPen(QColor(255, 255, 255));
    //ui->customplot_2->yAxis->grid()->setPen(QColor(255, 255, 255));

    // Set font color to white for legend
    ui->customplot_2->legend->setBrush(QColor(255, 255, 255));
    ui->customplot_2->legend->setTextColor(QColor(255, 255, 255));

    //==========================================*============================================

    // ui->customplot_3->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    // ui->customplot_3->addGraph();
    // ui->customplot_3->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    // ui->customplot_3->graph(0)->setLineStyle(QCPGraph::lsLine);
    // ui->customplot_3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // // Set plot labels and titles
    // ui->customplot_3->xAxis->setLabel("Frequency (GHz)");
    // ui->customplot_3->yAxis->setLabel("Amplitude (dBm)");


    // // Set font color to white for x-axis label
    // ui->customplot_3->xAxis->setLabelColor(QColor(27, 196, 145));

    // // Set font color to white for y-axis label
    // ui->customplot_3->yAxis->setLabelColor(QColor(27, 196, 145));

    // // Set font color to white for graph text
    // ui->customplot_3->graph(0)->setPen(QColor(27, 196, 145));

    // // Set font color to white for axis ticks and labels
    // ui->customplot_3->xAxis->setTickLabelColor(QColor(27, 196, 145));
    // ui->customplot_3->yAxis->setTickLabelColor(QColor(27, 196, 145));

    // // Set font color to white for axis line
    // ui->customplot_3->xAxis->setBasePen(QColor(27, 196, 145));
    // ui->customplot_3->yAxis->setBasePen(QColor(27, 196, 145));

    // // Set font color to white for axis grid lines
    // ui->customplot_3->xAxis->grid()->setPen(QColor(27, 196, 145));
    // ui->customplot_3->yAxis->grid()->setPen(QColor(27, 196, 145));

    // // Set font color to white for legend
    // ui->customplot_3->legend->setBrush(QColor(27, 196, 145));
    // ui->customplot_3->legend->setTextColor(QColor(27, 196, 145));

    ui->customplot_3->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    ui->customplot_3->addGraph();
    ui->customplot_3->addGraph();  // Graph 1
    ui->customplot_3->addGraph();  // Graph 2
    ui->customplot_3->addGraph();  // Graph 3

    // Set scatter style (none in this case) and line style (line)
    ui->customplot_3->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_2->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_3->graph(1)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_3->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_3->graph(2)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_3->graph(2)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_3->graph(3)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_3->graph(3)->setLineStyle(QCPGraph::lsLine);

    // Set different colors for each graph
    //ui->customplot_8->graph(0)->setPen(QPen(Qt::red));   // Graph 0 - Red
    ui->customplot_3->graph(1)->setPen(QPen(QColor(0, 0, 255))); // Graph 1 - Green
    ui->customplot_3->graph(2)->setPen(QPen(QColor(217, 145, 0)));  // Graph 2 - Blue
    ui->customplot_3->graph(3)->setPen(QPen(QColor(137, 126, 255))); // Graph 3 - Magenta

    ui->customplot_3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // Set plot labels and titles
    ui->customplot_3->xAxis->setLabel("Frequency (Hz)");
    ui->customplot_3->yAxis->setLabel("Amplitude (dBm)");


    // Set font color to white for x-axis label
    ui->customplot_3->xAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for y-axis label
    ui->customplot_3->yAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for graph text
    ui->customplot_3->graph(0)->setPen(QColor(255, 0, 0));

    // Set font color to white for axis ticks and labels
    ui->customplot_3->xAxis->setTickLabelColor(QColor(255, 255, 255));
    ui->customplot_3->yAxis->setTickLabelColor(QColor(255, 255, 255));

    // Set font color to white for axis line
    ui->customplot_3->xAxis->setBasePen(QColor(255, 255, 255));
    ui->customplot_3->yAxis->setBasePen(QColor(255, 255, 255));

    // Set font color to white for axis grid lines
    //ui->customplot_2->xAxis->grid()->setPen(QColor(255, 255, 255));
    //ui->customplot_3->yAxis->grid()->setPen(QColor(255, 255, 255));

    // Set font color to white for legend
    ui->customplot_3->legend->setBrush(QColor(255, 255, 255));
    ui->customplot_3->legend->setTextColor(QColor(255, 255, 255));

    //=========================================*===============================================================

    // ui->customplot_4->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    // ui->customplot_4->addGraph();
    // ui->customplot_4->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    // ui->customplot_4->graph(0)->setLineStyle(QCPGraph::lsLine);
    // ui->customplot_4->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // // Set plot labels and titles
    // ui->customplot_4->xAxis->setLabel("Frequency (GHz)");
    // ui->customplot_4->yAxis->setLabel("Amplitude (dBm)");


    // // Set font color to white for x-axis label
    // ui->customplot_4->xAxis->setLabelColor(QColor(27, 196, 145));

    // // Set font color to white for y-axis label
    // ui->customplot_4->yAxis->setLabelColor(QColor(27, 196, 145));

    // // Set font color to white for graph text
    // ui->customplot_4->graph(0)->setPen(QColor(27, 196, 145));

    // // Set font color to white for axis ticks and labels
    // ui->customplot_4->xAxis->setTickLabelColor(QColor(27, 196, 145));
    // ui->customplot_4->yAxis->setTickLabelColor(QColor(27, 196, 145));

    // // Set font color to white for axis line
    // ui->customplot_4->xAxis->setBasePen(QColor(27, 196, 145));
    // ui->customplot_4->yAxis->setBasePen(QColor(27, 196, 145));

    // // Set font color to white for axis grid lines
    // ui->customplot_4->xAxis->grid()->setPen(QColor(27, 196, 145));
    // ui->customplot_4->yAxis->grid()->setPen(QColor(27, 196, 145));

    // // Set font color to white for legend
    // ui->customplot_4->legend->setBrush(QColor(27, 196, 145));
    // ui->customplot_4->legend->setTextColor(QColor(27, 196, 145));

    ui->customplot_4->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    ui->customplot_4->addGraph();
    ui->customplot_4->addGraph();  // Graph 1
    ui->customplot_4->addGraph();  // Graph 2
    ui->customplot_4->addGraph();  // Graph 3

    // Set scatter style (none in this case) and line style (line)
    ui->customplot_4->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_4->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_4->graph(1)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_4->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_4->graph(2)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_4->graph(2)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_4->graph(3)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_4->graph(3)->setLineStyle(QCPGraph::lsLine);

    // Set different colors for each graph
    //ui->customplot_8->graph(0)->setPen(QPen(Qt::red));   // Graph 0 - Red
    ui->customplot_4->graph(1)->setPen(QPen(QColor(0, 0, 255))); // Graph 1 - Green
    ui->customplot_4->graph(2)->setPen(QPen(QColor(217, 145, 0)));  // Graph 2 - Blue
    ui->customplot_4->graph(3)->setPen(QPen(QColor(137, 126, 255))); // Graph 3 - Magenta

    ui->customplot_4->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // Set plot labels and titles
    ui->customplot_4->xAxis->setLabel("Frequency (Hz)");
    ui->customplot_4->yAxis->setLabel("Amplitude (dBm)");


    // Set font color to white for x-axis label
    ui->customplot_4->xAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for y-axis label
    ui->customplot_4->yAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for graph text
    ui->customplot_4->graph(0)->setPen(QColor(255, 0, 0));

    // Set font color to white for axis ticks and labels
    ui->customplot_4->xAxis->setTickLabelColor(QColor(255, 255, 255));
    ui->customplot_4->yAxis->setTickLabelColor(QColor(255, 255, 255));

    // Set font color to white for axis line
    ui->customplot_4->xAxis->setBasePen(QColor(255, 255, 255));
    ui->customplot_4->yAxis->setBasePen(QColor(255, 255, 255));

    // Set font color to white for axis grid lines
    //ui->customplot_4->xAxis->grid()->setPen(QColor(255, 255, 255));
    //ui->customplot_4->yAxis->grid()->setPen(QColor(255, 255, 255));

    // Set font color to white for legend
    ui->customplot_4->legend->setBrush(QColor(255, 255, 255));
    ui->customplot_4->legend->setTextColor(QColor(255, 255, 255));

    //=============================================*====================================================

    // ui->customplot_5->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    // ui->customplot_5->addGraph();
    // ui->customplot_5->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    // ui->customplot_5->graph(0)->setLineStyle(QCPGraph::lsLine);
    // ui->customplot_5->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // // Set plot labels and titles
    // ui->customplot_5->xAxis->setLabel("Frequency (GHz)");
    // ui->customplot_5->yAxis->setLabel("Amplitude (dBm)");


    // // Set font color to white for x-axis label
    // ui->customplot_5->xAxis->setLabelColor(QColor(27, 196, 145));

    // // Set font color to white for y-axis label
    // ui->customplot_5->yAxis->setLabelColor(QColor(27, 196, 145));

    // // Set font color to white for graph text
    // ui->customplot_5->graph(0)->setPen(QColor(27, 196, 145));

    // // Set font color to white for axis ticks and labels
    // ui->customplot_5->xAxis->setTickLabelColor(QColor(27, 196, 145));
    // ui->customplot_5->yAxis->setTickLabelColor(QColor(27, 196, 145));

    // // Set font color to white for axis line
    // ui->customplot_5->xAxis->setBasePen(QColor(27, 196, 145));
    // ui->customplot_5->yAxis->setBasePen(QColor(27, 196, 145));

    // // Set font color to white for axis grid lines
    // ui->customplot_5->xAxis->grid()->setPen(QColor(27, 196, 145));
    // ui->customplot_5->yAxis->grid()->setPen(QColor(27, 196, 145));

    // // Set font color to white for legend
    // ui->customplot_5->legend->setBrush(QColor(27, 196, 145));
    // ui->customplot_5->legend->setTextColor(QColor(27, 196, 145));


    ui->customplot_5->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    ui->customplot_5->addGraph();
    ui->customplot_5->addGraph();  // Graph 1
    ui->customplot_5->addGraph();  // Graph 2
    ui->customplot_5->addGraph();  // Graph 3

    // Set scatter style (none in this case) and line style (line)
    ui->customplot_5->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_5->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_5->graph(1)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_5->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_5->graph(2)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_5->graph(2)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_5->graph(3)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_5->graph(3)->setLineStyle(QCPGraph::lsLine);

    // Set different colors for each graph
    //ui->customplot_8->graph(0)->setPen(QPen(Qt::red));   // Graph 0 - Red
    ui->customplot_5->graph(1)->setPen(QPen(QColor(0, 0, 255))); // Graph 1 - Green
    ui->customplot_5->graph(2)->setPen(QPen(QColor(217, 145, 0)));  // Graph 2 - Blue
    ui->customplot_5->graph(3)->setPen(QPen(QColor(137, 126, 255))); // Graph 3 - Magenta

    ui->customplot_5->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // Set plot labels and titles
    ui->customplot_5->xAxis->setLabel("Frequency (Hz)");
    ui->customplot_5->yAxis->setLabel("Amplitude (dBm)");


    // Set font color to white for x-axis label
    ui->customplot_5->xAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for y-axis label
    ui->customplot_5->yAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for graph text
    ui->customplot_5->graph(0)->setPen(QColor(255, 0, 0));

    // Set font color to white for axis ticks and labels
    ui->customplot_5->xAxis->setTickLabelColor(QColor(255, 255, 255));
    ui->customplot_5->yAxis->setTickLabelColor(QColor(255, 255, 255));

    // Set font color to white for axis line
    ui->customplot_5->xAxis->setBasePen(QColor(255, 255, 255));
    ui->customplot_5->yAxis->setBasePen(QColor(255, 255, 255));

    // Set font color to white for axis grid lines
    //ui->customplot_5->xAxis->grid()->setPen(QColor(255, 255, 255));
    //ui->customplot_5->yAxis->grid()->setPen(QColor(255, 255, 255));

    // Set font color to white for legend
    ui->customplot_5->legend->setBrush(QColor(255, 255, 255));
    ui->customplot_5->legend->setTextColor(QColor(255, 255, 255));

    //====================================================*====================================================

    // ui->customplot_6->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    // ui->customplot_6->addGraph();
    // ui->customplot_6->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    // ui->customplot_6->graph(0)->setLineStyle(QCPGraph::lsLine);
    // ui->customplot_6->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    // // Set plot labels and titles
    // ui->customplot_6->xAxis->setLabel("Frequency (GHz)");
    // ui->customplot_6->yAxis->setLabel("Amplitude (dBm)");


    // // Set font color to white for x-axis label
    // ui->customplot_6->xAxis->setLabelColor(QColor(27, 196, 145));

    // // Set font color to white for y-axis label
    // ui->customplot_6->yAxis->setLabelColor(QColor(27, 196, 145));

    // // Set font color to white for graph text
    // ui->customplot_6->graph(0)->setPen(QColor(27, 196, 145));

    // // Set font color to white for axis ticks and labels
    // ui->customplot_6->xAxis->setTickLabelColor(QColor(27, 196, 145));
    // ui->customplot_6->yAxis->setTickLabelColor(QColor(27, 196, 145));

    // // Set font color to white for axis line
    // ui->customplot_6->xAxis->setBasePen(QColor(27, 196, 145));
    // ui->customplot_6->yAxis->setBasePen(QColor(27, 196, 145));

    // // Set font color to white for axis grid lines
    // ui->customplot_6->xAxis->grid()->setPen(QColor(27, 196, 145));
    // ui->customplot_6->yAxis->grid()->setPen(QColor(27, 196, 145));

    // // Set font color to white for legend
    // ui->customplot_6->legend->setBrush(QColor(27, 196, 145));
    // ui->customplot_6->legend->setTextColor(QColor(27, 196, 145));


    ui->customplot_6->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    ui->customplot_6->addGraph();
    ui->customplot_6->addGraph();  // Graph 1
    ui->customplot_6->addGraph();  // Graph 2
    ui->customplot_6->addGraph();  // Graph 3

    // Set scatter style (none in this case) and line style (line)
    ui->customplot_6->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_6->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_6->graph(1)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_6->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_6->graph(2)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_6->graph(2)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_6->graph(3)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_6->graph(3)->setLineStyle(QCPGraph::lsLine);

    // Set different colors for each graph
    //ui->customplot_8->graph(0)->setPen(QPen(Qt::red));   // Graph 0 - Red
    ui->customplot_6->graph(1)->setPen(QPen(QColor(0, 0, 255))); // Graph 1 - Green
    ui->customplot_6->graph(2)->setPen(QPen(QColor(217, 145, 0)));  // Graph 2 - Blue
    ui->customplot_6->graph(3)->setPen(QPen(QColor(137, 126, 255))); // Graph 3 - Magenta

    ui->customplot_6->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // Set plot labels and titles
    ui->customplot_6->xAxis->setLabel("Frequency (Hz)");
    ui->customplot_6->yAxis->setLabel("Amplitude (dBm)");


    // Set font color to white for x-axis label
    ui->customplot_6->xAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for y-axis label
    ui->customplot_6->yAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for graph text
    ui->customplot_6->graph(0)->setPen(QColor(255, 0, 0));

    // Set font color to white for axis ticks and labels
    ui->customplot_6->xAxis->setTickLabelColor(QColor(255, 255, 255));
    ui->customplot_6->yAxis->setTickLabelColor(QColor(255, 255, 255));

    // Set font color to white for axis line
    ui->customplot_6->xAxis->setBasePen(QColor(255, 255, 255));
    ui->customplot_6->yAxis->setBasePen(QColor(255, 255, 255));

    // Set font color to white for axis grid lines
    //ui->customplot_6->xAxis->grid()->setPen(QColor(255, 255, 255));
    //ui->customplot_6->yAxis->grid()->setPen(QColor(255, 255, 255));

    // Set font color to white for legend
    ui->customplot_6->legend->setBrush(QColor(255, 255, 255));
    ui->customplot_6->legend->setTextColor(QColor(255, 255, 255));


    //========================*==============================================================

    // ui->customplot_7->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    // ui->customplot_7->addGraph();
    // ui->customplot_7->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    // ui->customplot_7->graph(0)->setLineStyle(QCPGraph::lsLine);
    // ui->customplot_7->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // // Set plot labels and titles
    // ui->customplot_7->xAxis->setLabel("Frequency (GHz)");
    // ui->customplot_7->yAxis->setLabel("Amplitude (dBm)");


    // // Set font color to white for x-axis label
    // ui->customplot_7->xAxis->setLabelColor(QColor(27, 196, 145));

    // // Set font color to white for y-axis label
    // ui->customplot_7->yAxis->setLabelColor(QColor(27, 196, 145));

    // // Set font color to white for graph text
    // ui->customplot_7->graph(0)->setPen(QColor(27, 196, 145));

    // // Set font color to white for axis ticks and labels
    // ui->customplot_7->xAxis->setTickLabelColor(QColor(27, 196, 145));
    // ui->customplot_7->yAxis->setTickLabelColor(QColor(27, 196, 145));

    // // Set font color to white for axis line
    // ui->customplot_7->xAxis->setBasePen(QColor(27, 196, 145));
    // ui->customplot_7->yAxis->setBasePen(QColor(27, 196, 145));

    // // Set font color to white for axis grid lines
    // ui->customplot_7->xAxis->grid()->setPen(QColor(27, 196, 145));
    // ui->customplot_7->yAxis->grid()->setPen(QColor(27, 196, 145));

    // // Set font color to white for legend
    // ui->customplot_7->legend->setBrush(QColor(27, 196, 145));
    // ui->customplot_7->legend->setTextColor(QColor(27, 196, 145));

    ui->customplot_7->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    ui->customplot_7->addGraph();
    ui->customplot_7->addGraph();  // Graph 1
    ui->customplot_7->addGraph();  // Graph 2
    ui->customplot_7->addGraph();  // Graph 3

    // Set scatter style (none in this case) and line style (line)
    ui->customplot_7->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_7->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_7->graph(1)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_7->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_7->graph(2)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_7->graph(2)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_7->graph(3)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_7->graph(3)->setLineStyle(QCPGraph::lsLine);

    // Set different colors for each graph
    //ui->customplot_8->graph(0)->setPen(QPen(Qt::red));   // Graph 0 - Red
    ui->customplot_7->graph(1)->setPen(QPen(QColor(0, 0, 255))); // Graph 1 - Green
    ui->customplot_7->graph(2)->setPen(QPen(QColor(217, 145, 0)));  // Graph 2 - Blue
    ui->customplot_7->graph(3)->setPen(QPen(QColor(137, 126, 255))); // Graph 3 - Magenta

    ui->customplot_7->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // Set plot labels and titles
    ui->customplot_7->xAxis->setLabel("Frequency (Hz)");
    ui->customplot_7->yAxis->setLabel("Amplitude (dBm)");


    // Set font color to white for x-axis label
    ui->customplot_7->xAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for y-axis label
    ui->customplot_7->yAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for graph text
    ui->customplot_7->graph(0)->setPen(QColor(255, 0, 0));

    // Set font color to white for axis ticks and labels
    ui->customplot_7->xAxis->setTickLabelColor(QColor(255, 255, 255));
    ui->customplot_7->yAxis->setTickLabelColor(QColor(255, 255, 255));

    // Set font color to white for axis line
    ui->customplot_7->xAxis->setBasePen(QColor(255, 255, 255));
    ui->customplot_7->yAxis->setBasePen(QColor(255, 255, 255));

    // Set font color to white for axis grid lines
    //ui->customplot_7->xAxis->grid()->setPen(QColor(255, 255, 255));
    //ui->customplot_7->yAxis->grid()->setPen(QColor(255, 255, 255));

    // Set font color to white for legend
    ui->customplot_7->legend->setBrush(QColor(255, 255, 255));
    ui->customplot_7->legend->setTextColor(QColor(255, 255, 255));




    //==============================================*=============================================

    ui->customplot_8->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    ui->customplot_8->addGraph();
    ui->customplot_8->addGraph();  // Graph 1
    ui->customplot_8->addGraph();  // Graph 2
    ui->customplot_8->addGraph();  // Graph 3

    // Set scatter style (none in this case) and line style (line)
    ui->customplot_8->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_8->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_8->graph(1)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_8->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_8->graph(2)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_8->graph(2)->setLineStyle(QCPGraph::lsLine);
    ui->customplot_8->graph(3)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot_8->graph(3)->setLineStyle(QCPGraph::lsLine);

    // Set different colors for each graph
    //ui->customplot_8->graph(0)->setPen(QPen(Qt::red));   // Graph 0 - Red
    ui->customplot_8->graph(1)->setPen(QPen(QColor(0, 0, 255))); // Graph 1 - Green
    ui->customplot_8->graph(2)->setPen(QPen(QColor(217, 145, 0)));  // Graph 2 - Blue
    ui->customplot_8->graph(3)->setPen(QPen(QColor(137, 126, 255))); // Graph 3 - Magenta

    ui->customplot_8->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // Set plot labels and titles
    ui->customplot_8->xAxis->setLabel("Frequency (Hz)");
    ui->customplot_8->yAxis->setLabel("Amplitude (dBm)");


    // Set font color to white for x-axis label
    ui->customplot_8->xAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for y-axis label
    ui->customplot_8->yAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for graph text
    ui->customplot_8->graph(0)->setPen(QColor(255, 0, 0));

    // Set font color to white for axis ticks and labels
    ui->customplot_8->xAxis->setTickLabelColor(QColor(255, 255, 255));
    ui->customplot_8->yAxis->setTickLabelColor(QColor(255, 255, 255));

    // Set font color to white for axis line
    ui->customplot_8->xAxis->setBasePen(QColor(255, 255, 255));
    ui->customplot_8->yAxis->setBasePen(QColor(255, 255, 255));

    // Set font color to white for axis grid lines
    //ui->customplot_8->xAxis->grid()->setPen(QColor(255, 255, 255));
    //ui->customplot_8->yAxis->grid()->setPen(QColor(255, 255, 255));

    // Set font color to white for legend
    ui->customplot_8->legend->setBrush(QColor(255, 255, 255));
    ui->customplot_8->legend->setTextColor(QColor(255, 255, 255));

    //========================================Polar Satart=========================================================

    polarChartz = new QPolarChart();
    // polarChart->setTitle("Direction Finder");
    QColor rgbaColor(0, 0, 0); // Red color with 50% transparency
    rgbaColor.setAlpha(100);
    QBrush brush(rgbaColor);
    polarChartz->setBackgroundBrush(brush);


    // // Create angular and radial axes
    angularAxisz = new QValueAxis();
    angularAxisz->setTickCount(9); // 8 sectors + 1 to complete the circle
    angularAxisz->setLabelFormat("%.0f");
    angularAxisz->setRange(0, 360);
    angularAxisz->setLabelsColor(Qt::white);
    angularAxisz->setGridLineColor(Qt::green);
    polarChartz->addAxis(angularAxisz, QPolarChart::PolarOrientationAngular);

    radialAxisz = new QValueAxis();
    radialAxisz->setTickCount(10);
    radialAxisz->setLabelFormat("%.1f");
    radialAxisz->setRange(0, 160); // Example range, can be adjusted
    radialAxisz->setLabelsColor(Qt::transparent);
    radialAxisz->setGridLineColor(Qt::green);
    polarChartz->addAxis(radialAxisz,QPolarChart::PolarOrientationRadial);
    polarChartz->legend()->setLabelColor(Qt::white);

    // // Create a scatter series to plot points in sector 7 (270 to 315 degrees)

    seriez3 = new QSplineSeries();
    seriez3->setPointsVisible(false);
    seriez3->setMarkerSize(10);
    seriez3->setName("T1 Direction");
    seriez3->append(0, 0); // Example point (angle, radius)
    // seriez3->append(22, 128); // Example point (angle, radius)
    // seriez3->append(25, 170); // Example point (angle, radius)
    // seriez3->append(25, 170); // Example point (angle, radius)
    // seriez3->append(28, 128); // Example point (angle, radius)
    seriez3->append(0, 0); // Example point (angle, radius)

    seriez_t2 = new QSplineSeries();
    seriez_t2->setPointsVisible(false);
    seriez_t2->setMarkerSize(10);
    seriez_t2->setName("T2 Direction");
    seriez_t2->append(0, 0); // Example point (angle, radius)
    // seriez_t2->append(10, 128); // Example point (angle, radius)
    // seriez_t2->append(30, 170); // Example point (angle, radius)
    // seriez_t2->append(25, 170); // Example point (angle, radius)
    // seriez_t2->append(50, 128); // Example point (angle, radius)
    seriez_t2->append(0, 0); // Example point (angle, radius)

    seriez_t3 = new QSplineSeries();
    seriez_t3->setPointsVisible(false);
    seriez_t3->setMarkerSize(10);
    seriez_t3->setName("T3 Direction");
    seriez_t3->append(0, 0); // Example point (angle, radius)
    // seriez_t3->append(10, 128); // Example point (angle, radius)
    // seriez_t3->append(315, 170); // Example point (angle, radius)
    // seriez_t3->append(250, 170); // Example point (angle, radius)
    // seriez_t3->append(50, 128); // Example point (angle, radius)
    seriez_t3->append(0, 0); // Example point (angle, radius)

    seriez_t4 = new QSplineSeries();
    seriez_t4->setPointsVisible(false);
    seriez_t4->setMarkerSize(10);
    seriez_t4->setName("T4 Direction");
    seriez_t4->append(0, 0); // Example point (angle, radius)
    // seriez_t4->append(10, 128); // Example point (angle, radius)
    // seriez_t4->append(115, 170); // Example point (angle, radius)
    // seriez_t4->append(25, 170); // Example point (angle, radius)
    // seriez_t4->append(150, 128); // Example point (angle, radius)
    seriez_t4->append(0, 0); // Example point (angle, radius)




    //series = new QScatterSeries();
    //series = new QLineSeries();
    seriez = new QSplineSeries();
    seriez->setPointsVisible(false);
    seriez->setMarkerSize(8);
    seriez->setName("Channels T1");

    seriez_c2 = new QSplineSeries();
    seriez_c2->setPointsVisible(false);
    seriez_c2->setMarkerSize(8);
    seriez_c2->setName("Channels T2");

    seriez_c3 = new QSplineSeries();
    seriez_c3->setPointsVisible(false);
    seriez_c3->setMarkerSize(8);
    seriez_c3->setName("Channels T3");

    seriez_c4 = new QSplineSeries();
    seriez_c4->setPointsVisible(false);
    seriez_c4->setMarkerSize(8);
    seriez_c4->setName("Channels T4");


    // seriez->append(45, 205); // Example point (angle, radius)
    // seriez->append(75, 150);
    // seriez->append(115, 50);
    // seriez->append(0, 0);
    // seriez->append(0, 0);
    // seriez->append(225, 50); // main lobe start
    // seriez->append(250, 100); // maib lobe mid
    // seriez->append(275, 50); // main lobe end
    // seriez->append(0, 0);
    // seriez->append(0, 0);
    // seriez->append(360,0);
    // seriez->append(15, 105); //back lobe
    // seriez->append(45, 205); //backlobe





    QBrush main_markerBrush(QColor(255, 0, 0));
    seriez3->setBrush(main_markerBrush);
    QPen black_pen3 = *new QPen();
    black_pen3 = seriez3->pen(); // Get current pen settings
    black_pen3.setColor(QColor(255, 0, 0)); // Set outline color to black
    black_pen3.setWidth(4); // Set outline width (optional)
    seriez3->setPen(black_pen3); // Apply the updated pen to the series

    QBrush markerBrush(QColor(255, 100, 100));
    seriez->setBrush(markerBrush);
    QPen black_pen = *new QPen();
    black_pen = seriez->pen(); // Get current pen settings
    black_pen.setColor(QColor(255, 100, 100)); // Set outline color to black
    black_pen.setWidth(2); // Set outline width (optional)
    seriez->setPen(black_pen); // Apply the updated pen to the series

//--------------------------------------------------------
    QBrush main_markerBrush1(QColor(0, 0, 255));
    seriez_t2->setBrush(main_markerBrush1);
    // // Set the outline color of the points to black
    QPen black_pent2 = *new QPen();
    black_pent2 = seriez_t2->pen(); // Get current pen settings
    black_pent2.setColor(QColor(0, 0, 255)); // Set outline color to black
    black_pent2.setWidth(4); // Set outline width (optional)
    seriez_t2->setPen(black_pent2); // Apply the updated pen to the series

    QBrush markerBrushc2(QColor(0, 0, 180));
    seriez_c2->setBrush(markerBrushc2);
    QPen black_penc2 = *new QPen();
    black_penc2 = seriez_c2->pen(); // Get current pen settings
    black_penc2.setColor(QColor(0, 0, 180)); // Set outline color to black
    black_penc2.setWidth(2); // Set outline width (optional)
    seriez_c2->setPen(black_penc2); // Apply the updated pen to the series
//------------------------------------------------------------



    QBrush main_markerBrush2(QColor(217, 145, 0));
    seriez_t3->setBrush(main_markerBrush2);
    // // Set the outline color of the points to black
    QPen black_pen3t = *new QPen();
    black_pen3t = seriez_t3->pen(); // Get current pen settings
    black_pen3t.setColor(QColor(217, 145, 0)); // Set outline color to black
    //black_pen.brush()
    black_pen3t.setWidth(4); // Set outline width (optional)
    seriez_t3->setPen(black_pen3t); // Apply the updated pen to the series

    QBrush markerBrushc3(QColor(217, 145, 100));
    seriez_c3->setBrush(markerBrushc3);
    QPen black_penc3 = *new QPen();
    black_penc3 = seriez_c3->pen(); // Get current pen settings
    black_penc3.setColor(QColor(217, 145, 100)); // Set outline color to black
    black_penc3.setWidth(2); // Set outline width (optional)
    seriez_c3->setPen(black_penc3); // Apply the updated pen to the series

//--------------------------------------------------------------
    QBrush main_markerBrush3(QColor(137, 126, 255));
    seriez_t4->setBrush(main_markerBrush3);
    // // Set the outline color of the points to black
    QPen black_pen4t = *new QPen();
    black_pen4t = seriez_t4->pen(); // Get current pen settings
    black_pen4t.setColor(QColor(137, 126, 255)); // Set outline color to black
    //black_pen.brush()
    black_pen4t.setWidth(4); // Set outline width (optional)
    seriez_t4->setPen(black_pen4t); // Apply the updated pen to the series

    QBrush markerBrushc4(QColor(137, 126, 200));
    seriez_c4->setBrush(markerBrushc4);
    QPen black_penc4 = *new QPen();
    black_penc4 = seriez_c4->pen(); // Get current pen settings
    black_penc4.setColor(QColor(137, 126, 200)); // Set outline color to black
    black_penc4.setWidth(2); // Set outline width (optional)
    seriez_c4->setPen(black_penc4); // Apply the updated pen to the series



    //polarChartz->addSeries(areaSeries);
    polarChartz->addSeries(seriez);
    polarChartz->addSeries(seriez_c2);
    polarChartz->addSeries(seriez_c3);
    polarChartz->addSeries(seriez_c4);

    polarChartz->addSeries(seriez3);
    polarChartz->addSeries(seriez_t2);
    polarChartz->addSeries(seriez_t3);
    polarChartz->addSeries(seriez_t4);


    //polarChartz->createDefaultAxes();

    // Attach the series to the axes
    seriez_c2->attachAxis(angularAxisz);
    seriez_c2->attachAxis(radialAxisz);

    // Attach the series to the axes
    seriez_c3->attachAxis(angularAxisz);
    seriez_c3->attachAxis(radialAxisz);

    // Attach the series to the axes
    seriez_c4->attachAxis(angularAxisz);
    seriez_c4->attachAxis(radialAxisz);

    // Attach the series to the axes
    seriez->attachAxis(angularAxisz);
    seriez->attachAxis(radialAxisz);


    // Attach the series to the axes
    seriez3->attachAxis(angularAxisz);
    seriez3->attachAxis(radialAxisz);

    // Attach the series to the axes
    seriez_t2->attachAxis(angularAxisz);
    seriez_t2->attachAxis(radialAxisz);

    // Attach the series to the axes
    seriez_t3->attachAxis(angularAxisz);
    seriez_t3->attachAxis(radialAxisz);

    // Attach the series to the axes
    seriez_t4->attachAxis(angularAxisz);
    seriez_t4->attachAxis(radialAxisz);

    // // Create a chart view with zooming enabled
    chartViewz = new QChartView(polarChartz);
    chartViewz->setRenderHint(QPainter::Antialiasing);

    QColor rgbaColor2(0, 0, 0);
    rgbaColor2.setAlpha(100);
    QBrush brush2(rgbaColor2);

    chartViewz->setBackgroundBrush(brush2);

    //chartView->setMinimumSize(200, 380);

    ui->gridLayout->addWidget(chartViewz);

    //*************************************************************************************************** commented 23-jul-24- 12 20 Pm



    //=====================================End Polar******************************************************************

    ui->customplot->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    ui->customplot->addGraph();
    ui->customplot->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->customplot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // Set plot labels and titles
    ui->customplot->xAxis->setLabel("Frequency (Hz)");
    ui->customplot->yAxis->setLabel("Amplitude (dBm)");


    // Set font color to white for x-axis label
    ui->customplot->xAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for y-axis label
    ui->customplot->yAxis->setLabelColor(QColor(255, 255, 255));

    // Set font color to white for graph text
    ui->customplot->graph(0)->setPen(QColor(255, 215, 0));

    // Set font color to white for axis ticks and labels
    ui->customplot->xAxis->setTickLabelColor(QColor(255, 255, 255));
    ui->customplot->yAxis->setTickLabelColor(QColor(255, 255, 255));

    // Set font color to white for axis line
    ui->customplot->xAxis->setBasePen(QColor(255, 255, 255));
    ui->customplot->yAxis->setBasePen(QColor(255, 255, 255));

    // Set font color to white for axis grid lines
    // ui->customplot->xAxis->grid()->setPen(QColor(27, 196, 145));
    // ui->customplot->yAxis->grid()->setPen(QColor(27, 196, 145));

    // Set font color to white for legend
    ui->customplot->legend->setBrush(QColor(27, 196, 145));
    ui->customplot->legend->setTextColor(QColor(27, 196, 145));


    QPen pen;
    pen.setColor(Qt::red);  // Set color to red
    ui->customplot->addGraph();
    ui->customplot->graph(1)->setPen(pen);
    ui->customplot->graph(1)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customplot->graph(1)->setLineStyle(QCPGraph::lsNone);




    // ui->comboBox_2->addItem("MHz");
    // ui->comboBox_2->addItem("GHz");

    // ui->comboBox->addItem("MHz");
    // ui->comboBox->addItem("GHz");

    // ui->comboBox_4->addItem("MHz");
    // ui->comboBox_4->addItem("GHz");

    ui->comboBox_5->addItem("--");
    ui->comboBox_5->addItem("1");
    // ui->comboBox_5->addItem("2");
    // ui->comboBox_5->addItem("3");
    // ui->comboBox_5->addItem("4");

    ui->comboBox_8->addItem("1");
    ui->comboBox_8->addItem("2");
    ui->comboBox_8->addItem("3");
    ui->comboBox_8->addItem("4");

    ui->comboBox_7->addItem("--");
    // ui->comboBox_7->addItem("64");
    // ui->comboBox_7->addItem("128");
    ui->comboBox_7->addItem("256");
    //ui->comboBox_7->addItem("512");
    //ui->comboBox_7->addItem("1024");

    ui->radioButton_2->setStyleSheet(
        "QRadioButton::indicator {"
        "    width: 15px;"
        "    height: 15px;"
        "    border-radius: 7px;"
        "    background-color: red;"  // Sets the radio button indicator to red
        "}"
        "QRadioButton {"
        "    background-color: #117AE9;"  // Sets the background of the radio button itself
        "}"
        );

    ui->radioButton->setStyleSheet(
        "QRadioButton::indicator {"
        "    width: 15px;"
        "    height: 15px;"
        "    border-radius: 7px;"
        "    background-color: red;"  // Sets the radio button indicator to red
        "}"
        "QRadioButton {"
        "    background-color: #117AE9;"  // Sets the background of the radio button itself
        "}"
        );

    //ui->radioButton->setStyleSheet("QRadioButton::indicator {width: 15px; height: 15px;border-radius: 7px; background-color: Red; }");
    //ui->radioButton_2->setStyleSheet("QRadioButton::indicator {width: 15px; height: 15px;border-radius: 7px; background-color: Red; }");


    //ui->pushButton_4->setStyleSheet("color: #ffffff;");
    ui->pushButton_4->setStyleSheet("QPushButton { "
                                    "border-radius: 5px; "
                                    "background-color:#117AE9;"
                                    "color: #ffffff; "
                                    "} "
                                    "QPushButton:hover { "
                                    "background-color: #a3a3a3; "
                                    "} ");
    ui->pushButton_5->setStyleSheet("QPushButton { "
                                    "border-radius: 5px; "
                                    "background-color:#117AE9; "
                                    "color: #ffffff; "
                                    "} "
                                    "QPushButton:hover { "
                                    "background-color: #a3a3a3; "
                                    "} ");
    //ui->pushButton_4->setStyleSheet("background-color: #4d4d4d;");

    ui->pushButton_7->setStyleSheet("QPushButton { "
                                    "border-radius: 5px; "
                                    "background-color:#117AE9; "
                                    "color: #ffffff; "
                                    "} "
                                    "QPushButton:hover { "
                                    "background-color: #a3a3a3; "
                                    "} ");

    ui->pushButton_8->setStyleSheet("QPushButton { "
                                    "border-radius: 5px; "
                                    "background-color: #117AE9; "
                                    "color: #ffffff; "
                                    "} "
                                    "QPushButton:hover { "
                                    "background-color: #a3a3a3; "
                                    "} ");

    ui->horizontalSlider->setVisible(false);
    ui->label_3->setVisible(false);



}



df_gui_version_1::~df_gui_version_1()
{
    delete ui;
    delete socket;
    delete socket2;
    delete socket1;
    delete socket3;


}

void df_gui_version_1::on_pushButton_4_clicked()
{

    //============================Start button -------------

    ui->pushButton_5->setEnabled(true);
    ui->pushButton_5->setStyleSheet("QPushButton { "
                                    "border-radius: 5px; "
                                    "background-color:rgb(107, 138, 122); "
                                    "color: #ffffff; "
                                    "} "
                                    "QPushButton:hover { "
                                    "background-color: #a3a3a3; "
                                    "} ");

    ui->pushButton_4->setStyleSheet("QPushButton { "
                                    "border-radius: 5px; "
                                    "background-color: #a3a3a3; "
                                    "color: #4d4d4d; "
                                    "} "
                                    "QPushButton:hover { "
                                    "background-color:rgb(107, 138, 122); "
                                    "} ");

    ui->pushButton_4->setEnabled(false);

    ui->radioButton_2->setStyleSheet(
        "QRadioButton::indicator {"
        "    width: 15px;"
        "    height: 15px;"
        "    border-radius: 7px;"
        "    background-color: #21ff21;"  // Sets the radio button indicator to red
        "}"
        "QRadioButton {"
        "    background-color: #117AE9;"  // Sets the background of the radio button itself
        "}"
        );

    ui->radioButton->setStyleSheet(
        "QRadioButton::indicator {"
        "    width: 15px;"
        "    height: 15px;"
        "    border-radius: 7px;"
        "    background-color: #21ff21;"  // Sets the radio button indicator to red
        "}"
        "QRadioButton {"
        "    background-color: #117AE9;"  // Sets the background of the radio button itself
        "}"
        );

    socket = new QUdpSocket(this);
    //udpSocket->bind(QHostAddress("http://"+hostid), portid); // Bind to the specified local host address and port 7

    socket->bind(QHostAddress::Any, 4021); // Bind to localhost on port 7
    //ui->radioButton->setStyleSheet("QRadioButton::indicator {width: 15px; height: 15px;border-radius: 7px; background-color: #1bc43a; }");
    connect(socket, &QUdpSocket::readyRead, this, &df_gui_version_1::readDatagrams);

    socket2 = new QUdpSocket(this);
    //udpSocket->bind(QHostAddress("http://"+hostid), portid); // Bind to the specified local host address and port 7

    socket2->bind(QHostAddress::Any, 2500); // Bind to localhost on port 4021
    //ui->radioButton_2->setStyleSheet("QRadioButton::indicator {width: 15px; height: 15px;border-radius: 7px; background-color: #1bc43a; }");
    connect(socket2, &QUdpSocket::readyRead, this, &df_gui_version_1::readDatagrams2);



}


// Data For 8 Channels code Start here============

void df_gui_version_1::readDatagrams2() {


    while (socket2->hasPendingDatagrams()) {
        QElapsedTimer timer;
        // seriez->clear();
        // Start the timer before the loop starts
        timer.start();
        xxDataz.clear();
        yyDataz.clear();

        QByteArray datagram;
        datagram.resize(socket2->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        socket2->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        // Ensure the size of the received data is a multiple of 4 bytes (size of int32_t)
        if (datagram.size() % sizeof(int32_t) != 0) {
            qDebug() << "Received data size is not a multiple of 4 bytes";
            continue;
        }

        // Interpret the received data as int32_t values
        const int32_t *intArray = reinterpret_cast<const int32_t*>(datagram.constData());
        int numInts = datagram.size() / sizeof(int32_t);
        if(record_check < 331)
        {
                // Write data to file if recording is enabled
                if (record_data) {
                    // Specify the target directory path
                    QString folderPath = "C:/Users/ijaz_/OneDrive/Desktop/Recorded_data/"+ui->lineEdit_7->text()+"/"+ui->lineEdit_5->text()+"/DF";

                    // Ensure the folder exists
                    QDir dir(folderPath);
                    if (!dir.exists()) {
                        dir.mkpath(folderPath); // Create the directory if it doesn't exist
                    }

                    // Construct the file name with path
                    QString fileName = QString("%1/udp_data_DF_%2.txt").arg(folderPath).arg(fileCounter_df);

                    QFile file(fileName);

                    // Open the file in WriteOnly mode to create a fresh file
                    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                        QTextStream out(&file);

                        // Get the current date and time
                        QDateTime currentTime = QDateTime::currentDateTime();
                        QString timeStamp = currentTime.toString("yyyy-MM-dd HH:mm:ss");

                        // Write timestamp and data to the file
                        for (int i = 0; i < numInts; ++i) {
                            out << timeStamp << " " << intArray[i] << "\n";
                        }

                        file.close();
                        qDebug() << "Data recorded to" << fileName;

                        // Increment fileCounter for the next file
                        ++fileCounter_df;
                    } else {
                        qDebug() << "Failed to open file for writing.";
                    }
                record_check =record_check+1;

                    if(record_check==331){
                    record_check=340;
                    on_Record_data_clicked();

                    }
                }


        }
        // else if(record_check==330){
        //     // //set button to ideal
        //     // ui->Record_data->setStyleSheet("QPushButton { "
        //     //                                "border-radius: 5px; "
        //     //                                "background-color: #117AE9; "
        //     //                                "color: #4d4d4d; "
        //     //                                "} "
        //     //                                "QPushButton:hover { "
        //     //                                "background-color:#a3a3a3; "
        //     //                                "} ");

        //     // ui->Record_data->setText("START RECORDING");
        //     // ui->Record_data->click();

        //     // record_data=0;//
        //     record_check=340;
        //     on_Record_data_clicked();
        // }


        // If there are less than 8 values, discard the packet
        if (numInts <= 8) {
            qDebug() << "Received data packet has less than 8 values, discarding...";
            continue;
        }

        // for(int i=0; i<numInts; i++){
        //     yyDataz.append(intArray[i]);
        // }

        // qDebug() << " ---------------------------Recived Data Gram :------------------  "<< yyDataz<< Qt::endl;

        // qDebug() << " ---------------------------END Recived Data Gram :------------------  "<< Qt::endl;
        // yyDataz.clear();

        //if(freq_list.size()==4)
        //if(freq_list.size()==8)
        //if(freq_list.size()==12){
            //if(intArray[4]==1){aoa_data1.append(aoa_data);}
            //if(intArray[4]==2){aoa_data1.append(aoa_data);}
            //if(intArray[4]==3){aoa_data1.append(aoa_data);}
            //if(intArray[4]==4){aoa_data1.append(aoa_data);
        //polar_plot()
            //}
        //}
        //if(freq_list.size()==16){
            //if(intArray[4]==1){aoa_data1.append(aoa_data);}
            //if(intArray[4]==2){aoa_data1.append(aoa_data);}
            //if(intArray[4]==3){aoa_data1.append(aoa_data);}
            //if(intArray[4]==4){aoa_data1.append(aoa_data);
                //polar_plot()
                //}
        //}


        int chnl_nbr=-1;

        if(intArray[2]==13){
            //for direction
            int db_aoa=160;
            freq_list1.clear();
            freq_list1.append(freq_list);
            //int value_chk=freq_list.size()/4;
            for(int i=3; i<freq_list1.size();i +=4){

                if(freq_list1[i]==1){
                    freq_list1[i]=0;
                }
                if(freq_list1[i]==2){
                    freq_list1[i]=1;
                }
                if(freq_list1[i]==3){
                    freq_list1[i]=2;
                }
                if(freq_list1[i]==4){
                    freq_list1[i]=3;
                }

                if(intArray[6]==0 && intArray[6]==freq_list1[i]){
                    aoa_data.append(QPointF(0,0 ));
                    aoa_data.append(QPointF(qAbs(intArray[8]-5),db_aoa/2 ));
                    aoa_data.append(QPointF(qAbs(intArray[8]),db_aoa ));
                    aoa_data.append(QPointF(qAbs(intArray[8]+5),db_aoa/2 ));
                    aoa_data.append(QPointF(0,0 ));
                    seriez3->replace(aoa_data);
                    ui->label_68->setText(QString::number(intArray[8]));

                }
                if(intArray[6]==1 && intArray[6]==freq_list1[i]){
                    aoa_data2.append(QPointF(0,0 ));
                    aoa_data2.append(QPointF(qAbs(intArray[8]-5),db_aoa/2 ));
                    aoa_data2.append(QPointF(qAbs(intArray[8]),db_aoa ));
                    aoa_data2.append(QPointF(qAbs(intArray[8]+5),db_aoa/2 ));
                    aoa_data2.append(QPointF(0,0 ));
                    seriez_t2->replace(aoa_data2);
                    ui->label_69->setText(QString::number(intArray[8]));


                }
                if(intArray[6]==2 && intArray[6]==freq_list1[i]){
                    aoa_data3.append(QPointF(0,0 ));
                    aoa_data3.append(QPointF(qAbs(intArray[8]-5),db_aoa/2 ));
                    aoa_data3.append(QPointF(qAbs(intArray[8]),db_aoa ));
                    aoa_data3.append(QPointF(qAbs(intArray[8]+5),db_aoa/2 ));
                    aoa_data3.append(QPointF(0,0 ));
                    seriez_t3->replace(aoa_data3);
                    ui->label_70->setText(QString::number(intArray[8]));


                }


                if(intArray[6]==3 && intArray[6]==freq_list1[i]){
                    aoa_data4.append(QPointF(0,0 ));
                    aoa_data4.append(QPointF(qAbs(intArray[8]-5),db_aoa/2 ));
                    aoa_data4.append(QPointF(qAbs(intArray[8]),db_aoa ));
                    aoa_data4.append(QPointF(qAbs(intArray[8]+5),db_aoa/2 ));
                    aoa_data4.append(QPointF(0,0 ));
                    //qDebug() << " AOA Value after Recived :  "<< aoa_data;

                    seriez_t4->replace(aoa_data4);
                    ui->label_71->setText(QString::number(intArray[8]));


                }

                if(i== freq_list1.size()-1){
                    aoa_data.clear();
                    aoa_data2.clear();
                    aoa_data3.clear();
                    aoa_data4.clear();


                    //series->append(newData1);
                    polarChartz->update();
                    chartViewz->update();
                }
            }


        }        // if(intArray[2]==14){
        //     //for peaks
        //     QVector<QPointF> Pekas_data;
        //     qDebug() << "Peaks values"<<Pekas_data;
        //     float tetaa=0;
        //     for(int i=8; i<16; i++){
        //         qDebug() << "Peaks values"<<Pekas_data;
        //         Pekas_data.append(QPointF(0,0 ));
        //         if(i==8){
        //             Pekas_data.append(QPointF(355,qAbs(intArray[i])/2 ));
        //             Pekas_data.append(QPointF(358,qAbs((intArray[i])/2)+(qAbs(intArray[i])/3) ));
        //             Pekas_data.append(QPointF(359.5,qAbs(intArray[i])-1));

        //         }else{
        //             Pekas_data.append(QPointF(tetaa-5,qAbs(intArray[i])/2 ));
        //         }
        //         Pekas_data.append(QPointF(tetaa, qAbs(intArray[i])));
        //         Pekas_data.append(QPointF(tetaa+5,qAbs(intArray[i])/2 ));
        //         Pekas_data.append(QPointF(0,0 ));


        //         tetaa =tetaa+45;

        //     }
        if (intArray[2] == 14 && allok==1) {


            freq_list1.clear();
            freq_list1.append(freq_list);
            //int value_chk=freq_list.size()/4;
            for(int i=3; i<freq_list1.size();i +=4){

                if(freq_list1[i]==1){
                    freq_list1[i]=0;
                }
                if(freq_list1[i]==2){
                    freq_list1[i]=1;
                }
                if(freq_list1[i]==3){
                    freq_list1[i]=2;
                }
                if(freq_list1[i]==4){
                    freq_list1[i]=3;
                }

                if(intArray[6]==0 && intArray[6]==freq_list1[i]){
                    // Initialize QVector to store peak data points
                    QVector<int> peaks; // To store the raw peak values

                    // Step 1: Collect the 8 peak values from intArray[8] to intArray[15]
                    for (int i = 8; i < 16; i++) {
                        int peakValue = qAbs(intArray[i]);
                        peaks.append(peakValue);
                    }

                    // Print raw peak values before normalization
                    //qDebug() << "Peaks before normalization:" << peaks;

                    // Step 2: Find the maximum peak value
                    float maxPeakValue = *std::max_element(peaks.begin(), peaks.end());

                    // Step 3: Normalize, scale, and convert peaks to integers for plotting
                    float angle = 0;  // Starting angle for peaks
                    QVector<int> normalizedPeaks; // To store integer normalized peak values for debugging

                    for (int i = 0; i < peaks.size(); i++) {
                        // Normalize, scale by 100, and convert to integer
                        int scaledPeak = static_cast<int>((peaks[i] / maxPeakValue) * 100);
                        normalizedPeaks.append(scaledPeak); // Store scaled integer value for debugging

                        // Add points to create a peak shape around the angle position
                        if(i==8){
                            Peaks_data.append(QPointF(0, 0)); // zero point
                            Peaks_data.append(QPointF(355, scaledPeak / 2)); // Left side
                            Peaks_data.append(QPointF(358, scaledPeak /2 +scaledPeak /3));         // Peak point
                            Peaks_data.append(QPointF(359.9, scaledPeak)); // Right side
                            Peaks_data.append(QPointF(0, 0)); // zero point
                        }
                        else
                        {
                            Peaks_data.append(QPointF(0, 0)); // zero point
                            Peaks_data.append(QPointF(angle - 5, scaledPeak / 2)); // Left side
                            Peaks_data.append(QPointF(angle, scaledPeak));         // Peak point
                            Peaks_data.append(QPointF(angle + 5, scaledPeak / 2)); // Right side
                            Peaks_data.append(QPointF(0, 0)); // zero point
                        }
                        angle += 45; // Move to the next angle for each peak

                    }

                    // Print normalized and scaled peak values
                    //qDebug() << "Peaks after normalization and scaling:" << normalizedPeaks;

                    // Print the final integer Peaks_data points for further inspection
                    //qDebug() << "Normalized and scaled Peaks data points:" << Peaks_data;

                    // QThread::msleep(500);  // seconds
                    seriez->replace(Peaks_data);

                }

                if(intArray[6]==1 && intArray[6]==freq_list1[i]){
                    // Initialize QVector to store peak data points
                    QVector<int> peaks; // To store the raw peak values

                    // Step 1: Collect the 8 peak values from intArray[8] to intArray[15]
                    for (int i = 8; i < 16; i++) {
                        int peakValue = qAbs(intArray[i]);
                        peaks.append(peakValue);
                    }

                    // Print raw peak values before normalization
                    //qDebug() << "Peaks before normalization:" << peaks;

                    // Step 2: Find the maximum peak value
                    float maxPeakValue = *std::max_element(peaks.begin(), peaks.end());

                    // Step 3: Normalize, scale, and convert peaks to integers for plotting
                    float angle = 0;  // Starting angle for peaks
                    QVector<int> normalizedPeaks; // To store integer normalized peak values for debugging

                    for (int i = 0; i < peaks.size(); i++) {
                        // Normalize, scale by 100, and convert to integer
                        int scaledPeak = static_cast<int>((peaks[i] / maxPeakValue) * 100);
                        normalizedPeaks.append(scaledPeak); // Store scaled integer value for debugging

                        // Add points to create a peak shape around the angle position
                        if(i==8){
                            Peaks_data2.append(QPointF(0, 0)); // zero point
                            Peaks_data2.append(QPointF(355, scaledPeak / 2)); // Left side
                            Peaks_data2.append(QPointF(358, scaledPeak /2 +scaledPeak /3));         // Peak point
                            Peaks_data2.append(QPointF(359.9, scaledPeak)); // Right side
                            Peaks_data2.append(QPointF(0, 0)); // zero point
                        }
                        else
                        {
                            Peaks_data2.append(QPointF(0, 0)); // zero point
                            Peaks_data2.append(QPointF(angle - 5, scaledPeak / 2)); // Left side
                            Peaks_data2.append(QPointF(angle, scaledPeak));         // Peak point
                            Peaks_data2.append(QPointF(angle + 5, scaledPeak / 2)); // Right side
                            Peaks_data2.append(QPointF(0, 0)); // zero point
                        }
                        angle += 45; // Move to the next angle for each peak

                    }

                    // Print normalized and scaled peak values
                    //qDebug() << "Peaks after normalization and scaling:" << normalizedPeaks;

                    // Print the final integer Peaks_data points for further inspection
                    //qDebug() << "Normalized and scaled Peaks data points:" << Peaks_data;


                    // QThread::msleep(500);  // seconds
                    seriez_c2->replace(Peaks_data2);

                }

                if(intArray[6]==2 && intArray[6]==freq_list1[i]){
                    // Initialize QVector to store peak data points
                    QVector<int> peaks; // To store the raw peak values

                    // Step 1: Collect the 8 peak values from intArray[8] to intArray[15]
                    for (int i = 8; i < 16; i++) {
                        int peakValue = qAbs(intArray[i]);
                        peaks.append(peakValue);
                    }

                    // Print raw peak values before normalization
                    //qDebug() << "Peaks before normalization:" << peaks;

                    // Step 2: Find the maximum peak value
                    float maxPeakValue = *std::max_element(peaks.begin(), peaks.end());

                    // Step 3: Normalize, scale, and convert peaks to integers for plotting
                    float angle = 0;  // Starting angle for peaks
                    QVector<int> normalizedPeaks; // To store integer normalized peak values for debugging

                    for (int i = 0; i < peaks.size(); i++) {
                        // Normalize, scale by 100, and convert to integer
                        int scaledPeak = static_cast<int>((peaks[i] / maxPeakValue) * 100);
                        normalizedPeaks.append(scaledPeak); // Store scaled integer value for debugging

                        // Add points to create a peak shape around the angle position
                        if(i==8){
                            Peaks_data3.append(QPointF(0, 0)); // zero point
                            Peaks_data3.append(QPointF(355, scaledPeak / 2)); // Left side
                            Peaks_data3.append(QPointF(358, scaledPeak /2 +scaledPeak /3));         // Peak point
                            Peaks_data3.append(QPointF(359.9, scaledPeak)); // Right side
                            Peaks_data3.append(QPointF(0, 0)); // zero point
                        }
                        else
                        {
                            Peaks_data3.append(QPointF(0, 0)); // zero point
                            Peaks_data3.append(QPointF(angle - 5, scaledPeak / 2)); // Left side
                            Peaks_data3.append(QPointF(angle, scaledPeak));         // Peak point
                            Peaks_data3.append(QPointF(angle + 5, scaledPeak / 2)); // Right side
                            Peaks_data3.append(QPointF(0, 0)); // zero point
                        }
                        angle += 45; // Move to the next angle for each peak

                    }


                    // QThread::msleep(500);  // seconds
                    seriez_c3->replace(Peaks_data3);

                }

                if(intArray[6]==3 && intArray[6]==freq_list1[i]){
                    // Initialize QVector to store peak data points
                    QVector<int> peaks; // To store the raw peak values

                    // Step 1: Collect the 8 peak values from intArray[8] to intArray[15]
                    for (int i = 8; i < 16; i++) {
                        int peakValue = qAbs(intArray[i]);
                        peaks.append(peakValue);
                    }

                    // Print raw peak values before normalization
                    //qDebug() << "Peaks before normalization:" << peaks;

                    // Step 2: Find the maximum peak value
                    float maxPeakValue = *std::max_element(peaks.begin(), peaks.end());

                    // Step 3: Normalize, scale, and convert peaks to integers for plotting
                    float angle = 0;  // Starting angle for peaks
                    QVector<int> normalizedPeaks; // To store integer normalized peak values for debugging

                    for (int i = 0; i < peaks.size(); i++) {
                        // Normalize, scale by 100, and convert to integer
                        int scaledPeak = static_cast<int>((peaks[i] / maxPeakValue) * 100);
                        normalizedPeaks.append(scaledPeak); // Store scaled integer value for debugging

                        // Add points to create a peak shape around the angle position
                        if(i==8){
                            Peaks_data4.append(QPointF(0, 0)); // zero point
                            Peaks_data4.append(QPointF(355, scaledPeak / 2)); // Left side
                            Peaks_data4.append(QPointF(358, scaledPeak /2 +scaledPeak /3));         // Peak point
                            Peaks_data4.append(QPointF(359.9, scaledPeak)); // Right side
                            Peaks_data4.append(QPointF(0, 0)); // zero point
                        }
                        else
                        {
                            Peaks_data4.append(QPointF(0, 0)); // zero point
                            Peaks_data4.append(QPointF(angle - 5, scaledPeak / 2)); // Left side
                            Peaks_data4.append(QPointF(angle, scaledPeak));         // Peak point
                            Peaks_data4.append(QPointF(angle + 5, scaledPeak / 2)); // Right side
                            Peaks_data4.append(QPointF(0, 0)); // zero point
                        }
                        angle += 45; // Move to the next angle for each peak

                    }

                    // Print normalized and scaled peak values
                    //qDebug() << "Peaks after normalization and scaling:" << normalizedPeaks;

                    // Print the final integer Peaks_data points for further inspection
                    //qDebug() << "Normalized and scaled Peaks data points:" << Peaks_data;



                    // QThread::msleep(500);  // seconds
                    seriez_c4->replace(Peaks_data4);

                }


                if(i== freq_list1.size()-1){
                    Peaks_data.clear();
                    Peaks_data2.clear();
                    Peaks_data3.clear();
                    Peaks_data4.clear();

                    //series->append(newData1);
                    polarChartz->update();
                    chartViewz->update();
                }
            }
        }
        double xAxisDF_data = 0.00;
        xAxisDF_data = -30720000.0;
        if(intArray[2]==15 && allok==1){
            //for scanners
            for (int i = 8; i < numInts; ++i) {
                //float xfreq=f11+(x_freq*x_itr1);
                //std::cout << "x freq is: " << xfreq << std::endl;
                //xxData.append(xfreq);

                //xxDataz.append(i-7);
                xxDataz.append(xAxisDF_data);
                xAxisDF_data = xAxisDF_data + 61440000.0/((double)(intArray[4]) / 8.0);
                yyDataz.append( intArray[i]);
                // qDebug() << " Y Value after Divide :  "<< qAbs(intArray[i]);


                //x_itr1=x_itr1+1;

                xxDataz.reserve(numSamples);
                yyDataz.reserve(numSamples);

            }
            chnl_nbr=intArray[3];
            // std::cout << "x chnl is: " << chnl_nbr << " WITH SIZE: "<<yyDataz.size()<<std::endl;


        }
        //chnl_nbr=intArray[7];
        //std::cout << "x chnl is: " << chnl_nbr << std::endl;

        if(chnl_nbr==7){



            freq_list1.clear();
            freq_list1.append(freq_list);
            //int value_chk=freq_list.size()/4;
            for(int i=3; i<freq_list1.size();i +=4){

                if(freq_list1[i]==1){

                    freq_list1[i]=0;

                }
                if(freq_list1[i]==2){

                    freq_list1[i]=1;

                }
                if(freq_list1[i]==3){

                    freq_list1[i]=2;

                }
                if(freq_list1[i]==4){

                    freq_list1[i]=3;

                }

                if(intArray[6]==0 && intArray[6]==freq_list1[i] && scan1==1){
                    xxDataz1.append(xxDataz);
                    yyDataz1.append(yyDataz);
                    ui->customplot_2->graph(0)->setData(xxDataz1, yyDataz1);


                }
                if(intArray[6]==1 && intArray[6]==freq_list1[i] && scan2==1){
                    xxDataz2.append(xxDataz);
                    yyDataz2.append(yyDataz);
                    ui->customplot_2->graph(1)->setData(xxDataz2, yyDataz2);


                }
                if(intArray[6]==2 && intArray[6]==freq_list1[i] && scan3==1){
                    xxDataz3.append(xxDataz);
                    yyDataz3.append(yyDataz);
                    ui->customplot_2->graph(2)->setData(xxDataz3, yyDataz3);


                }
                if(intArray[6]==3 && intArray[6]==freq_list1[i] && scan4==1){
                    xxDataz4.append(xxDataz);
                    yyDataz4.append(yyDataz);
                    ui->customplot_2->graph(3)->setData(xxDataz4, yyDataz4);

                }

                if(i== freq_list1.size()-1){
                    xxDataz1.clear();
                    xxDataz2.clear();
                    xxDataz3.clear();
                    xxDataz4.clear();
                    yyDataz1.clear();
                    yyDataz2.clear();
                    yyDataz3.clear();
                    yyDataz4.clear();

                }
            }


            ui->customplot_2->xAxis->setRange(-30720000,30720000);
            //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
            ui->customplot_2->yAxis->setRange(-100,0); // Adjust range as needed
            ui->customplot_2->replot();
            ui->customplot_2->update();


            // ui->customplot_2->graph(0)->setData(xxDataz, yyDataz);

            // ui->customplot_2->xAxis->setRange(-30720000,30720000);
            // //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
            // ui->customplot_2->yAxis->setRange(-100,0); // Adjust range as needed
            // ui->customplot_2->replot();
            // //x_lop1=x_lop1+1;


        }
        if(chnl_nbr==0){



            freq_list1.clear();
            freq_list1.append(freq_list);
            //int value_chk=freq_list.size()/4;
            for(int i=3; i<freq_list1.size();i +=4){

                if(freq_list1[i]==1){

                    freq_list1[i]=0;

                }
                if(freq_list1[i]==2){

                    freq_list1[i]=1;

                }
                if(freq_list1[i]==3){

                    freq_list1[i]=2;

                }
                if(freq_list1[i]==4){

                    freq_list1[i]=3;

                }

                if(intArray[6]==0 && intArray[6]==freq_list1[i] && scan1==1){
                    xxDataz1.append(xxDataz);
                    yyDataz1.append(yyDataz);
                    ui->customplot_6->graph(0)->setData(xxDataz1, yyDataz1);


                }
                if(intArray[6]==1 && intArray[6]==freq_list1[i] && scan2==1){
                    xxDataz2.append(xxDataz);
                    yyDataz2.append(yyDataz);
                    ui->customplot_6->graph(1)->setData(xxDataz2, yyDataz2);


                }
                if(intArray[6]==2 && intArray[6]==freq_list1[i] && scan3==1){
                    xxDataz3.append(xxDataz);
                    yyDataz3.append(yyDataz);
                    ui->customplot_6->graph(2)->setData(xxDataz3, yyDataz3);


                }
                if(intArray[6]==3 && intArray[6]==freq_list1[i] && scan4==1){
                    xxDataz4.append(xxDataz);
                    yyDataz4.append(yyDataz);
                    ui->customplot_6->graph(3)->setData(xxDataz4, yyDataz4);

                }

                if(i== freq_list1.size()-1){
                    xxDataz1.clear();
                    xxDataz2.clear();
                    xxDataz3.clear();
                    xxDataz4.clear();
                    yyDataz1.clear();
                    yyDataz2.clear();
                    yyDataz3.clear();
                    yyDataz4.clear();

                }
            }


            ui->customplot_6->xAxis->setRange(-30720000,30720000);
            //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
            ui->customplot_6->yAxis->setRange(-100,0); // Adjust range as needed
            ui->customplot_6->replot();
            ui->customplot_6->update();


            // ui->customplot_6->graph(0)->setData(xxDataz, yyDataz);

            // ui->customplot_6->xAxis->setRange(-30720000,30720000);
            // //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
            // ui->customplot_6->yAxis->setRange(-100,0); // Adjust range as needed
            // ui->customplot_6->replot();
            // //x_lop1=x_lop1+1;

        }
        if(chnl_nbr==1){



            freq_list1.clear();
            freq_list1.append(freq_list);
            //int value_chk=freq_list.size()/4;
            for(int i=3; i<freq_list1.size();i +=4){

                if(freq_list1[i]==1){

                    freq_list1[i]=0;

                }
                if(freq_list1[i]==2){

                    freq_list1[i]=1;

                }
                if(freq_list1[i]==3){

                    freq_list1[i]=2;

                }
                if(freq_list1[i]==4){

                    freq_list1[i]=3;

                }

                if(intArray[6]==0 && intArray[6]==freq_list1[i] && scan1==1){
                    xxDataz1.append(xxDataz);
                    yyDataz1.append(yyDataz);
                    ui->customplot_7->graph(0)->setData(xxDataz1, yyDataz1);


                }
                if(intArray[6]==1 && intArray[6]==freq_list1[i] && scan2==1){
                    xxDataz2.append(xxDataz);
                    yyDataz2.append(yyDataz);
                    ui->customplot_7->graph(1)->setData(xxDataz2, yyDataz2);


                }
                if(intArray[6]==2 && intArray[6]==freq_list1[i] && scan3==1){
                    xxDataz3.append(xxDataz);
                    yyDataz3.append(yyDataz);
                    ui->customplot_7->graph(2)->setData(xxDataz3, yyDataz3);


                }
                if(intArray[6]==3 && intArray[6]==freq_list1[i] && scan4==1){
                    xxDataz4.append(xxDataz);
                    yyDataz4.append(yyDataz);
                    ui->customplot_7->graph(3)->setData(xxDataz4, yyDataz4);

                }

                if(i== freq_list1.size()-1){
                    xxDataz1.clear();
                    xxDataz2.clear();
                    xxDataz3.clear();
                    xxDataz4.clear();
                    yyDataz1.clear();
                    yyDataz2.clear();
                    yyDataz3.clear();
                    yyDataz4.clear();

                }
            }


            ui->customplot_7->xAxis->setRange(-30720000,30720000);
            //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
            ui->customplot_7->yAxis->setRange(-100,0); // Adjust range as needed
            ui->customplot_7->replot();
            ui->customplot_7->update();


            // ui->customplot_7->graph(0)->setData(xxDataz, yyDataz);

            // ui->customplot_7->xAxis->setRange(-30720000,30720000);
            // //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
            // ui->customplot_7->yAxis->setRange(-100,0); // Adjust range as needed
            // ui->customplot_7->replot();
            // //x_lop1=x_lop1+1;

        }
        if(chnl_nbr==6){



            freq_list1.clear();
            freq_list1.append(freq_list);
            //int value_chk=freq_list.size()/4;
            for(int i=3; i<freq_list1.size();i +=4){

                if(freq_list1[i]==1){

                    freq_list1[i]=0;

                }
                if(freq_list1[i]==2){

                    freq_list1[i]=1;

                }
                if(freq_list1[i]==3){

                    freq_list1[i]=2;

                }
                if(freq_list1[i]==4){

                    freq_list1[i]=3;

                }

                if(intArray[6]==0 && intArray[6]==freq_list1[i] && scan1==1){
                    xxDataz1.append(xxDataz);
                    yyDataz1.append(yyDataz);
                    ui->customplot_3->graph(0)->setData(xxDataz1, yyDataz1);


                }
                if(intArray[6]==1 && intArray[6]==freq_list1[i] && scan2==1){
                    xxDataz2.append(xxDataz);
                    yyDataz2.append(yyDataz);
                    ui->customplot_3->graph(1)->setData(xxDataz2, yyDataz2);


                }
                if(intArray[6]==2 && intArray[6]==freq_list1[i] && scan3==1){
                    xxDataz3.append(xxDataz);
                    yyDataz3.append(yyDataz);
                    ui->customplot_3->graph(2)->setData(xxDataz3, yyDataz3);


                }
                if(intArray[6]==3 && intArray[6]==freq_list1[i] && scan4==1){
                    xxDataz4.append(xxDataz);
                    yyDataz4.append(yyDataz);
                    ui->customplot_3->graph(3)->setData(xxDataz4, yyDataz4);

                }

                if(i== freq_list1.size()-1){
                    xxDataz1.clear();
                    xxDataz2.clear();
                    xxDataz3.clear();
                    xxDataz4.clear();
                    yyDataz1.clear();
                    yyDataz2.clear();
                    yyDataz3.clear();
                    yyDataz4.clear();

                }
            }


            ui->customplot_3->xAxis->setRange(-30720000,30720000);
            //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
            ui->customplot_3->yAxis->setRange(-100,0); // Adjust range as needed
            ui->customplot_3->replot();
            ui->customplot_3->update();


            // ui->customplot_3->graph(0)->setData(xxDataz, yyDataz);


            // ui->customplot_3->xAxis->setRange(-30720000,30720000);
            // //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
            // ui->customplot_3->yAxis->setRange(-100,0); // Adjust range as needed
            // ui->customplot_3->replot();
            // //x_lop1=x_lop1+1;


        }
        if(chnl_nbr==2){

            freq_list1.clear();
            freq_list1.append(freq_list);
            //int value_chk=freq_list.size()/4;
            for(int i=3; i<freq_list1.size();i +=4){

                if(freq_list1[i]==1){

                    freq_list1[i]=0;

                }
                if(freq_list1[i]==2){

                    freq_list1[i]=1;

                }
                if(freq_list1[i]==3){

                    freq_list1[i]=2;

                }
                if(freq_list1[i]==4){

                    freq_list1[i]=3;

                }

                if(intArray[6]==0 && intArray[6]==freq_list1[i] && scan1==1){
                    xxDataz1.append(xxDataz);
                    yyDataz1.append(yyDataz);
                    ui->customplot_8->graph(0)->setData(xxDataz1, yyDataz1);


                }
                if(intArray[6]==1 && intArray[6]==freq_list1[i]&& scan2==1){
                    xxDataz2.append(xxDataz);
                    yyDataz2.append(yyDataz);
                    ui->customplot_8->graph(1)->setData(xxDataz2, yyDataz2);


                }
                if(intArray[6]==2 && intArray[6]==freq_list1[i] && scan3==1){
                    xxDataz3.append(xxDataz);
                    yyDataz3.append(yyDataz);
                    ui->customplot_8->graph(2)->setData(xxDataz3, yyDataz3);


                }
                if(intArray[6]==3 && intArray[6]==freq_list1[i] && scan4==1){
                    xxDataz4.append(xxDataz);
                    yyDataz4.append(yyDataz);
                    ui->customplot_8->graph(3)->setData(xxDataz4, yyDataz4);

                }

                if(i== freq_list1.size()-1){
                    xxDataz1.clear();
                    xxDataz2.clear();
                    xxDataz3.clear();
                    xxDataz4.clear();
                    yyDataz1.clear();
                    yyDataz2.clear();
                    yyDataz3.clear();
                    yyDataz4.clear();

                }
            }


            ui->customplot_8->xAxis->setRange(-30720000,30720000);
            //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
            ui->customplot_8->yAxis->setRange(-100,0); // Adjust range as needed
            ui->customplot_8->replot();
            ui->customplot_8->update();


            //x_lop1=x_lop1+1;

        }
        if(chnl_nbr==4){


            freq_list1.clear();
            freq_list1.append(freq_list);
            //int value_chk=freq_list.size()/4;
            for(int i=3; i<freq_list1.size();i +=4){

                if(freq_list1[i]==1){

                    freq_list1[i]=0;

                }
                if(freq_list1[i]==2){

                    freq_list1[i]=1;

                }
                if(freq_list1[i]==3){

                    freq_list1[i]=2;

                }
                if(freq_list1[i]==4){

                    freq_list1[i]=3;

                }

                if(intArray[6]==0 && intArray[6]==freq_list1[i] && scan1==1){
                    xxDataz1.append(xxDataz);
                    yyDataz1.append(yyDataz);
                    ui->customplot_5->graph(0)->setData(xxDataz1, yyDataz1);


                }
                if(intArray[6]==1 && intArray[6]==freq_list1[i] && scan2==1){
                    xxDataz2.append(xxDataz);
                    yyDataz2.append(yyDataz);
                    ui->customplot_5->graph(1)->setData(xxDataz2, yyDataz2);


                }
                if(intArray[6]==2 && intArray[6]==freq_list1[i] && scan3==1){
                    xxDataz3.append(xxDataz);
                    yyDataz3.append(yyDataz);
                    ui->customplot_5->graph(2)->setData(xxDataz3, yyDataz3);


                }
                if(intArray[6]==3 && intArray[6]==freq_list1[i] && scan4==1){
                    xxDataz4.append(xxDataz);
                    yyDataz4.append(yyDataz);
                    ui->customplot_5->graph(3)->setData(xxDataz4, yyDataz4);

                }

                if(i== freq_list1.size()-1){
                    xxDataz1.clear();
                    xxDataz2.clear();
                    xxDataz3.clear();
                    xxDataz4.clear();
                    yyDataz1.clear();
                    yyDataz2.clear();
                    yyDataz3.clear();
                    yyDataz4.clear();

                }
            }


            ui->customplot_5->xAxis->setRange(-30720000,30720000);
            //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
            ui->customplot_5->yAxis->setRange(-100,0); // Adjust range as needed
            ui->customplot_5->replot();
            ui->customplot_5->update();


            // ui->customplot_5->graph(0)->setData(xxDataz, yyDataz);

            // ui->customplot_5->xAxis->setRange(-30720000,30720000);
            // //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
            // ui->customplot_5->yAxis->setRange(-100,0); // Adjust range as needed
            // ui->customplot_5->replot();
            // //x_lop1=x_lop1+1;

        }
        if(chnl_nbr==5){


            freq_list1.clear();
            freq_list1.append(freq_list);
            //int value_chk=freq_list.size()/4;
            for(int i=3; i<freq_list1.size();i +=4){

                if(freq_list1[i]==1){

                    freq_list1[i]=0;

                }
                if(freq_list1[i]==2){

                    freq_list1[i]=1;

                }
                if(freq_list1[i]==3){

                    freq_list1[i]=2;

                }
                if(freq_list1[i]==4){

                    freq_list1[i]=3;

                }

                if(intArray[6]==0 && intArray[6]==freq_list1[i] && scan1==1){
                    xxDataz1.append(xxDataz);
                    yyDataz1.append(yyDataz);
                    ui->customplot_4->graph(0)->setData(xxDataz1, yyDataz1);


                }
                if(intArray[6]==1 && intArray[6]==freq_list1[i] && scan2==1){
                    xxDataz2.append(xxDataz);
                    yyDataz2.append(yyDataz);
                    ui->customplot_4->graph(1)->setData(xxDataz2, yyDataz2);


                }
                if(intArray[6]==2 && intArray[6]==freq_list1[i] && scan3==1){
                    xxDataz3.append(xxDataz);
                    yyDataz3.append(yyDataz);
                    ui->customplot_4->graph(2)->setData(xxDataz3, yyDataz3);


                }
                if(intArray[6]==3 && intArray[6]==freq_list1[i] && scan4==1){
                    xxDataz4.append(xxDataz);
                    yyDataz4.append(yyDataz);
                    ui->customplot_4->graph(3)->setData(xxDataz4, yyDataz4);

                }

                if(i== freq_list1.size()-1){
                    xxDataz1.clear();
                    xxDataz2.clear();
                    xxDataz3.clear();
                    xxDataz4.clear();
                    yyDataz1.clear();
                    yyDataz2.clear();
                    yyDataz3.clear();
                    yyDataz4.clear();

                }
            }


            ui->customplot_4->xAxis->setRange(-30720000,30720000);
            //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
            ui->customplot_4->yAxis->setRange(-100,0); // Adjust range as needed
            ui->customplot_4->replot();
            ui->customplot_4->update();


            // ui->customplot_4->graph(0)->setData(xxDataz, yyDataz);

            // ui->customplot_4->xAxis->setRange(-30720000,30720000);
            // //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
            // ui->customplot_4->yAxis->setRange(-100,0); // Adjust range as needed
            // ui->customplot_4->replot();
            // //x_lop1=x_lop1+1;


        }
        if(chnl_nbr==3){


            freq_list1.clear();
            freq_list1.append(freq_list);
            //int value_chk=freq_list.size()/4;
            for(int i=3; i<freq_list1.size();i +=4){

                if(freq_list1[i]==1){

                    freq_list1[i]=0;

                }
                if(freq_list1[i]==2){

                    freq_list1[i]=1;

                }
                if(freq_list1[i]==3){

                    freq_list1[i]=2;

                }
                if(freq_list1[i]==4){

                    freq_list1[i]=3;

                }

                if(intArray[6]==0 && intArray[6]==freq_list1[i] && scan1==1){
                    xxDataz1.append(xxDataz);
                    yyDataz1.append(yyDataz);
                    ui->customplot_9->graph(0)->setData(xxDataz1, yyDataz1);


                }
                if(intArray[6]==1 && intArray[6]==freq_list1[i] && scan2==1){
                    xxDataz2.append(xxDataz);
                    yyDataz2.append(yyDataz);
                    ui->customplot_9->graph(1)->setData(xxDataz2, yyDataz2);


                }
                if(intArray[6]==2 && intArray[6]==freq_list1[i] && scan3==1){
                    xxDataz3.append(xxDataz);
                    yyDataz3.append(yyDataz);
                    ui->customplot_9->graph(2)->setData(xxDataz3, yyDataz3);


                }
                if(intArray[6]==3 && intArray[6]==freq_list1[i] && scan4==1){
                    xxDataz4.append(xxDataz);
                    yyDataz4.append(yyDataz);
                    ui->customplot_9->graph(3)->setData(xxDataz4, yyDataz4);

                }

                if(i== freq_list1.size()-1){
                    xxDataz1.clear();
                    xxDataz2.clear();
                    xxDataz3.clear();
                    xxDataz4.clear();
                    yyDataz1.clear();
                    yyDataz2.clear();
                    yyDataz3.clear();
                    yyDataz4.clear();

                }
            }


            ui->customplot_9->xAxis->setRange(-30720000,30720000);
            //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
            ui->customplot_9->yAxis->setRange(-100,0); // Adjust range as needed
            ui->customplot_9->replot();
            ui->customplot_9->update();


            // //x_lop1=0;
            // ui->customplot_9->graph(0)->setData(xxDataz, yyDataz);

            // ui->customplot_9->xAxis->setRange(-30720000,30720000);
            // //ui->customplot_1->yAxis->setRange(-250,dbval1); // Adjust range as needed
            // ui->customplot_9->yAxis->setRange(-100,0); // Adjust range as needed
            // ui->customplot_9->replot();

        }

    }
}


// Data for 8 Channe;s code END Here===============



void df_gui_version_1::readDatagrams() {

    //QVector<double> x,y;

    while (socket->hasPendingDatagrams()) {
        QElapsedTimer timer;

        // Start the timer before the loop starts
        timer.start();

        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        // Ensure the size of the received data is a multiple of 4 bytes (size of int32_t)
        if (datagram.size() % sizeof(int32_t) != 0) {
            qDebug() << "Received data size is not a multiple of 4 bytes";
            continue;
        }

        // Interpret the received data as int32_t values
        const int32_t *intArray = reinterpret_cast<const int32_t*>(datagram.constData());
        int numInts = datagram.size() / sizeof(int32_t);


        // Write data to file if recording is enabled
        // if (record_data) {
        //     // Specify the target directory path
        //     QString folderPath = "D:/Working_Dir/Integration_DF_SYS/DF-8-LPDA-GUI-main-2Dec/build/Desktop_Qt_6_7_3_MinGW_64_bit-Debug/Recorded_data/scanner";

        //     // Ensure the folder exists
        //     QDir dir(folderPath);
        //     if (!dir.exists()) {
        //         dir.mkpath(folderPath); // Create the directory if it doesn't exist
        //     }

        //     // Construct the file name with path
        //     QString fileName = QString("%1/udp_data_Scanner_%2.txt").arg(folderPath).arg(fileCounter_scanner);

        //     QFile file(fileName);

        //     // Open the file in WriteOnly mode to create a fresh file
        //     if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        //         QTextStream out(&file);

        //         // Get the current date and time
        //         QDateTime currentTime = QDateTime::currentDateTime();
        //         QString timeStamp = currentTime.toString("yyyy-MM-dd HH:mm:ss");

        //         // Write timestamp and data to the file
        //         for (int i = 0; i < numInts; ++i) {
        //             out << timeStamp << " " << intArray[i] << "\n";
        //         }

        //         file.close();
        //         qDebug() << "Data recorded to" << fileName;

        //         // Increment fileCounter for the next file
        //         ++fileCounter_scanner;
        //     } else {
        //         qDebug() << "Failed to open file for writing.";
        //     }
        // }

        if(record_check_scaner < 331)
        {
            // Write data to file if recording is enabled
            if (record_data) {
                // Specify the target directory path
                QString folderPath = "C:/Users/ijaz_/OneDrive/Desktop/Recorded_data/"+ui->lineEdit_7->text()+"/"+ui->lineEdit_5->text()+"/Scanner";

                // Ensure the folder exists
                QDir dir(folderPath);
                if (!dir.exists()) {
                    dir.mkpath(folderPath); // Create the directory if it doesn't exist
                }

                // Construct the file name with path
                QString fileName = QString("%1/udp_data_scanner_%2.txt").arg(folderPath).arg(fileCounter_scanner);

                QFile file(fileName);

                // Open the file in WriteOnly mode to create a fresh file
                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    QTextStream out(&file);

                    // Get the current date and time
                    QDateTime currentTime = QDateTime::currentDateTime();
                    QString timeStamp = currentTime.toString("yyyy-MM-dd HH:mm:ss");

                    // Write timestamp and data to the file
                    for (int i = 0; i < numInts; ++i) {
                        out << timeStamp << " " << intArray[i] << "\n";
                    }

                    file.close();
                    qDebug() << "Data recorded to" << fileName;

                    // Increment fileCounter for the next file
                    ++fileCounter_scanner;
                } else {
                    qDebug() << "Failed to open file for writing.";
                }
                record_check_scaner =record_check_scaner+1;

                if(record_check_scaner==331){
                    record_check_scaner=340;

                    on_Record_data_clicked();

                }
            }


        }
        // If there are less than 8 values, discard the packet
        if (numInts <= 8) {
            qDebug() << "Received data packet has less than 8 values, discarding...";
            continue;
        }

        //intArray[2]; --> total_data
        //intArray[3]; --> total_packets
        //intArray[4]; --> packet_counter
        //intArray[5]; --> valid_data
        //intArray[6]; --> FFT_LENGTH
        //intArray[7]; --> starting_freq (MHz)

        //float x_freq=(f2-f1)/intArray[2];
        double x_freq=(double)((61440000.0)/((double)intArray[6] * 1.0));
        int pkt_nbr= intArray[4];

        if (pkt_nbr<=intArray[3]){
            x_lop=x_lop+1;
            for (int i = 8; i < (intArray[5] + 8); ++i) {
                double xfreq=(double)(intArray[7]*1000.0*1000.0+((double)x_freq*(double)x_itr));
                //std::cout << "x freq is: " << xfreq << std::endl;
                xData.append(xfreq);

                //xData.append(x_itr);
                yData.append(intArray[i]);
                //yData.append(xfreq);


                x_itr=x_itr+1;

                xData.reserve(numSamples);
                yData.reserve(numSamples);

            }

                qDebug() << "Recived Packet number: " << intArray[4];

            if(pkt_nbr==intArray[3]){
                    qDebug() << "Recived file number: " << intArray[6];

                x_lop=1;
                x_itr=0;
                //=================== Top Peaks logics Start====================================


                //top_count=ui->comboBox_8->currentText().toInt();

                // Create a copy of y and x to not modify the original vectors
                QVector<double> y_copy = yData;
                QVector<double> x_copy = xData;

                // Use std::partial_sort_copy to get the top `top_count` values
                QVector<double> yy(top_count);
                QVector<double> xx(top_count);

                std::partial_sort_copy(y_copy.begin(), y_copy.end(), yy.begin(), yy.end(), std::greater<double>());

                for (int i = 0; i < top_count; ++i) {
                    for (int j = 0; j < yData.size(); ++j) {
                        if (yy[i] == yData[j]) {
                            xx[i] = xData[j];
                            break;
                        }
                    }
                }

                //--------------------------------------------------------------------

                findPeaks(xData, yData);


                //===========Top Peaks logic END========================================================

                ui->customplot->graph(0)->setData(xData, yData);
                QList<QCPItemText*> labelList;  // List to store the labels

                // else{
                ui->customplot->xAxis->setRange(f1,f2);
                ui->customplot->yAxis->setRange(ui->label_2->text().toInt(),0); // Adjust range as needed
                ui->customplot->replot();

                // Highlight the peaks with a different color
                QVector<double> peakX, peakY;
                // Assuming findPeaks has stored the peaks in 'peaks' variable
                //QVector<QPair<double, double>> peaks = findPeaks(xData, yData); // Get the peaks again
                int yrange=10;

                for (const auto& peak : peaks) {
                    peakX.append(peak.first);
                    peakY.append(peak.second);

                    label = new QCPItemText(ui->customplot);
                    label->position->setType(QCPItemPosition::ptPlotCoords);
                    label->position->setCoords(peak.first, peak.second+yrange); // Position at the top of the bar
                    //label->setText(QString::number(freq_list[i]/1000000000.0 ,'f', 2)+ " GHz"); // Set label text to the value
                    //QString label_text=peak.first,peak.second;
                    //QString label_text = QString("%1-%2").arg(peak.first).arg(peak.second);
                    label->setText(QString::number(peak.first/1000000000 ,'f', 2)+ " GHz "); // Set label text to the value
                    label->setFont(QFont("sans", 10)); // Set font size
                    label->setColor(Qt::white); // Set label color
                    labelList.append(label); // Add label to list
                    yrange +=3;
                }


                // Add new data from vectors x and y
                //ui->customplot->graph(1)->setData(xx, yy);
                 ui->customplot->graph(1)->setData(peakX, peakY);

                // Replot the graph to update with new data
                ui->customplot->replot();
                xData.clear();
                yData.clear();
                xx.clear();
                yy.clear();
                y_copy.clear();
                x_copy.clear();
                peakX.clear();
                peakY.clear();
                peaks.clear();
                for (int i = 0; i < labelList.size(); ++i) {
                    ui->customplot->removeItem(labelList[i]);  // Remove label from plot
                }
                labelList.clear();

                // Calculate the elapsed time in milliseconds
                qint64 elapsed = timer.nsecsElapsed() / 1000000; // Convert nanoseconds to milliseconds

                // Output the elapsed time for one iteration of the loop
                qDebug() << "Time taken for one iteration: " << elapsed << " milliseconds";

            }
        }

    }






}


void df_gui_version_1::on_pushButton_5_clicked()
{
    //====================Stop Button

    // Disconnect the readyRead signal
    disconnect(socket, &QUdpSocket::readyRead, this, &df_gui_version_1::readDatagrams);

    // Close the UDP socket
    socket->close();

    // Disconnect the readyRead signal
    disconnect(socket2, &QUdpSocket::readyRead, this, &df_gui_version_1::readDatagrams2);

    // Close the UDP socket
    socket2->close();
    //ui->radioButton->setStyleSheet("QRadioButton::indicator {width: 15px; height: 15px;border-radius: 7px; background-color:red; }");
    //ui->radioButton_2->setStyleSheet("QRadioButton::indicator {width: 15px; height: 15px;border-radius: 7px; background-color:red; }");

    ui->radioButton_2->setStyleSheet(
        "QRadioButton::indicator {"
        "    width: 15px;"
        "    height: 15px;"
        "    border-radius: 7px;"
        "    background-color: red;"  // Sets the radio button indicator to red
        "}"
        "QRadioButton {"
        "    background-color: #117AE9;"  // Sets the background of the radio button itself
        "}"
        );

    ui->radioButton->setStyleSheet(
        "QRadioButton::indicator {"
        "    width: 15px;"
        "    height: 15px;"
        "    border-radius: 7px;"
        "    background-color: red;"  // Sets the radio button indicator to red
        "}"
        "QRadioButton {"
        "    background-color: #117AE9;"  // Sets the background of the radio button itself
        "}"
        );



    //ui->pushButton_4->setStyleSheet("background-color: #4d4d4d;");
    ui->pushButton_4->setEnabled(true);
    //ui->pushButton_4->setStyleSheet("border-radius: 15px;background-color: #4d4d4d;color: #ffffff;");
    ui->pushButton_4->setStyleSheet("QPushButton { "
                                    "border-radius: 5px; "
                                    "background-color:rgb(107, 138, 122);"
                                    "color: #ffffff; "
                                    "} "
                                    "QPushButton:hover { "
                                    "background-color: #a3a3a3; "
                                    "} ");



    //ui->pushButton_5->setStyleSheet("border-radius: 15px;background-color: #a3a3a3;color: #4d4d4d;");
    ui->pushButton_5->setStyleSheet("QPushButton { "
                                    "border-radius: 5px; "
                                    "background-color: #a3a3a3; "
                                    "color: #4d4d4d; "
                                    "} "
                                    "QPushButton:hover { "
                                    "background-color:rgb(107, 138, 122);"
                                    "} ");


    ui->pushButton_5->setEnabled(false);


}

void df_gui_version_1::on_pushButton_8_clicked()
{
    //====================Apply Button For Scanner
    socket1= new QUdpSocket(this);


    if(!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty() && !ui->lineEdit_3->text().isEmpty()){

        qint16 sf,ef,gn;
        sf= ui->lineEdit_2->text().toInt();
        ef= ui->lineEdit->text().toInt();
        gn= ui->lineEdit_3->text().toInt();

        if(sf < ef && sf<5900 && ef<5900){

            qDebug()<<"Befor sent SF "<<sf;
            qDebug()<<"Befor sent EF "<<ef;
            qDebug()<<"Befor sent GAIN "<<gn;


            f1=0;
            f2=0;
            f1=sf*1000000.0;
            f2=ef*1000000.0;

            ui->label_32->setText(QString::number(sf)+" MHz");
            ui->label_30->setText(QString::number(ef)+" MHz");
            ui->label_27->setText(QString::number(gn)+" dB");
            ui->label_25->setText(ui->comboBox_8->currentText());




            qDebug()<<"NEW  F1 "<<f1;
            qDebug()<<"NEW  F2 "<<f2;


            senditnow(sf,ef,gn);
        }
        else{
            //qDebug()<<"Stop Frequency can not be greater than start"<<Qt::endl;
            //qDebug()<<"OR Some Feild is mising";
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowTitle("Critical Error");
            msgBox.setText("Stop Frequency can not be greater than start OR Some Feild is missing");
            msgBox.setInformativeText("Please check the input data.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            // msgBox.setDefaultButton(QMessageBox::Retry);
            // int ret = msgBox.exec();
            // if (ret == QMessageBox::Retry) {
            //     // Handle retry logic
            // } else {
            //     // Handle abort logic
            // }

        }
    }

}





void df_gui_version_1::on_pushButton_7_clicked()
{
    // Reset Button For Sccaner==========================
    ui->label_32->setText("----");
    ui->label_30->setText("----");
    ui->label_27->setText("----");
    ui->label_25->setText("----");

    ui->lineEdit_3->setText("");

    if (xData.isEmpty() || yData.isEmpty()) {
        ui->pushButton_7->setStyleSheet("QPushButton { "
                                        "border-radius: 15px; "
                                        "background-color: #4d4d4d; "
                                        "color: #ffffff; "
                                        "} "
                                        "QPushButton:hover { "
                                        "background-color: #a3a3a3; "
                                        "} ");
        ui->pushButton_8->setStyleSheet("QPushButton { "
                                        "border-radius: 15px; "
                                        "background-color: #4d4d4d; "
                                        "color: #ffffff; "
                                        "} "
                                        "QPushButton:hover { "
                                        "background-color: #a3a3a3; "
                                        "} ");
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
    }
    else {
        ui->pushButton_7->setStyleSheet("QPushButton { "
                                        "border-radius: 15px; "
                                        "background-color: #4d4d4d; "
                                        "color: #ffffff; "
                                        "} "
                                        "QPushButton:hover { "
                                        "background-color: #a3a3a3; "
                                        "} ");
        ui->pushButton_8->setStyleSheet("QPushButton { "
                                        "border-radius: 15px; "
                                        "background-color: #4d4d4d; "
                                        "color: #ffffff; "
                                        "} "
                                        "QPushButton:hover { "
                                        "background-color: #a3a3a3; "
                                        "} ");
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        //ui->customplot->graph(0)->setData(xData, yData);

        // Rescale axes to fit new data
        //ui->customplot->rescaleAxes();

        // Replot the graph
        //ui->customplot->replot();
    }


}


void df_gui_version_1::on_lineEdit_3_textChanged(const QString &arg1)
{
    // Db Gain for Scaner
    //dbval = ui->lineEdit_3->text().toDouble();
    dbval =arg1.toDouble();


}


void df_gui_version_1::on_verticalSlider_valueChanged(int value)
{
    dbval=value;
    ui->label_2->setText(QString::number(value));

}


void df_gui_version_1::on_horizontalSlider_valueChanged(int value)
{
    ui->label_3->setText(QString::number(value));

}


// void df_gui_version_1::on_pushButton_6_clicked()
// {
//     //df_channels.show();
// }


void df_gui_version_1::on_comboBox_8_currentTextChanged(const QString &arg1)
{
    top_count=arg1.toInt();
}


void df_gui_version_1::on_pushButton_16_clicked()
{
    //Expert view Button------------------
    allok=1;
    ui->frame_2->setVisible(false);
    ui->frame_3->setVisible(false);

    ui->frame_6->setVisible(false);
    ui->frame_7->setVisible(false);
    ui->frame_10->setVisible(false);
    ui->frame_8->setVisible(false);
    ui->frame_9->setVisible(false);
    ui->frame_11->setVisible(false);
    ui->frame->setVisible(false);


    // Assuming `frame_2` is a pointer to your QFrame
    int x = 552;
    int y = ui->frame_4->y();  // Preserve the current y-coordinate
    int width = ui->frame_4->width();  // Preserve the current width
    int height = ui->frame_4->height(); // Preserve the current height

    ui->frame_4->setGeometry(x, y, width, height);

    int yv = ui->frame_5->y();  // Preserve the current y-coordinate
    int widthv = ui->frame_5->width();  // Preserve the current width
    int heightv = ui->frame_5->height(); // Preserve the current height

    ui->frame_5->setGeometry(x, yv, widthv, heightv);

    ui->customplot_2->setVisible(true);
    ui->frame_21->setVisible(true);
    ui->frame_22->setVisible(true);

    ui->checkBox->setVisible(true);
    ui->checkBox_2->setVisible(true);
    ui->checkBox_3->setVisible(true);
    ui->checkBox_4->setVisible(true);


}


void df_gui_version_1::on_pushButton_17_clicked()
{
    // MainView Button--------------------------
    allok =0;
    seriez->clear();
    seriez_c2->clear();
    seriez_c3->clear();
    seriez_c4->clear();

    polarChartz->update();
    chartViewz->update();
    Peaks_data.clear();
    Peaks_data2.clear();
    Peaks_data3.clear();
    Peaks_data4.clear();

    ideal_series.append(QPointF(0, 0));

    seriez->replace(ideal_series);
    seriez_c2->replace(ideal_series);
    seriez_c3->replace(ideal_series);
    seriez_c4->replace(ideal_series);

    seriez->clear();
    seriez_c2->clear();
    seriez_c3->clear();
    seriez_c4->clear();
    Peaks_data.clear();
    Peaks_data.clear();
    Peaks_data2.clear();
    Peaks_data3.clear();
    ideal_series.append(QPointF(0, 0));
    seriez->replace(ideal_series);
    seriez_c2->replace(ideal_series);
    seriez_c3->replace(ideal_series);
    seriez_c4->replace(ideal_series);






    ui->frame_2->setVisible(true);
    ui->frame_3->setVisible(true);

    ui->frame_6->setVisible(true);
    ui->frame_7->setVisible(true);
    ui->frame_10->setVisible(true);
    ui->frame_8->setVisible(true);
    ui->frame_9->setVisible(true);
    ui->frame_11->setVisible(true);
    ui->frame->setVisible(true);


    // Assuming `frame_2` is a pointer to your QFrame
    int x = 365;
    int y = ui->frame_4->y();  // Preserve the current y-coordinate
    int width = ui->frame_4->width();  // Preserve the current width
    int height = ui->frame_4->height(); // Preserve the current height

    ui->frame_4->setGeometry(x, y, width, height);

    int yv = ui->frame_5->y();  // Preserve the current y-coordinate
    int widthv = ui->frame_5->width();  // Preserve the current width
    int heightv = ui->frame_5->height(); // Preserve the current height

    ui->frame_5->setGeometry(x, yv, widthv, heightv);

    ui->customplot_2->setVisible(false);
    ui->frame_21->setVisible(false);
    ui->frame_22->setVisible(false);


    ui->checkBox->setVisible(false);
    ui->checkBox_2->setVisible(false);
    ui->checkBox_3->setVisible(false);
    ui->checkBox_4->setVisible(false);
}


void df_gui_version_1::on_pushButton_12_clicked()
{
    //QUIT Button
    // Disconnect the readyRead signal
    disconnect(socket, &QUdpSocket::readyRead, this, &df_gui_version_1::readDatagrams);

    // Close the UDP socket
    socket->close();

    // Disconnect the readyRead signal
    disconnect(socket2, &QUdpSocket::readyRead, this, &df_gui_version_1::readDatagrams2);

    // Close the UDP socket
    socket2->close();
    x_itr=0, x_lop=0;
    numSamples = 1000000;    // 1 million samples
    f1=400000000.0;
    f2=5900000000.0;



    dbval=100;


    x_itr1z=0, x_lop1z=1;
    angle_to_addz=0.1757;

    QApplication::quit();  // Ends the application's event loop and closes the application


}
void df_gui_version_1::on_pushButton_10_clicked()
{
    //====================Apply Button For Scanner
    // socket2= new QUdpSocket(this);


    // if(!ui->lineEdit_4->text().isEmpty() && !ui->lineEdit_6->text().isEmpty()){

    //     qint16 cf,fft_N,gn;
    //     QString fft_N_value = ui->comboBox_7->currentText();
    //     cf= ui->lineEdit_4->text().toInt();
    //     gn= ui->lineEdit_6->text().toInt();
    //     fft_N = fft_N_value.toInt();
    //     qDebug()<<"Befor sent CF "<<cf;
    //     qDebug()<<"Befor sent fft_N "<<fft_N;
    //     qDebug()<<"Befor sent GAIN "<<gn;
    //     // cf=cf;
    //     qDebug()<<"NEW  CF "<<f1;
    //     senditnow_2(cf,fft_N,gn);
    // }
    //DF Settings Apply
    socket3= new QUdpSocket(this);


    if(!ui->lineEdit_4->text().isEmpty()  && !ui->lineEdit_6->text().isEmpty() && ui->comboBox_7->currentText()!="--" && ui->comboBox_5->currentText()!="--" && ui->lineEdit_4->text().toInt()<5900){

        qint16 cf,rwb,rwgn;
        cf= ui->lineEdit_4->text().toInt();
        rwb= ui->comboBox_7->currentText().toInt();
        rwgn= ui->lineEdit_6->text().toInt();
        // if(freq_list.size()>=16){
        //     freq_list.clear();
        // }
        qDebug()<<"Befor sent cf "<<cf;
        qDebug()<<"Befor sent Rcx Gain "<<rwb;
        qDebug()<<"Befor sent GAIN "<<rwgn;

        if(freq_list.size()<16){
        freq_list.append(cf);
        freq_list.append(rwb);
        freq_list.append(rwgn);
        freq_list.append(ui->comboBox_5->currentText().toInt());
        }else
        {
            qDebug()<<"Alredy Added 4 freq Press Reset";
        }

        if(ui->comboBox_5->currentText()=="1"){
            ui->label_43->setText(ui->lineEdit_4->text());
            ui->label_18->setText(ui->lineEdit_4->text()+" MHz");
            ui->label_44->setText(ui->lineEdit_6->text());
            ui->label_45->setText(ui->comboBox_7->currentText());
            ui->comboBox_5->addItem("2");
            ui->checkBox->setEnabled(true);

        }
        if(ui->comboBox_5->currentText()=="2"){
            ui->label_55->setText(ui->lineEdit_4->text());
            ui->label_19->setText(ui->lineEdit_4->text()+" MHz");
            ui->label_56->setText(ui->lineEdit_6->text());
            ui->label_57->setText(ui->comboBox_7->currentText());
            ui->comboBox_5->addItem("3");
            ui->checkBox_2->setEnabled(true);


        }
        if(ui->comboBox_5->currentText()=="3"){
            ui->label_59->setText(ui->lineEdit_4->text());
            ui->label_21->setText(ui->lineEdit_4->text()+" MHz");
            ui->label_60->setText(ui->lineEdit_6->text());
            ui->label_61->setText(ui->comboBox_7->currentText());
            ui->comboBox_5->addItem("4");
            ui->checkBox_3->setEnabled(true);


        }
        if(ui->comboBox_5->currentText()=="4"){
            ui->label_63->setText(ui->lineEdit_4->text());
            ui->label_23->setText(ui->lineEdit_4->text()+" MHz");
            ui->label_64->setText(ui->lineEdit_6->text());
            ui->label_65->setText(ui->comboBox_7->currentText());
            ui->checkBox_4->setEnabled(true);

        }



        //f1=0;
        //f2=0;
        //f1=sf*1000000;
        //f2=ef*1000000;

        //qDebug()<<"NEW  F1 "<<f1;
        //qDebug()<<"NEW  F2 "<<f2;
        ui->comboBox_5->removeItem( ui->comboBox_5->currentIndex());
        ui->comboBox_5->setCurrentIndex(0);

        ui->comboBox_7->setEnabled(false);
        x_range=ui->comboBox_7->currentText().toInt();

        senditnow_2();
    }
    else{
        //qDebug()<<"Either Center Frequency is not in Range or Some Feild is mising";
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Critical Error");
        msgBox.setText("Either Center Frequency is not in Range or Some Feild is mising");
        msgBox.setInformativeText("Please check the input data.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }


}


void df_gui_version_1::on_pushButton_9_clicked()
{
    ui->lineEdit_4->setText("");
    ui->lineEdit_6->setText("");
    ui->comboBox_5->clear();
    ui->comboBox_5->addItem("--");
    ui->comboBox_5->addItem("1");
    // ui->comboBox_5->addItem("2");
    // ui->comboBox_5->addItem("3");
    // ui->comboBox_5->addItem("4");
    ui->comboBox_7->setEnabled(true);
    ui->comboBox_7->setCurrentIndex(0);
    freq_list.clear();
    seriez3->clear();
    seriez_t2->clear();
    seriez_t3->clear();
    seriez_t4->clear();
    aoa_data.clear();
    aoa_data2.clear();
    aoa_data3.clear();
    aoa_data4.clear();

        ui->label_43->setText(ui->lineEdit_4->text());
        ui->label_18->setText(ui->lineEdit_4->text()+" MHz");
        ui->label_44->setText(ui->lineEdit_6->text());
        ui->label_45->setText(ui->comboBox_7->currentText());


        ui->label_55->setText(ui->lineEdit_4->text());
        ui->label_19->setText(ui->lineEdit_4->text()+" MHz");
        ui->label_56->setText(ui->lineEdit_6->text());
        ui->label_57->setText(ui->comboBox_7->currentText());

        ui->label_59->setText(ui->lineEdit_4->text());
        ui->label_21->setText(ui->lineEdit_4->text()+" MHz");
        ui->label_60->setText(ui->lineEdit_6->text());
        ui->label_61->setText(ui->comboBox_7->currentText());


        ui->label_63->setText(ui->lineEdit_4->text());
        ui->label_23->setText(ui->lineEdit_4->text()+" MHz");
        ui->label_64->setText(ui->lineEdit_6->text());
        ui->label_65->setText(ui->comboBox_7->currentText());

        ui->label_68->setText("--");
        ui->label_69->setText("--");
        ui->label_70->setText("--");
        ui->label_71->setText("--");

        seriez3->clear();
        seriez_t2->clear();
        seriez_t3->clear();
        seriez_t4->clear();
        aoa_data.clear();
        aoa_data2.clear();
        aoa_data3.clear();
        aoa_data4.clear();



        xxDataz1.clear();
        xxDataz2.clear();
        xxDataz3.clear();
        xxDataz4.clear();

        yyDataz1.clear();
        yyDataz2.clear();
        yyDataz3.clear();
        yyDataz4.clear();

        ui->checkBox->setEnabled(false);
        ui->checkBox_2->setEnabled(false);
        ui->checkBox_3->setEnabled(false);
        ui->checkBox_4->setEnabled(false);


        // ui->customplot_2->clearGraphs();
        // ui->customplot_3->clearGraphs();
        // ui->customplot_4->clearGraphs();
        // ui->customplot_5->clearGraphs();
        // ui->customplot_6->clearGraphs();
        // ui->customplot_7->clearGraphs();
        // ui->customplot_8->clearGraphs();
        // ui->customplot_9->clearGraphs();
       ui->customplot_2->graph(0)->setData(xxDataz5, yyDataz5);
       ui->customplot_3->graph(0)->setData(xxDataz5, yyDataz5);
       ui->customplot_4->graph(0)->setData(xxDataz5, yyDataz5);
       ui->customplot_5->graph(0)->setData(xxDataz5, yyDataz5);
       ui->customplot_6->graph(0)->setData(xxDataz5, yyDataz5);
       ui->customplot_7->graph(0)->setData(xxDataz5, yyDataz5);
       ui->customplot_8->graph(0)->setData(xxDataz5, yyDataz5);
       ui->customplot_9->graph(0)->setData(xxDataz5, yyDataz5);

       ui->customplot_2->graph(0)->setData(xxDataz5, yyDataz5);
       ui->customplot_3->graph(0)->setData(xxDataz5, yyDataz5);
       ui->customplot_4->graph(0)->setData(xxDataz5, yyDataz5);
       ui->customplot_5->graph(0)->setData(xxDataz5, yyDataz5);
       ui->customplot_6->graph(0)->setData(xxDataz5, yyDataz5);
       ui->customplot_7->graph(0)->setData(xxDataz5, yyDataz5);
       ui->customplot_8->graph(0)->setData(xxDataz5, yyDataz5);
       ui->customplot_9->graph(0)->setData(xxDataz5, yyDataz5);

       ui->customplot_2->graph(1)->setData(xxDataz5, yyDataz5);
       ui->customplot_3->graph(1)->setData(xxDataz5, yyDataz5);
       ui->customplot_4->graph(1)->setData(xxDataz5, yyDataz5);
       ui->customplot_5->graph(1)->setData(xxDataz5, yyDataz5);
       ui->customplot_6->graph(1)->setData(xxDataz5, yyDataz5);
       ui->customplot_7->graph(1)->setData(xxDataz5, yyDataz5);
       ui->customplot_8->graph(1)->setData(xxDataz5, yyDataz5);
       ui->customplot_9->graph(1)->setData(xxDataz5, yyDataz5);

       ui->customplot_2->graph(2)->setData(xxDataz5, yyDataz5);
       ui->customplot_3->graph(2)->setData(xxDataz5, yyDataz5);
       ui->customplot_4->graph(2)->setData(xxDataz5, yyDataz5);
       ui->customplot_5->graph(2)->setData(xxDataz5, yyDataz5);
       ui->customplot_6->graph(2)->setData(xxDataz5, yyDataz5);
       ui->customplot_7->graph(2)->setData(xxDataz5, yyDataz5);
       ui->customplot_8->graph(2)->setData(xxDataz5, yyDataz5);
       ui->customplot_9->graph(2)->setData(xxDataz5, yyDataz5);

       ui->customplot_2->graph(3)->setData(xxDataz5, yyDataz5);
       ui->customplot_3->graph(3)->setData(xxDataz5, yyDataz5);
       ui->customplot_4->graph(3)->setData(xxDataz5, yyDataz5);
       ui->customplot_5->graph(3)->setData(xxDataz5, yyDataz5);
       ui->customplot_6->graph(3)->setData(xxDataz5, yyDataz5);
       ui->customplot_7->graph(3)->setData(xxDataz5, yyDataz5);
       ui->customplot_8->graph(3)->setData(xxDataz5, yyDataz5);
       ui->customplot_9->graph(3)->setData(xxDataz5, yyDataz5);

       ui->customplot_2->replot();
       ui->customplot_2->update();
       ui->customplot_3->replot();
       ui->customplot_3->update();
       ui->customplot_4->replot();
       ui->customplot_4->update();
       ui->customplot_5->replot();
       ui->customplot_5->update();
       ui->customplot_6->replot();
       ui->customplot_6->update();
       ui->customplot_7->replot();
       ui->customplot_7->update();
       ui->customplot_8->replot();
       ui->customplot_8->update();
       ui->customplot_9->replot();
       ui->customplot_9->update();




        x_range=256;
        // freq_list.append(410);
        // freq_list.append(256);
        // freq_list.append(0);
        // freq_list.append(1);

        // freq_list.append(410);
        // freq_list.append(256);
        // freq_list.append(0);
        // freq_list.append(2);

        // freq_list.append(410);
        // freq_list.append(256);
        // freq_list.append(0);
        // freq_list.append(3);

        // freq_list.append(410);
        // freq_list.append(256);
        // freq_list.append(0);
        // freq_list.append(4);

        // senditnow_2(1,1,1);


}


void df_gui_version_1::senditnow(qint16 sf,qint16 ef,qint16 gn){

    QByteArray datagram;
    QDataStream stream(&datagram, QIODevice::WriteOnly);

    // Set the data stream to use big-endian or little-endian as needed (default is big-endian)
    stream.setByteOrder(QDataStream::LittleEndian); // Set to LittleEndian if your receiver expects it

    // Prepare the data
    qint16 header = 1122;            // Example value
    qint16 packet_type = 1;        // 1: set start/stop frequency; 2: gain set
    qint16 start_freq_OR_gain = sf; // Start frequency or gain
    qint16 stop_freq = ef;       // Stop frequency
    qint16 gain_ADC = gn;          // ADC gain

    // Write each integer to the datagram as a 4-byte value
    stream << header;
    stream << packet_type;
    stream << start_freq_OR_gain;
    stream << stop_freq;
    stream << gain_ADC;


    qDebug()<<"Befor sent 2 SF "<<start_freq_OR_gain;
    qDebug()<<"Befor sent 2 EF "<<stop_freq;
    qDebug()<<"Befor sent 2 GAIN "<<gain_ADC;

    // Define the target address and port
    QHostAddress targetAddress_sc("192.168.1.10"); // Change to your target IP address

    // Debug output
    qDebug() << "Final Datagram" << datagram.toHex();

    // Send the datagram
    qint64 bytesWritten = socket1->writeDatagram(datagram, targetAddress_sc, targetPort1);

    if (bytesWritten == -1) {
        qCritical() << "Failed to send datagram:" << socket1->errorString();
    } else {
        qDebug() << "Datagram sent:" << bytesWritten << "bytes. with data gram"<< datagram;


    }
}

void df_gui_version_1::senditnow_2(){

    QByteArray datagram;
    QDataStream stream(&datagram, QIODevice::WriteOnly);

    // Set the data stream to use big-endian or little-endian as needed (default is big-endian)
    stream.setByteOrder(QDataStream::LittleEndian); // Set to LittleEndian if your receiver expects it

    // Prepare the data
    // qint16 header = 1122;            // Example value
    // qint16 packet_type = 1;        // 1: set start/stop frequency; 2: gain set
    // qint16 LO_freq = cf; // Start frequency or gain
    // qint16 FFT_length = fft_N;       // Stop frequency
    // qint16 gain_ADC = gn;          // ADC gain

    // Write each integer to the datagram as a 4-byte value
    // stream << header;
    // stream << packet_type;
    // stream << LO_freq;
    // stream << FFT_length;
    // stream << gain_ADC;

    stream << freq_list;


    // qDebug()<<"Befor sent 2 LO_freq "<<LO_freq;
    // qDebug()<<"Befor sent 2 FFT_length "<<FFT_length;
    // qDebug()<<"Befor sent 2 gain_ADC "<<gain_ADC;

    // Define the target address and port
    QHostAddress targetAddress_df("192.168.1.9"); // DF IP address

    // Debug output
    qDebug() << "Final Datagram for socket2" << datagram.toHex();

    // Send the datagram
    qint64 bytesWritten = socket3->writeDatagram(datagram, targetAddress_df, targetPort2);

    if (bytesWritten == -1) {
        qCritical() << "Failed to send datagram:" << socket3->errorString();
    } else {
        qDebug() << "Datagram sent:" << bytesWritten << "bytes. with data gram"<< datagram;

        qDebug()<<"Sent List "<<freq_list;

    }
}
// void df_gui_version_1::on_Record_data_clicked()
// {
//     if (record_data == 0) {
//         record_data = 1;
//         ui->Record_data->setText("Start Recording");
//         ui->Record_data->setStyleSheet("background-color: red; color: white;"); // Set button to red
//         qDebug() << "Recording started.";
//     } else if (record_data == 1) {
//         record_data = 0;
//         ui->Record_data->setText("Stop Recording");
//         ui->Record_data->setStyleSheet("background-color: green; color: white;"); // Set button to green
//         qDebug() << "Recording stopped.";
//     }
// }

void df_gui_version_1::on_Record_data_clicked()
{
    if (record_data == 0) {
        record_data = 1;
        record_check=1;
        record_check_scaner=1;
        ui->Record_data->setText("STOP RECORDING");
        fileCounter_scanner =1;
        fileCounter_df =1;
        // Initialize the timer for blinking effect
        if (!blinkTimer) {
            blinkTimer = new QTimer(this);
            connect(blinkTimer, &QTimer::timeout, this, &df_gui_version_1::toggleButtonColor);
        }
        blinkTimer->start(500); // Blink every 500 ms
    } else {
        record_data = 0;
        ui->Record_data->setText("START RECORDING");

        // Stop the blinking effect
        if (blinkTimer) {
            blinkTimer->stop();
            ui->Record_data->setStyleSheet("background-color: green; color: white;"); // Reset to default style
        }
    }
}

void df_gui_version_1::toggleButtonColor()
{
    if (isRed) {
        ui->Record_data->setStyleSheet("background-color: red; color: white;"); // Red for active recording
    } else {
        ui->Record_data->setStyleSheet("background-color: yellow; color: black;"); // Alternate color
    }
    isRed = !isRed; // Toggle the state
}

void df_gui_version_1::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked()==false){
        scan1=0;
        xxDataz1.clear();
        yyDataz1.clear();
        ui->customplot_2->graph(0)->setData(xxDataz5, yyDataz5);
        ui->customplot_3->graph(0)->setData(xxDataz5, yyDataz5);
        ui->customplot_4->graph(0)->setData(xxDataz5, yyDataz5);
        ui->customplot_5->graph(0)->setData(xxDataz5, yyDataz5);
        ui->customplot_6->graph(0)->setData(xxDataz5, yyDataz5);
        ui->customplot_7->graph(0)->setData(xxDataz5, yyDataz5);
        ui->customplot_8->graph(0)->setData(xxDataz5, yyDataz5);
        ui->customplot_9->graph(0)->setData(xxDataz5, yyDataz5);
        ui->customplot_2->replot();
        ui->customplot_2->update();
        ui->customplot_3->replot();
        ui->customplot_3->update();
        ui->customplot_4->replot();
        ui->customplot_4->update();
        ui->customplot_5->replot();
        ui->customplot_5->update();
        ui->customplot_6->replot();
        ui->customplot_6->update();
        ui->customplot_7->replot();
        ui->customplot_7->update();
        ui->customplot_8->replot();
        ui->customplot_8->update();
        ui->customplot_9->replot();
        ui->customplot_9->update();
    }
    else if(ui->checkBox->isChecked()==true){
        scan1=1;
    }
}


void df_gui_version_1::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->isChecked()==false){
        scan2=0;
        xxDataz2.clear();
        yyDataz2.clear();
        ui->customplot_2->graph(1)->setData(xxDataz5, yyDataz5);
        ui->customplot_3->graph(1)->setData(xxDataz5, yyDataz5);
        ui->customplot_4->graph(1)->setData(xxDataz5, yyDataz5);
        ui->customplot_5->graph(1)->setData(xxDataz5, yyDataz5);
        ui->customplot_6->graph(1)->setData(xxDataz5, yyDataz5);
        ui->customplot_7->graph(1)->setData(xxDataz5, yyDataz5);
        ui->customplot_8->graph(1)->setData(xxDataz5, yyDataz5);
        ui->customplot_9->graph(1)->setData(xxDataz5, yyDataz5);
        ui->customplot_2->replot();
        ui->customplot_2->update();
        ui->customplot_3->replot();
        ui->customplot_3->update();
        ui->customplot_4->replot();
        ui->customplot_4->update();
        ui->customplot_5->replot();
        ui->customplot_5->update();
        ui->customplot_6->replot();
        ui->customplot_6->update();
        ui->customplot_7->replot();
        ui->customplot_7->update();
        ui->customplot_8->replot();
        ui->customplot_8->update();
        ui->customplot_9->replot();
        ui->customplot_9->update();
    }
    else if(ui->checkBox_2->isChecked()==true){
        scan2=1;
    }
}


void df_gui_version_1::on_checkBox_3_clicked()
{
    if(ui->checkBox_3->isChecked()==false){
        scan3=0;
        xxDataz3.clear();
        yyDataz3.clear();
        ui->customplot_2->graph(2)->setData(xxDataz5, yyDataz5);
        ui->customplot_3->graph(2)->setData(xxDataz5, yyDataz5);
        ui->customplot_4->graph(2)->setData(xxDataz5, yyDataz5);
        ui->customplot_5->graph(2)->setData(xxDataz5, yyDataz5);
        ui->customplot_6->graph(2)->setData(xxDataz5, yyDataz5);
        ui->customplot_7->graph(2)->setData(xxDataz5, yyDataz5);
        ui->customplot_8->graph(2)->setData(xxDataz5, yyDataz5);
        ui->customplot_9->graph(2)->setData(xxDataz5, yyDataz5);
        ui->customplot_2->replot();
        ui->customplot_2->update();
        ui->customplot_3->replot();
        ui->customplot_3->update();
        ui->customplot_4->replot();
        ui->customplot_4->update();
        ui->customplot_5->replot();
        ui->customplot_5->update();
        ui->customplot_6->replot();
        ui->customplot_6->update();
        ui->customplot_7->replot();
        ui->customplot_7->update();
        ui->customplot_8->replot();
        ui->customplot_8->update();
        ui->customplot_9->replot();
        ui->customplot_9->update();
    }
    else if(ui->checkBox_3->isChecked()==true){
        scan3=1;
    }
}


void df_gui_version_1::on_checkBox_4_clicked()
{
    if(ui->checkBox_4->isChecked()==false){
        scan4=0;
        xxDataz4.clear();
        yyDataz4.clear();
        ui->customplot_2->graph(3)->setData(xxDataz5, yyDataz5);
        ui->customplot_3->graph(3)->setData(xxDataz5, yyDataz5);
        ui->customplot_4->graph(3)->setData(xxDataz5, yyDataz5);
        ui->customplot_5->graph(3)->setData(xxDataz5, yyDataz5);
        ui->customplot_6->graph(3)->setData(xxDataz5, yyDataz5);
        ui->customplot_7->graph(3)->setData(xxDataz5, yyDataz5);
        ui->customplot_8->graph(3)->setData(xxDataz5, yyDataz5);
        ui->customplot_9->graph(3)->setData(xxDataz5, yyDataz5);
        ui->customplot_2->replot();
        ui->customplot_2->update();
        ui->customplot_3->replot();
        ui->customplot_3->update();
        ui->customplot_4->replot();
        ui->customplot_4->update();
        ui->customplot_5->replot();
        ui->customplot_5->update();
        ui->customplot_6->replot();
        ui->customplot_6->update();
        ui->customplot_7->replot();
        ui->customplot_7->update();
        ui->customplot_8->replot();
        ui->customplot_8->update();
        ui->customplot_9->replot();
        ui->customplot_9->update();
    }
    else if(ui->checkBox_4->isChecked()==true){
        scan4=1;
    }
}


void df_gui_version_1::findPeaks(const QVector<double>& xData, const QVector<double>& yData)
{

    // Loop through the data points to find peaks
    for (int i = 1; i < yData.size() - 1; ++i) {
        // Check if the current point is a local maximum
        if (yData[i] > yData[i - 1] && yData[i] > yData[i + 1]) {
            peaks.append(qMakePair(xData[i], yData[i]));
        }
    }

    // Sort peaks by y-value (descending order) to get the largest peaks
    std::sort(peaks.begin(), peaks.end(), [](const QPair<double, double>& a, const QPair<double, double>& b) {
        return a.second > b.second; // Sort by y value (peak height)
    });

    // Get the top 4 peaks
    peaks = peaks.mid(0, ui->comboBox_8->currentText().toInt());


    // Print peaks information (for debugging purposes)
    for (const auto& peak : peaks) {
        std::cout << "Peak at x: " << peak.first << " with y: " << peak.second << std::endl;
    }
}

