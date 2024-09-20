#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "scndwindow.h"
#include "loginerror.h"
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(750, 500);
    this->setWindowTitle("sssss");

    setupLayout();
    setupSettingsMainWindow();

    //ui->loginbtn->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
    connect(ui->loginbtn, &QPushButton::clicked, this, &::MainWindow::on_loginbtn_Clicked);

}

void MainWindow::setupSettingsMainWindow(){
    ui->loginbtn->setText("Login");
    ui->loginbtn->setMinimumSize(70, 50);
    ui->loginbtn->setMaximumSize(200, 100);

    ui->loginLabel->setText("Input username");
    ui->loginLabel->setMaximumSize(100, 20);
    //ui->loginLabel->setMinimumSize(50, 50);

    ui->pswdLabel->setText("Input password");
    ui->pswdLabel->setMaximumSize(100, 20);
    //ui->pswdLabel->setMinimumSize(50, 50);
}


void MainWindow::setupLayout(){

    // Layout for LineEdit login and Label login
    QVBoxLayout *inputlayoutlogin = new QVBoxLayout();
    inputlayoutlogin->addWidget(ui->loginLabel);
    inputlayoutlogin->addWidget(ui->loginLine);

    // Layout for LineEdit pswd and Label pswd

    QVBoxLayout *inputlayoutpswd = new QVBoxLayout();
    inputlayoutpswd->addWidget(ui-> pswdLabel);
    inputlayoutpswd->addWidget(ui-> pswdLine);

    // Layout for both pswd and login

    QHBoxLayout *inputlayout = new QHBoxLayout();
    inputlayout->addLayout(inputlayoutlogin);
    inputlayout->addLayout(inputlayoutpswd);

    // Layout for input and button
    QHBoxLayout *layoutbutton = new QHBoxLayout();
    layoutbutton->addWidget(ui->loginbtn);


    QVBoxLayout *layout = new QVBoxLayout();
    layout->addLayout(inputlayout);
    layout->addLayout(layoutbutton);

    //layout->addWidget(ui->loginbtn);
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginbtn_Clicked()
{
    QString username = ui->loginLine->text();
    QString password = ui->pswdLine->text();

    if (username == "" && password == "") {
        LoginError *LoginError = new class LoginError;
        LoginError->show();
    } else {
        scndWindow *scndWindow = new class scndWindow();
        scndWindow->show();
        this->hide();
    }
}



