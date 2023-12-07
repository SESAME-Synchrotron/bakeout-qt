#include "heaters9to16.h"
#include "ui_heaters9to16.h"

Heaters9To16::Heaters9To16(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Heaters9To16)
{
    ui->setupUi(this);

    QObject::connect(this->ui->btnClose, SIGNAL(clicked()), this, SLOT(close()));
}

Heaters9To16::~Heaters9To16()
{
    delete ui;
}
