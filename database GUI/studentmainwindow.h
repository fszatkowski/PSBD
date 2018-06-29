#ifndef STUDENTMAINWINDOW_H
#define STUDENTMAINWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class StudentMainWindow;
}

class StudentMainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StudentMainWindow(QWidget *parent = 0);
    ~StudentMainWindow();
    MainWindow *w;

private slots:
    void on_logout_button_clicked();

private:
    Ui::StudentMainWindow *ui;
};

#endif // STUDENTMAINWINDOW_H
