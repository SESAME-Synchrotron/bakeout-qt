#ifndef TEMPERATUREGRAPHS_H
#define TEMPERATUREGRAPHS_H

#include <QMainWindow>
#include <qepicspv.h>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>
#include <qwt_legend_label.h>
#include <qwt_legend_data.h>
#include <qwt_point_data.h>
#include <qwt_plot_grid.h>
#include <QRegularExpression>
#include <QTimer>
#include "circularbuffer.h"

namespace Ui {
class TemperatureGraphs;
}

class TemperatureGraphs : public QMainWindow
{
    Q_OBJECT

public:
    explicit TemperatureGraphs(QWidget *parent = nullptr);
    ~TemperatureGraphs();

private slots:
    void onTemperatureUpdate();
    void onLegendStatusChanged(const QVariant& itemInfo, bool status, int index);

private:
    Ui::TemperatureGraphs *ui;

    const int windowSize;
    double *timeIndexArr;
    QTimer *timer;

    QwtLegend *legend;
    QwtPointArrayData *temperaturesPlotData;

    QList<QwtPlotCurve*> temperatureCurves;
    QList<QEpicsPV*> temperaturePVs;
    QList<CircularBuffer*> temperatureBuffers;
};

#endif // TEMPERATUREGRAPHS_H
