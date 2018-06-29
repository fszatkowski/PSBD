#include "portiermainwindow.h"
#include "ui_portiermainwindow.h"
#include "portieraddvisit.h"

PortierMainWindow::PortierMainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PortierMainWindow)
{
    ui->setupUi(this);
}

PortierMainWindow::~PortierMainWindow()
{
    delete ui;
}

void PortierMainWindow::on_logout_button_clicked()
{
    this->close();
    w->show();
}

void PortierMainWindow::on_add_visit_button_clicked()
{
    PortierAddVisit add;
    add.setModal(true);
    add.exec();
}
