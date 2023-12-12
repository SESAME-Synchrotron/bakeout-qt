#ifndef CONFIRMATIONDIALOG_H
#define CONFIRMATIONDIALOG_H

#include <QMainWindow>
#include <functional>

namespace Ui {
class ConfirmationDialog;
}

class ConfirmationDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConfirmationDialog(QString message, std::function<void()> func, QWidget *parent = nullptr);
    ~ConfirmationDialog();

    void closeEvent(QCloseEvent *event);

private slots:
    void on_btnConfirm_clicked();

private:
    Ui::ConfirmationDialog *ui;
    std::function<void()> func;
};

#endif // CONFIRMATIONDIALOG_H
