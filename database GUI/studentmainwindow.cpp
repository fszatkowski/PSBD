#include "studentmainwindow.h"
#include "ui_studentmainwindow.h"

StudentMainWindow::StudentMainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentMainWindow)
{
    ui->setupUi(this);
}

StudentMainWindow::~StudentMainWindow()
{
    delete ui;
}

void StudentMainWindow::on_logout_button_clicked()
{
    this->close();
    w->show();
}
