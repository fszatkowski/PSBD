#ifndef RAPORTSPASSES_H
#define RAPORTSPASSES_H

#include <QDialog>

namespace Ui {
class RaportsPasses;
}

class RaportsPasses : public QDialog
{
    Q_OBJECT

public:
    explicit RaportsPasses(QWidget *parent = 0);
    ~RaportsPasses();

private slots:
    void on_search_button_clicked();

private:
    Ui::RaportsPasses *ui;
};

#endif // RAPORTSPASSES_H
