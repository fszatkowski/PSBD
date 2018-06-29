#include "raportspasses.h"
#include "ui_raportspasses.h"
#include "mainwindow.h"
#include <QMessageBox>

RaportsPasses::RaportsPasses(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RaportsPasses)
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

RaportsPasses::~RaportsPasses()
{
    delete ui;
}

void RaportsPasses::on_search_button_clicked()
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
        qry_end = " and zaj.Forma_Zajęć = 1";
    }

    QSqlQuery qry;
    QSqlQueryModel *model = new QSqlQueryModel;

    qry.prepare("select q1.dyscyplina AS 'Dyscyplina', sum(q2.lz) AS 'Liczba zapisanych', sum(q1.lzal) AS 'Liczba zaliczeń', sum(q1.lzpo) AS 'Liczba zaliczeń z pełną obecnością' FROM (select zaj.id_zajęć as i, d.Nazwa as 'Dyscyplina', sum(case when zap.Czy_zaliczenie = 1 then 1 else 0 end) 'Lzal', sum(case when zap.Liczba_obecności = q.lpo then 1 else 0 end)`Lzpo` froM dyscyplina AS D JOIN zajęcia AS ZAJ ON D.idDyscypliny = ZAJ.idDyscypliny join zapisy as zap on zap.id_zajęć = zaj.id_zajęć join (SELECT zaj.Id_Zajęć as idz, dyscyplina.Nazwa, COUNT(p.date) as lpo FROM przeprowadzenie_zajęć as p join zajęcia as zaj on zaj.Id_Zajęć = p.Id_Zajęć join dyscyplina on zaj.idDyscypliny = dyscyplina.idDyscypliny group by zaj.Id_Zajęć) as q on q.idz = zaj.Id_Zajęć where zap.rok_akademicki = " + ui->year_box->currentText() + qry_end + " and zap.czy_zaliczenie = 1 group by zaj.Id_zajęć) AS q1 JOIN (SELECT zaj.id_zajęć AS i, d.Nazwa AS 'Dyscyplina', COUNT(d.nazwa) AS 'Lz' FROM zajęcia as zaj join dyscyplina as d on zaj.idDyscypliny = d.idDyscypliny join zapisy as zap on zaj.Id_Zajęć = zap.Id_Zajęć where zap.Rok_akademicki = " + ui->year_box->currentText() + qry_end + " group by zaj.id_zajęć) as q2 on q1.i = q2.i group by Dyscyplina");
    if(qry.exec())
    {
        if(qry.size() == 0)
        {
            QMessageBox msg;
            msg.setText("Brak wyników o wybranych parametrach");
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
