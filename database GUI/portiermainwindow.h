#ifndef PORTIERMAINWINDOW_H
#define PORTIERMAINWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class PortierMainWindow;
}

class PortierMainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PortierMainWindow(QWidget *parent = 0);
    ~PortierMainWindow();
    MainWindow *w;
private slots:
    void on_logout_button_clicked();

    void on_add_visit_button_clicked();

private:
    Ui::PortierMainWindow *ui;
};

#endif // PORTIERMAINWINDOW_H
