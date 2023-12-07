#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->heaters1To8       = NULL;
    this->heaters9To16      = NULL;
    this->tempgraphs1To8    = NULL;
    this->tempgraphs9To16 = NULL;

    QObject::connect(this->ui->btnClose, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(this->ui->btnHeaters1To8, &QPushButton::clicked, this, [this](){ OPEN_UI(this->heaters1To8, Heaters1To8, this); });
    QObject::connect(this->ui->btnHeaters9To16, &QPushButton::clicked, this, [this](){ OPEN_UI(this->heaters9To16, Heaters9To16, this); });
    QObject::connect(this->ui->btnTempGraphs1To8, &QPushButton::clicked, this, [this](){ OPEN_UI(this->tempgraphs1To8, TempGraphs1To8, this); });
    QObject::connect(this->ui->btnTempGraphs9To16, &QPushButton::clicked, this, [this](){ OPEN_UI(this->tempgraphs9To16, TempGraphs9To16, this); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

