#include "heaters1to8.h"
#include "ui_heaters1to8.h"

Heaters1To8::Heaters1To8(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Heaters1To8)
{
    ui->setupUi(this);

    QObject::connect(this->ui->btnClose, SIGNAL(clicked()), this, SLOT(close()));

    ui->ltHeater->addWidget(new heater_widget("1"));
    ui->ltHeater->addWidget(new heater_widget("2"));
    ui->ltHeater->addWidget(new heater_widget("3"));
    ui->ltHeater->addWidget(new heater_widget("4"));
    ui->ltHeater->addWidget(new heater_widget("5"));
    ui->ltHeater->addWidget(new heater_widget("6"));
    ui->ltHeater->addWidget(new heater_widget("7"));
    ui->ltHeater->addWidget(new heater_widget("8"));

    ui->Header->setFlat(false);
    ui->Header->setStyleSheet("border:0;");
}

Heaters1To8::~Heaters1To8()
{
    delete ui;
}
