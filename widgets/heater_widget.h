#ifndef HEATER_WIDGET_H
#define HEATER_WIDGET_H

#include <QMainWindow>

namespace Ui {
class heater_widget;
}

class heater_widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit heater_widget(QString num, QWidget *parent = nullptr);
    ~heater_widget();

private:
    Ui::heater_widget *ui;
};

#endif // HEATER_WIDGET_H
