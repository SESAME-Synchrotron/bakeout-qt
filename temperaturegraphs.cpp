#include "temperaturegraphs.h"
#include "ui_temperaturegraphs.h"

TemperatureGraphs::TemperatureGraphs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TemperatureGraphs),
    windowSize(100)
{
    ui->setupUi(this);

    QList<Qt::GlobalColor> colors = { Qt::black, Qt::red, Qt::green, Qt::blue, Qt::yellow,
                                      Qt::darkYellow, Qt::darkGray, Qt::cyan, Qt::magenta, Qt::darkRed,
                                      Qt::gray, Qt::darkGreen, Qt::darkBlue, Qt::darkCyan, Qt::darkMagenta,
                                      Qt::lightGray };

    for(int heaterNum = 1; heaterNum <= 16; ++heaterNum)
    {
        QEpicsPV* pv = new QEpicsPV(QString::asprintf("HEATER%d:getTemp", heaterNum), this);
        this->temperaturePVs.push_back(pv);

        CircularBuffer* buffer = new CircularBuffer(windowSize);
        temperatureBuffers.push_back(buffer);

        QwtPlotCurve *curve = new QwtPlotCurve(QString::asprintf("Heater %d", heaterNum));
        curve->setPen(colors[heaterNum-1], 1);
        curve->setVisible(false);
        this->temperatureCurves.push_back(curve);

        legend = new QwtLegend();
        legend->setDefaultItemMode(QwtLegendData::Checkable);
        this->ui->pltHeaters->insertLegend(legend, QwtPlot::BottomLegend);
        QObject::connect(legend, &QwtLegend::checked, this, &TemperatureGraphs::onLegendStatusChanged);
    }

    timeIndexArr = new double[windowSize];
    for(int i = 0; i < this->windowSize; i++) {
        timeIndexArr[i] = i + 1.0;
    }

    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(onTemperatureUpdate()));

    this->ui->pltHeaters->setAutoReplot(true);
    this->ui->pltHeaters->setAxisScale(QwtPlot::xBottom, 1, windowSize, 10);

    QwtPlotGrid* gridX = new QwtPlotGrid;
    gridX->setAxes(QwtPlot::xBottom, QwtPlot::yLeft);
    gridX->setPen(Qt::black, 0.25);
    gridX->attach(this->ui->pltHeaters);

    this->timer->start(100);
}

TemperatureGraphs::~TemperatureGraphs()
{
    delete ui;
}

void TemperatureGraphs::onTemperatureUpdate()
{
    for (int heaterIndex = 0; heaterIndex < 16; ++heaterIndex)
    {
        this->temperatureBuffers[heaterIndex]->enqueue(temperaturePVs[heaterIndex]->get().toDouble());
        this->ui->pltHeaters->setAxisScale(QwtPlot::xBottom, 1, this->temperatureBuffers[heaterIndex]->numItems, 10);
        this->temperaturesPlotData = new QwtPointArrayData(timeIndexArr, this->temperatureBuffers[heaterIndex]->dataArr, this->temperatureBuffers[heaterIndex]->numItems);
        this->temperatureCurves[heaterIndex]->setSamples(this->temperaturesPlotData);
        this->temperatureCurves[heaterIndex]->attach(this->ui->pltHeaters);
        this->ui->pltHeaters->replot();
        this->ui->pltHeaters->update();
    }
}

void TemperatureGraphs::onLegendStatusChanged(const QVariant& itemInfo, bool status, int index)
{
    QwtPlotItem* plotItem = qvariant_cast <QwtPlotItem*>(itemInfo);
    const QRegularExpression reHeaterNumber("\\d+");

    if (plotItem)
    {
        QString curveName = plotItem->title().text();
        QRegularExpressionMatch heaterNumberMatch = reHeaterNumber.match(curveName);
        if (heaterNumberMatch.hasMatch())
        {
            int heaterIndex = heaterNumberMatch.captured(0).toInt() - 1;
            if (status)
                temperatureCurves[heaterIndex]->setVisible(true);
            else
                temperatureCurves[heaterIndex]->setVisible(false);
        }
    }
}
