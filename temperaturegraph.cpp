#include "temperaturegraph.h"
#include "ui_temperaturegraph.h"

TemperatureGraph::TemperatureGraph(QString num, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TemperatureGraph)
{
    ui->setupUi(this);

    setWindowTitle("Heater " + num + " graph");
    this->ui->pltHeater->setVariableNameSubstitutionsProperty("num=" + num);
    this->ui->pltHeater->setTitle("Heater " + num);
}

TemperatureGraph::~TemperatureGraph()
{
    delete ui;
}
