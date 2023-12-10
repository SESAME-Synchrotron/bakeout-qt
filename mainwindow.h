#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define OPEN_UI(object, CLASS, ...)      \
    if(!object || !object->isVisible())  \
        object = new CLASS(__VA_ARGS__); \
    object->show();

#include <QMainWindow>
#include <widgets/heater_widget.h>

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
};
#endif // MAINWINDOW_H
