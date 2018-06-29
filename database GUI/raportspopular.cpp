#include "raportspopular.h"
#include "ui_raportspopular.h"
#include "mainwindow.h"
#include <QMessageBox>

RaportsPopular::RaportsPopular(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RaportsPopular)
{
    ui->setupUi(this);

    QSqlQuery qry;
    qry.prepare("SELECT DISTINCT Rok_akademicki FROM Zapisy");
    if(qry.exec())
    {
        QStringList years;
        QString year;
        while(qry.next())
        {
            year = qry.value("Rok_akademicki").toString().toUtf8().constData();
            years << year;
        }
        ui->year_box->blockSignals(true);
        ui->year_box->addItems(years);
        ui->year_box->blockSignals(false);
        ui->year_box->setCurrentIndex(0);
    }
    QStringList oc;
    oc << "Wszystkie" << "Otwarte" << "Zamknięte";
    ui->type_box->blockSignals(true);
    ui->type_box->addItems(oc);
    ui->type_box->blockSignals(false);
    ui->type_box->setCurrentIndex(0);
}

RaportsPopular::~RaportsPopular()
{
    delete ui;
}

void RaportsPopular::on_show_button_clicked()
{
    QString qry_end;
    if(ui->type_box->currentIndex() == 0)
    {
        qry_end = "";
    }
    else if(ui->type_box->currentIndex() == 1)
    {
        qry_end = " and zaj.Forma_Zajęć = 0";
    }
    else
    {
        qry_end = "and zaj.Forma_Zajęć = 1";
    }

    QSqlQuery qry;
    QSqlQueryModel *model = new QSqlQueryModel;

    qry.prepare("SELECT d.Nazwa, zaj.Forma_zajęć, COUNT(d.nazwa) AS 'Liczba zapisanych', count(d.Nazwa)/(select COUNT(*) FROM zapisy where zapisy.Rok_akademicki = " + ui->year_box->currentText() + ")*100 AS 'Procent wszystkich zapisów' FROM zajęcia as zaj join dyscyplina as d on zaj.idDyscypliny = d.idDyscypliny join zapisy as zap on zaj.Id_Zajęć = zap.Id_Zajęć where zap.Rok_akademicki = " + ui->year_box->currentText() + qry_end + " group by d.Nazwa");
    if(qry.exec())
    {
        if(qry.size() == 0)
        {
            QMessageBox msg;
            msg.setText("Brak zajęć o wybranych parametrach");
            msg.exec();
            model->clear();
            ui->tableView->setModel(model);
            return;
        }
    }
    else
    {
        QMessageBox msg;
        msg.setText("Query error");
        msg.exec();
        return;
    }
    QSqlQuery *qry_ptr = &qry;
    model->setQuery(*qry_ptr);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}
