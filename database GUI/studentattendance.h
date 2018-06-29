#ifndef STUDENTATTENDANCE_H
#define STUDENTATTENDANCE_H

#include <QDialog>

namespace Ui {
class StudentAttendance;
}

class StudentAttendance : public QDialog
{
    Q_OBJECT

public:
    explicit StudentAttendance(QWidget *parent = 0);
    ~StudentAttendance();

private slots:
    void on_return_button_clicked();

private:
    Ui::StudentAttendance *ui;
};

#endif // STUDENTATTENDANCE_H
