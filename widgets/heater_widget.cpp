#include "heater_widget.h"
#include "ui_heater_widget.h"

heater_widget::heater_widget(QString num, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::heater_widget)
{
    ui->setupUi(this);

    this->graph = NULL;
    this->confirmationDialog = NULL;
    this->num = num;
    this->saturationDisabled = new QEpicsPV("HEATER" + num + ":disableSat");

    QObject::connect(this->ui->btnTempGraph, &QPushButton::clicked, this, [this, num](){ OPEN_UI(this->graph, TemperatureGraph, num, this) });
    QObject::connect(this->saturationDisabled, SIGNAL(valueChanged(QVariant)), this, SLOT(on_satEnableDisable(QVariant)));
    QObject::connect(this->saturationDisabled, SIGNAL(valueInited(QVariant)), this, SLOT(on_satEnableDisable(QVariant)));

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

void ::heater_widget::on_satEnableDisable(QVariant status)
{
    int enabled = 0;

    QString greenColor = "138, 226, 52";
    QString redColor = "255, 0, 0";

    if (status == enabled)
    {
        this->ui->btnSaturationEnable->setStyleSheet("background-color: rgb(" + greenColor + ")");
        this->ui->btnSaturationDisable->setStyleSheet("");
    } else
    {
        this->ui->btnSaturationEnable->setStyleSheet("");
        this->ui->btnSaturationDisable->setStyleSheet("background-color: rgb(" + redColor + ")");
    }
}

void heater_widget::on_btnSaturationDisable_clicked()
{
    QString pv_name = "HEATER" + this->num + ":disableSat";
    if (!this->saturationDisabled->get().toBool())
    {
        QString message = "Caution: If you turn off this option and heater " + num + " becomes saturated (no temperature increase for a while), other heaters won't be disabled. Be careful when disabling this option.";
        OPEN_UI(this->confirmationDialog, ConfirmationDialog, message, [pv_name](){ Client::writePV(pv_name, "1"); }, this);
    } else {
        Client::writePV(pv_name, "1");
    }
}
