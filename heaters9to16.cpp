#include "heaters9to16.h"
#include "ui_heaters9to16.h"

Heaters9To16::Heaters9To16(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Heaters9To16)
{
    ui->setupUi(this);

    QObject::connect(this->ui->btnClose, SIGNAL(clicked()), this, SLOT(close()));

    ui->ltHeater->addWidget(new heater_widget("9"));
    ui->ltHeater->addWidget(new heater_widget("10"));
    ui->ltHeater->addWidget(new heater_widget("11"));
    ui->ltHeater->addWidget(new heater_widget("12"));
    ui->ltHeater->addWidget(new heater_widget("13"));
    ui->ltHeater->addWidget(new heater_widget("14"));
    ui->ltHeater->addWidget(new heater_widget("15"));
    ui->ltHeater->addWidget(new heater_widget("16"));

    ui->Header->setFlat(false);
    ui->Header->setStyleSheet("border:0;");
}

Heaters9To16::~Heaters9To16()
{
    delete ui;
}
