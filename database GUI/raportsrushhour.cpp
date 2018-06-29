#include "raportsrushhour.h"
#include "ui_raportsrushhour.h"
#include "mainwindow.h"
#include <QMessageBox>

RaportsRushHour::RaportsRushHour(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RaportsRushHour)
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

    qry.prepare("SELECT DISTINCT Dyscyplina.Nazwa FROM Dyscyplina JOIN Zajęcia ON zajęcia.IdDyscypliny = Dyscyplina.idDyscypliny WHERE zajęcia.Forma_zajęć = 0");
    if(qry.exec())
    {
        QStringList sports;
        QString sport;
        while(qry.next())
        {
            sport = qry.value("Dyscyplina.Nazwa").toString().toUtf8().constData();
            sports << sport;
        }
        ui->sport_box->blockSignals(true);
        ui->sport_box->addItems(sports);
        ui->sport_box->blockSignals(false);
        ui->sport_box->setCurrentIndex(0);
    }
    QStringList months;
    months << "01" << "02" << "03" << "04" << "05" << "06" << "07" << "08" << "09" << "10" << "11" << "12";
    ui->month_box->blockSignals(true);
    ui->month_box->addItems(months);
    ui->month_box->blockSignals(false);
    ui->month_box->setCurrentIndex(9);
}

RaportsRushHour::~RaportsRushHour()
{
    delete ui;
}

void RaportsRushHour::on_show_button_clicked()
{
    QSqlQuery qry;
    qry.prepare("SELECT godziny.Od, godziny.Do, COUNT(godziny.Od) AS Wszyscy, sum(case when u.Czy_opłacone = 1 then 1 else 0 end) Goście, sum(case when u.Czy_opłacone = 0 then 1 else 0 end) Studenci FROM uczestnictwo_w_zajęciach as u JOIN zajęcia as zaj on zaj.Id_Zajęć = u.Id_Zajęć join dyscyplina as d on d.idDyscypliny = zaj.idDyscypliny join godziny where u.Od_godziny <= godziny.Do AND u.Do_godziny >= godziny.Od and year(u.Data) = " + ui->year_box->currentText() + " and month(u.Data) = " + ui->month_box->currentText() + " and d.Nazwa = '" + ui->sport_box->currentText() + "' GROUP BY godziny.Od");
    qry.exec();
    QSqlQuery *qry_ptr = &qry;
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(*qry_ptr);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
