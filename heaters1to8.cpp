#include "heaters1to8.h"
#include "ui_heaters1to8.h"

Heaters1To8::Heaters1To8(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Heaters1To8)
{
    ui->setupUi(this);

    QObject::connect(this->ui->btnClose, SIGNAL(clicked()), this, SLOT(close()));
}

Heaters1To8::~Heaters1To8()
{
    delete ui;
}
