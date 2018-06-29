#ifndef RAPORTSPOPULAR_H
#define RAPORTSPOPULAR_H

#include <QDialog>

namespace Ui {
class RaportsPopular;
}

class RaportsPopular : public QDialog
{
    Q_OBJECT

public:
    explicit RaportsPopular(QWidget *parent = 0);
    ~RaportsPopular();

private slots:
    void on_show_button_clicked();

private:
    Ui::RaportsPopular *ui;
};

#endif // RAPORTSPOPULAR_H
