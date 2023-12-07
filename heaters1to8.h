#ifndef HEATERS1TO8_H
#define HEATERS1TO8_H

#include <QMainWindow>

namespace Ui {
class Heaters1To8;
}

class Heaters1To8 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Heaters1To8(QWidget *parent = nullptr);
    ~Heaters1To8();

private:
    Ui::Heaters1To8 *ui;
};

#endif // HEATERS1TO8_H
