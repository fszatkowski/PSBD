#ifndef ADMINADDTOCLASSES_H
#define ADMINADDTOCLASSES_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class AdminAddToClasses;
}

class AdminAddToClasses : public QDialog
{
    Q_OBJECT

public:
    explicit AdminAddToClasses(QWidget *parent = 0);
    ~AdminAddToClasses();

private slots:
    void on_return_button_clicked();

    void on_check_if_signed_button_clicked();

    void on_check_if_available_button_clicked();

    void on_sign_student_button_clicked();

    void on_sport_type_currentTextChanged(const QString &arg1);

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::AdminAddToClasses *ui;
    bool signed_flag;
    bool available_flag;
    bool add_flag;
    int c_id;
    QString current_pesel;
};

#endif // ADMINADDTOCLASSES_H
