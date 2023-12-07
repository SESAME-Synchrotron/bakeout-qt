#include "tempgraphs9to16.h"
#include "ui_tempgraphs9to16.h"

TempGraphs9To16::TempGraphs9To16(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TempGraphs9To16)
{
    ui->setupUi(this);

    QObject::connect(this->ui->btnClose, SIGNAL(clicked()), this, SLOT(close()));
}

TempGraphs9To16::~TempGraphs9To16()
{
    delete ui;
}
