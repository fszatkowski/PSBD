#include "studentattendance.h"
#include "ui_studentattendance.h"

StudentAttendance::StudentAttendance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentAttendance)
{
    ui->setupUi(this);
}

StudentAttendance::~StudentAttendance()
{
    delete ui;
}

void StudentAttendance::on_return_button_clicked()
{
    this->close();
}
