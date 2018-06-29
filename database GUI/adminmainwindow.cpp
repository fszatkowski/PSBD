#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"
#include "adminraports.h"
#include "adminaddtoclasses.h"

AdminMainWindow::AdminMainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);
}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}

void AdminMainWindow::on_logout_button_clicked()
{
    this->close();
    w->show();
}

void AdminMainWindow::on_zapisy_button_clicked()
{
    AdminAddToClasses adds;
    adds.setModal(true);
    adds.exec();
}

void AdminMainWindow::on_raports_button_clicked()
{
    AdminRaports raports;
    raports.setModal(true);
    raports.exec();
}
