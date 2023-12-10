#ifndef TEMPERATUREGRAPH_H
#define TEMPERATUREGRAPH_H

#include <QMainWindow>

namespace Ui {
class TemperatureGraph;
}

class TemperatureGraph : public QMainWindow
{
    Q_OBJECT

public:
    explicit TemperatureGraph(QString num, QWidget *parent = nullptr);
    ~TemperatureGraph();

private:
    Ui::TemperatureGraph *ui;
};

#endif // TEMPERATUREGRAPH_H
