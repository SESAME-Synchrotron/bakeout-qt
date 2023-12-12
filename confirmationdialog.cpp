#include "confirmationdialog.h"
#include "ui_confirmationdialog.h"

ConfirmationDialog::ConfirmationDialog(QString message, std::function<void()> func, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfirmationDialog)
{
    ui->setupUi(this);
    ui->confirmationMessage->setText(message);
    QObject::connect(this->ui->btnCancel, SIGNAL(clicked()), this, SLOT(close()));

    this->func = func;
}

ConfirmationDialog::~ConfirmationDialog()
{
    delete ui;
}

void ConfirmationDialog::closeEvent(QCloseEvent *event) {
    // This function is useful to handle closing the window from the tab bar (x button)
    QWidget::closeEvent(event);
}

void ConfirmationDialog::on_btnConfirm_clicked()
{
    func();
    this->close();
}
