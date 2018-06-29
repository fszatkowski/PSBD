#include "adminraports.h"
#include "ui_adminraports.h"
#include "raportspasses.h"
#include "raportspopular.h"
#include "raportsrushhour.h"

AdminRaports::AdminRaports(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminRaports)
{
    ui->setupUi(this);
}

AdminRaports::~AdminRaports()
{
    delete ui;
}

void AdminRaports::on_return_button_clicked()
{
    this->close();
}

void AdminRaports::on_popular_button_clicked()
{
    RaportsPopular pop;
    pop.setModal(true);
    pop.exec();
}

void AdminRaports::on_rush_hour_button_clicked()
{
    RaportsRushHour rush;
    rush.setModal(true);
    rush.exec();
}

void AdminRaports::on_pass_button_clicked()
{
    RaportsPasses pass;
    pass.setModal(true);
    pass.exec();
}
