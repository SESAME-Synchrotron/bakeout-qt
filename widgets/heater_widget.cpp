#include "heater_widget.h"
#include "ui_heater_widget.h"

heater_widget::heater_widget(QString num, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::heater_widget)
{
    ui->setupUi(this);

    ui->heaterName->setText("Heater " + QString::asprintf("%02d", num.toInt()));
    ui->ledHeaterEnable->setVariableNameSubstitutionsProperty("num=" + num);
    ui->btnHeaterEnable->setVariableNameSubstitutionsProperty("num=" + num);
    ui->btnHeaterDisable->setVariableNameSubstitutionsProperty("num=" + num);
    ui->temperatureReading->setVariableNameSubstitutionsProperty("num=" + num);
    ui->ledHeaterStatus->setVariableNameSubstitutionsProperty("num=" + num);
    ui->temperatureSetpoint->setVariableNameSubstitutionsProperty("num=" + num);
    ui->temperatureSetpointReadback->setVariableNameSubstitutionsProperty("num=" + num);
    ui->incrementSetPoint->setVariableNameSubstitutionsProperty("num=" + num);
    ui->temperatureSetRate->setVariableNameSubstitutionsProperty("num=" + num);
    ui->temperatureRateReadback->setVariableNameSubstitutionsProperty("num=" + num);
    ui->interlockSetpoint->setVariableNameSubstitutionsProperty("num=" + num);
    ui->interlockReadback->setVariableNameSubstitutionsProperty("num=" + num);
    ui->ledInterlockStatus->setVariableNameSubstitutionsProperty("num=" + num);
    ui->ledSaturationStatus->setVariableNameSubstitutionsProperty("num=" + num);
    ui->btnSaturationEnable->setVariableNameSubstitutionsProperty("num=" + num);
    ui->btnSaturationDisable->setVariableNameSubstitutionsProperty("num=" + num);
    ui->remainingTime->setVariableNameSubstitutionsProperty("num=" + num);
}

heater_widget::~heater_widget()
{
    delete ui;
}
