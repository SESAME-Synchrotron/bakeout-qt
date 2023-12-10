#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define OPEN_UI(object, CLASS, ...)      \
    if(!object || !object->isVisible())  \
        object = new CLASS(__VA_ARGS__); \
    object->show();

#include <QMainWindow>
#include <widgets/heater_widget.h>
#include <tempgraphs1to8.h>
#include <tempgraphs9to16.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    TempGraphs1To8* tempgraphs1To8;
    TempGraphs9To16* tempgraphs9To16;
};
#endif // MAINWINDOW_H
