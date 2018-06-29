#ifndef RAPORTSRUSHHOUR_H
#define RAPORTSRUSHHOUR_H

#include <QDialog>

namespace Ui {
class RaportsRushHour;
}

class RaportsRushHour : public QDialog
{
    Q_OBJECT

public:
    explicit RaportsRushHour(QWidget *parent = 0);
    ~RaportsRushHour();

private slots:
    void on_show_button_clicked();

private:
    Ui::RaportsRushHour *ui;
    QString class_id;
};

#endif // RAPORTSRUSHHOUR_H
