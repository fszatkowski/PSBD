#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
    MainWindow *w;

private slots:
    void on_return_button_clicked();

    void on_log_in_button_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
