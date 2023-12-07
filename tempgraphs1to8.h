#ifndef TEMPGRAPHS1TO8_H
#define TEMPGRAPHS1TO8_H

#include <QMainWindow>

namespace Ui {
class TempGraphs1To8;
}

class TempGraphs1To8 : public QMainWindow
{
    Q_OBJECT

public:
    explicit TempGraphs1To8(QWidget *parent = nullptr);
    ~TempGraphs1To8();

private:
    Ui::TempGraphs1To8 *ui;
};

#endif // TEMPGRAPHS1TO8_H
