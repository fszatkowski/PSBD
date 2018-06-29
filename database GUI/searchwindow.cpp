#include "searchwindow.h"
#include "ui_searchwindow.h"
#include "QMessageBox"

SearchWindow::SearchWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchWindow)
{
    ui->setupUi(this);

    bool show_error = 0;

    //load data to comboboxes
    QSqlQuery qry;
    qry.prepare("SELECT Nazwa FROM Dyscyplina");
    if(qry.exec())
    {
        QStringList sport_names;
        QString sport_name;
        while(qry.next())
        {
            sport_name = qry.value("Nazwa").toString().toUtf8().constData();
            sport_names << sport_name;
        }
        ui->sport_type->blockSignals(true);
        ui->sport_type->addItems(sport_names);
        ui->sport_type->blockSignals(false);
    }
    else
    {
        show_error = true;
    }

    qry.prepare("SELECT Nazwa FROM Dzień_tygodnia");
    if(qry.exec())
    {
        QStringList day_names;
        QString day_name;
        while(qry.next())
        {
            day_name = qry.value("Nazwa").toString().toUtf8().constData();
            day_names << day_name;
        }
        ui->day_type->blockSignals(true);
        ui->day_type->addItems(day_names);
        ui->day_type->blockSignals(false);
    }
    else
    {
        show_error = true;
    }
    if(show_error)
    {
        QMessageBox msg;
        msg.setText("Baza danych nie jest podłączona");
        msg.exec();
        this->close();
    }
}

SearchWindow::~SearchWindow()
{
    delete ui;
}

void SearchWindow::on_return_button_clicked()
{
    this->close();
    w->show();
}

void SearchWindow::on_check_offer_button_clicked()
{
    QString day = ui->day_type->currentText();
    QString sport = ui->sport_type->currentText();
    QSqlQuery qry;
    qry.prepare("SELECT d.Nazwa AS 'Dyscyplina', dt.Nazwa AS 'Dzień tygodnia', z.Godzina_rozpoczęcia AS 'Od godziny', z.Godzina_zakończenia AS 'Do godziny', l.Ulica, l.Numer_budynku, l.Numer_sali FROM Zajęcia AS z JOIN dyscyplina AS d ON z.idDyscypliny=d.idDyscypliny JOIN dzień_tygodnia AS dt ON z.idDzień_tygodnia=dt.idDnia_tygodnia JOIN lokalizacja AS l ON l.idLokalizacji=z.idLokalizacja  WHERE d.Nazwa = '"+sport+"' AND dt.Nazwa = '"+day+"' ORDER BY Godzina_rozpoczęcia ASC");
    if(qry.exec())
    {
        QSqlQueryModel *model = new QSqlQueryModel;
        QSqlQuery *qry_ptr = &qry;
        model->setQuery(*qry_ptr);
        if(qry.size()>0){
            ui->tableView->setModel(model);
            ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        }
        else
            model->clear();
            ui->tableView->setModel(model);
    }
    else
    {
        QMessageBox msg;
        msg.setText("Error - query incorrect");
        msg.exec();
    }
}
