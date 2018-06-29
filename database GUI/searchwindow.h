#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class SearchWindow;
}

class SearchWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SearchWindow(QWidget *parent = 0);
    ~SearchWindow();
    MainWindow *w;

private slots:
    void on_return_button_clicked();

    void on_check_offer_button_clicked();

private:
    Ui::SearchWindow *ui;
};

#endif // SEARCHWINDOW_H
