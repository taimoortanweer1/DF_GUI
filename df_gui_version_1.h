#ifndef DF_GUI_VERSION_1_H
#define DF_GUI_VERSION_1_H

#include "qcustomplot.h"
#include <QMainWindow>
#include <QIntValidator>
#include <windows.h>
#include <QTimer>
#include <QVector>
#include <QUdpSocket>
#include <dfchannel.h>
//#include <QtCharts/QPolarChart>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QLineSeries>
#include <QElapsedTimer>
#include <QtGui/QPixmap>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QAreaSeries>






QT_BEGIN_NAMESPACE
namespace Ui {
class df_gui_version_1;
}
QT_END_NAMESPACE

class df_gui_version_1 : public QMainWindow
{
    Q_OBJECT

public:
    df_gui_version_1(QWidget *parent = nullptr);
    ~df_gui_version_1();

    void toggleButtonColor();
private slots:
    //qreal f(qreal theta);
    //qreal integrateArea(qreal theta_start, qreal theta_end);
    void senditnow(qint16 sf,qint16 ef,qint16 gn);
    //void senditnow_2(qint16 cf,qint16 fft_N,qint16 gn);
    void senditnow_2();

    void readDatagrams();
    void readDatagrams2();
    void findPeaks(const QVector<double>& xData, const QVector<double>& yData);
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_verticalSlider_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    //void on_pushButton_6_clicked();

    void on_comboBox_8_currentTextChanged(const QString &arg1);

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_Record_data_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();


private:
    Ui::df_gui_version_1 *ui;
    //DFChannel df_channels;
    QUdpSocket *socket, *socket2,*socket1,*socket3;
    //QVector<double> xxData;
    //QVector<double> yyData;
    QVector<int> freq_list;
    QVector<int> freq_list1;
    quint16 targetPort1 =7; // Change to your target port
    quint16 targetPort2 =1500; // Change to your target port
    int allok=0;

    int x_range=256;
    QVector<QPointF> aoa_data;
    QVector<QPointF> aoa_data2;
    QVector<QPointF> aoa_data3;
    QVector<QPointF> aoa_data4;
    QVector<QPointF> Peaks_data;
    QVector<QPointF> Peaks_data2;
    QVector<QPointF> Peaks_data3;
    QVector<QPointF> Peaks_data4;

    QVector<double> xxDataz1;
    QVector<double> yyDataz1;
    QVector<double> xxDataz2;
    QVector<double> yyDataz2;
    QVector<double> xxDataz3;
    QVector<double> yyDataz3;
    QVector<double> xxDataz4;
    QVector<double> yyDataz4;
    QVector<double> xxDataz5{0,0};
    QVector<double> yyDataz5{0,0};
    QVector<QPointF> ideal_series;

    int scan1=0,scan2=0,scan3=0,scan4=0;

    QVector<QPair<double, double>> peaks; // Store (x, y) pairs of peaks
    QCPItemText *label;
    int record_check=1;
    int record_check_scaner=1;








};
#endif // DF_GUI_VERSION_1_H
