#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"
#include "searchwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("wf");

    if(!db.open())
    {
        ui->status_label->setText("Brak połączenia z bazą danych");
    }
    else
    {
        ui->status_label->setText("Baza danych połączona");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_log_in_button_clicked()
{
    this->hide();
    LoginWindow login;
    login.setModal(true);
    login.w = this;
    login.exec();
}

void MainWindow::on_przegladanie_button_clicked()
{
    this->hide();
    SearchWindow search;
    search.setModal(true);
    search.w = this;
    search.exec();
}

void MainWindow::on_connect_button_clicked()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("wf");

    if(!db.open())
    {
        ui->status_label->setText("Brak połączenia z bazą danych");
    }
    else
    {
        ui->status_label->setText("Baza danych połączona");
    }
}
