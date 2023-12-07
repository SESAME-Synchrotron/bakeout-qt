#include "tempgraphs1to8.h"
#include "ui_tempgraphs1to8.h"

TempGraphs1To8::TempGraphs1To8(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TempGraphs1To8)
{
    ui->setupUi(this);

    QObject::connect(this->ui->btnClose, SIGNAL(clicked()), this, SLOT(close()));
}

TempGraphs1To8::~TempGraphs1To8()
{
    delete ui;
}
