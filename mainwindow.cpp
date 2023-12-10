#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

MainWindow::~MainWindow()
{
    delete ui;
}

