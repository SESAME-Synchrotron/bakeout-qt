#ifndef HEATERS9TO16_H
#define HEATERS9TO16_H

#include <QMainWindow>

namespace Ui {
class Heaters9To16;
}

class Heaters9To16 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Heaters9To16(QWidget *parent = nullptr);
    ~Heaters9To16();

private:
    Ui::Heaters9To16 *ui;
};

#endif // HEATERS9TO16_H
