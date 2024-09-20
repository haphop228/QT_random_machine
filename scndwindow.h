#ifndef SCNDWINDOW_H
#define SCNDWINDOW_H

#include <QMainWindow>

namespace Ui {
class scndWindow;
}

class scndWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit scndWindow(QWidget *parent = nullptr);
    ~scndWindow();

private slots:
    void start();
    void updateNumber1();
    void updateNumber2();
    void updateNumber3();
    void stop();

private:
    Ui::scndWindow *ui;
    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
};

#endif // SCNDWINDOW_H
