#include "heater_widget.h"
#include "ui_heater_widget.h"

heater_widget::heater_widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::heater_widget)
{
    ui->setupUi(this);
    ui->groupBox->setTitle("Heater Name!!!");
}

heater_widget::~heater_widget()
{
    delete ui;
}
