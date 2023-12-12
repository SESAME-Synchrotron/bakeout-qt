#ifndef HEATER_WIDGET_H
#define HEATER_WIDGET_H

#define OPEN_UI(object, CLASS, ...)      \
    if(!object || !object->isVisible())  \
        object = new CLASS(__VA_ARGS__); \
    object->show();

#include <QMainWindow>
#include <QString>
#include <qepicspv.h>
#include <temperaturegraph.h>
#include "confirmationdialog.h"
#include "client.h"

namespace Ui {
class heater_widget;
}

class heater_widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit heater_widget(QString num, QWidget *parent = nullptr);
    ~heater_widget();

private slots:
    void on_btnSaturationDisable_clicked();
    void on_satEnableDisable(QVariant);

private:
    Ui::heater_widget *ui;

    QString num;

    TemperatureGraph* graph;
    ConfirmationDialog* confirmationDialog;

    QEpicsPV* saturationDisabled;
};

#endif // HEATER_WIDGET_H
