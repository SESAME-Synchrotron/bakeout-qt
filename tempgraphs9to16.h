#ifndef TEMPGRAPHS9TO16_H
#define TEMPGRAPHS9TO16_H

#include <QMainWindow>
#include <widgets/heater_widget.h>

namespace Ui {
class TempGraphs9To16;
}

class TempGraphs9To16 : public QMainWindow
{
    Q_OBJECT

public:
    explicit TempGraphs9To16(QWidget *parent = nullptr);
    ~TempGraphs9To16();

private:
    Ui::TempGraphs9To16 *ui;
};

#endif // TEMPGRAPHS9TO16_H
