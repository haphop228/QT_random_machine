#ifndef LOGINERROR_H
#define LOGINERROR_H

#include <QDialog>

namespace Ui {
class LoginError;
}

class LoginError : public QDialog
{
    Q_OBJECT

public:
    explicit LoginError(QWidget *parent = nullptr);
    ~LoginError();

private slots:
    void setupSettingsLoginError();

private:
    Ui::LoginError *ui;
};

#endif // LOGINERROR_H
