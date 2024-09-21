#include "scndwindow.h"
#include "ui_scndwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QMessageBox>
#include <cstdlib>
#include <ctime>

scndWindow::scndWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::scndWindow)
{
    ui->setupUi(this);
    srand(static_cast<unsigned int>(time(nullptr)));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(ui->label);
    layout->addWidget(ui->label_2);
    layout->addWidget(ui->label_3);
    layout->addWidget(ui->pushButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Create timers for each number
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    timer3 = new QTimer(this);

    connect(timer1, &QTimer::timeout, this, &scndWindow::updateNumber1);
    connect(timer2, &QTimer::timeout, this, &scndWindow::updateNumber2);
    connect(timer3, &QTimer::timeout, this, &scndWindow::updateNumber3);

    connect(ui->pushButton, &QPushButton::clicked, this, &scndWindow::start);


}

scndWindow::~scndWindow()
{
    delete ui;
}

void scndWindow::start()
{
    timer1->start(100);  // each timer updates every 100 ms
    timer2->start(100);
    timer3->start(100);


    QTimer::singleShot(3000, this, &scndWindow::stop); // stop timer in 3 seconds
}

void scndWindow::updateNumber1()
{
    int randomValue = rand() % 2;  // generate number between 0 and 1
    ui->label->setText(QString::number(randomValue));
}

void scndWindow::updateNumber2()
{
    int randomValue = rand() % 2;
    ui->label_2->setText(QString::number(randomValue));
}

void scndWindow::updateNumber3()
{
    int randomValue = rand() % 2;
    ui->label_3->setText(QString::number(randomValue));
}

void scndWindow::stop()
{
    timer1->stop();
    timer2->stop();
    timer3->stop();

    // get final results
    int num1 = ui->label->text().toInt();
    int num2 = ui->label_2->text().toInt();
    int num3 = ui->label_3->text().toInt();

    // Check if you win or not
    if (num1 == num2 && num2 == num3) {
        QMessageBox::information(this, "Result", "Congratulations! You win!");
    } else {
        QMessageBox::information(this, "Result", "Unfortunately, you lose.");
    }
}
