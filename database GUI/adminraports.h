#ifndef ADMINRAPORTS_H
#define ADMINRAPORTS_H
#include "adminmainwindow.h"
#include <QDialog>

namespace Ui {
class AdminRaports;
}

class AdminRaports : public QDialog
{
    Q_OBJECT

public:
    explicit AdminRaports(QWidget *parent = 0);
    ~AdminRaports();

private slots:
    void on_return_button_clicked();

    void on_popular_button_clicked();

    void on_rush_hour_button_clicked();

    void on_pass_button_clicked();

private:
    Ui::AdminRaports *ui;
};

#endif // ADMINRAPORTS_H
