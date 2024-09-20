#include "loginerror.h"
#include "ui_loginerror.h"
#include <QVBoxLayout>
LoginError::LoginError(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginError)
{
    ui->setupUi(this);

    ui->errorlabel->setText("You wrote nothing, please fill in the labels!");
    ui->errorlabel->setMinimumSize(400, 25);
    QVBoxLayout *errorlayout = new QVBoxLayout();
    errorlayout->addWidget(ui->errorlabel);

}

LoginError::~LoginError()
{
    delete ui;
}


void LoginError::setupSettingsLoginError(){
    ui->errorlabel->setMinimumSize(400, 25);

    ui->errorlabel->setText("You wrote nothing, please fill in the labels!");
}
