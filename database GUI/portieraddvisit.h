#ifndef PORTIERADDVISIT_H
#define PORTIERADDVISIT_H

#include <QDialog>

namespace Ui {
class PortierAddVisit;
}

class PortierAddVisit : public QDialog
{
    Q_OBJECT

public:
    explicit PortierAddVisit(QWidget *parent = 0);
    ~PortierAddVisit();

private slots:
    void on_return_button_clicked();

    void on_check_assignment_clicked();

    void on_check_aviability_clicked();

    void on_add_visit_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pesel_input_textChanged(const QString &arg1);

private:
    Ui::PortierAddVisit *ui;
    QString current_pesel;
    QString current_class;
    QString current_pesel_save;
    QString current_class_save;
    bool student_checked;
    bool available;
    bool pay;
    bool closed;
    bool closed_save;
};

#endif // PORTIERADDVISIT_H
