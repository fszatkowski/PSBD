#include "adminaddtoclasses.h"
#include "ui_adminaddtoclasses.h"
#include "QMessageBox"

AdminAddToClasses::AdminAddToClasses(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminAddToClasses)
{
    ui->setupUi(this);

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
        QMessageBox msg;
        msg.setText("Baza danych nie jest podłączona");
        msg.exec();
        this->close();
    }
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    add_flag = false;
    available_flag = false;
    signed_flag = true;
    c_id = 0;
}

AdminAddToClasses::~AdminAddToClasses()
{
    delete ui;
}

void AdminAddToClasses::on_return_button_clicked()
{
    this->close();
}

void AdminAddToClasses::on_check_if_signed_button_clicked()
{
    QString name = ui->name_lineedit->text();
    QString surname = ui->surname_lineedit->text();
    QString pesel = ui->pesel_lineedit->text();
    QString faculty = ui->fac_lineedit->text();
    QString index = ui->idx_lineedit->text();

    if(pesel.toULongLong()<10000000000 || pesel.toULongLong()>=100000000000)
    {
        QMessageBox msg;
        msg.setText("Nieprawidłowy PESEL!");
        msg.exec();
        return;
    }

    current_pesel = pesel;

    QSqlQuery qry;

    qry.prepare("SELECT * FROM Uczestnik WHERE PESEL = " + pesel);
    qry.exec();
    if(qry.size() == 0)
    {
        QMessageBox msg;
        msg.setText("Student o podanym peselu nie istnieje");
        msg.exec();
        signed_flag = true;
        return;
    }

    qry.prepare("SELECT * FROM Zapisy WHERE Uczestnik_PESEL = '" + pesel + "'");
    if(qry.exec())
    {
        ui->error_label->setText("");
        if(qry.size()>0){
            QMessageBox msg;
            msg.setText("Student jest już zapisany!");
            msg.exec();
            signed_flag = true;
            return;
        }
        else
        {
            QMessageBox msg;
            msg.setText("Student nie jest nigdzie zapisany!");
            msg.exec();
            signed_flag = false;
        }
    }
}

void AdminAddToClasses::on_check_if_available_button_clicked()
{
    if(available_flag)
    {
        QMessageBox msg;
        msg.setText("Miejsca dostępne");
        msg.exec();
        add_flag = true;
        available_flag = false;
    }
    else
    {
        QMessageBox msg;
        msg.setText("Brak miejsc na zajęciach");
        msg.exec();
        add_flag = false;
    }
}

void AdminAddToClasses::on_sign_student_button_clicked()
{
    if(add_flag)
    {
        QSqlQuery qry;
        QString c = QString::number(c_id);

        qry.prepare("INSERT INTO Zapisy VALUES(0," + current_pesel +","+ c +", 0, 2018, 0)");
        if(qry.exec())
        {
            QMessageBox msg;
            msg.setText("Zapis dokonany");
            msg.exec();
        }
        else
        {
            QMessageBox msg;
            msg.setText("Błąd zapisu");
            msg.exec();
        }
        add_flag = false;
    }
    else
    {
        QMessageBox msg;
        msg.setText("Zapis niemożliwy");
        msg.exec();
    }
}

void AdminAddToClasses::on_sport_type_currentTextChanged(const QString &arg1)
{
    if(signed_flag)
    {
        QMessageBox msg;
        msg.setText("Przegląd dyscyplin niemożliwy - sprawdź, czy student nie jest już zapisany");
        msg.exec();
        return;
    }
    else
    {
        QSqlQuery qry;
        QString sport = ui->sport_type->currentText();
        qry.prepare("SELECT d.Nazwa AS 'Dyscyplina', dt.Nazwa AS 'Dzień tygodnia', z.Godzina_rozpoczęcia AS 'Od godziny', z.Godzina_zakończenia AS 'Do godziny', l.Ulica, l.Numer_budynku, l.Numer_sali FROM Zajęcia AS z JOIN dyscyplina AS d ON z.idDyscypliny=d.idDyscypliny JOIN dzień_tygodnia AS dt ON z.idDzień_tygodnia=dt.idDnia_tygodnia JOIN lokalizacja AS l ON l.idLokalizacji=z.idLokalizacja  WHERE d.Nazwa = '"+sport+"'");
        if(qry.exec())
        {
            ui->error_label2->setText("");
            QSqlQueryModel *model = new QSqlQueryModel;
            QSqlQuery *qry_ptr = &qry;
            model->setQuery(*qry_ptr);
            if(qry.size()>0){
                ui->tableView->setModel(model);
                ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            }
            else
            {
                model->clear();
                ui->tableView->setModel(model);
                QMessageBox msg;
                msg.setText("Brak ofert z wybranej dyscypliny");
                msg.exec();
            }
        }
        else
        {
            ui->error_label2->setText("Error - query incorrect");
        }
    }
}

void AdminAddToClasses::on_tableView_clicked(const QModelIndex &index)
{
    int row = index.row();

    QString sport = index.sibling(row, 0).data().toString();
    QString time_from = index.sibling(row, 2).data().toString();
    QString time_to = index.sibling(row, 3).data().toString();
    QString day = index.sibling(row, 1).data().toString();
    QString street = index.sibling(row, 4).data().toString();
    QString street_number = index.sibling(row, 5).data().toString();
    QString room_number = index.sibling(row, 6).data().toString();

    QSqlQuery qry;
    qry.prepare("SELECT idDnia_tygodnia FROM Dzień_tygodnia WHERE Nazwa = '" + day + "'");
    qry.exec();
    qry.first();
    QString day_id = qry.value("idDnia_tygodnia").toString().toUtf8().constData();

    qry.prepare("SELECT idLokalizacji, Limit_miejsc FROM Lokalizacja WHERE Ulica = '" + street + "' AND Numer_budynku = " + street_number + " AND Numer_sali =" + room_number);
    qry.exec();
    qry.first();
    QString loc_id = qry.value("idLokalizacji").toString().toUtf8().constData();
    int limit = qry.value("Limit_miejsc").toInt();

    qry.prepare("SELECT idDyscypliny FROM Dyscyplina WHERE Nazwa = '" + sport + "'");
    qry.exec();
    qry.first();
    QString sport_id = qry.value("idDyscypliny").toString().toUtf8().constData();

    qry.prepare("SELECT Id_Zajęć FROM Zajęcia WHERE idDyscypliny = " + sport_id + " AND idDzień_tygodnia = " + day_id + " AND idLokalizacja = " + loc_id + " AND Godzina_rozpoczęcia = '" + time_from + "' AND Godzina_zakończenia = '" + time_to + "'");
    qry.exec();
    qry.first();
    QString classes_id = qry.value(0).toString().toUtf8().constData();
    c_id = classes_id.toInt();

    qry.prepare("SELECT COUNT(Uczestnik_PESEL) FROM zapisy WHERE Id_Zajęć = " + classes_id);
    qry.exec();
    qry.first();
    int count = qry.value(0).toInt();

    if(count < limit)
    {
        available_flag = true;
    }
    else
    {
        available_flag = false;
    }
}
