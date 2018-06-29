#include "portieraddvisit.h"
#include "ui_portieraddvisit.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QTime>

PortierAddVisit::PortierAddVisit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PortierAddVisit)
{
    ui->setupUi(this);

    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->date->setDate(QDate::currentDate());



    QSqlQuery qry;
    qry.prepare("SELECT Zajęcia.Id_Zajęć AS Nr, Dyscyplina.Nazwa AS 'Typ zajęć', Zajęcia.Godzina_rozpoczęcia AS Od, Zajęcia.Godzina_zakończenia AS Do, Forma_Zajęć AS Zamknięte, Dzień_tygodnia.Nazwa AS Dzień FROM (Zajęcia JOIN Dyscyplina ON Zajęcia.IdDyscypliny = Dyscyplina.IdDyscypliny) JOIN Dzień_tygodnia ON Dzień_tygodnia.idDnia_tygodnia = Zajęcia.idDzień_tygodnia ORDER BY Dzień_tygodnia.idDnia_tygodnia ASC, Od ASC");
    QSqlQueryModel *model = new QSqlQueryModel;
    if(qry.exec())
    {
        QSqlQuery *qry_ptr = &qry;
        model->setQuery(*qry_ptr);
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView->setColumnHidden(0, true);
        ui->tableView->selectRow(0);
    }
    else
    {
        QMessageBox msg;
        msg.setText("Baza danych niepołączona.");
        msg.exec();
        this->close();
    }

    student_checked = false;
    available = false;
    pay = false;
    current_class = "1";
    closed = 1;
}

PortierAddVisit::~PortierAddVisit()
{
    delete ui;
}

void PortierAddVisit::on_return_button_clicked()
{
    this->close();
}

void PortierAddVisit::on_check_assignment_clicked()
{
    current_pesel = ui->pesel_input->text();
    if(current_pesel.toULongLong()<10000000000 || current_pesel.toULongLong()>=100000000000)
    {
        QMessageBox msg;
        msg.setText("Nieprawidłowy PESEL!");
        msg.exec();
        return;
    }

    current_class_save = current_class;
    closed_save = closed;

    QDate d = ui->date->date().currentDate();
    QString current_year = d.toString("yyyy");

    QSqlQuery qry;

    if(ui->student_button->isChecked())
    {
        qry.prepare("SELECT * FROM Student WHERE PESEL = " + current_pesel);
        qry.exec();
        if(qry.size() == 0)
        {
            QMessageBox msg;
            msg.setText("Studenta o podanym PESELu nie ma w bazie danych");
            msg.exec();
            return;
        }
        else
        {
            qry.prepare("SELECT * FROM Zapisy WHERE Uczestnik_PESEL = " + current_pesel + " AND Rok_akademicki = " + current_year + " AND Id_Zajęć = " + current_class_save);
            qry.exec();
            if(qry.size() == 0)
            {
                QMessageBox msg;
                msg.setText("Student nie jest zapisany na wybrane zajęcia. Ewentualny zapis wymaga sprawdzenia dostępności zajęć.");
                msg.exec();
                current_pesel_save = current_pesel;
                pay = true;
                student_checked = true;
                return;
            }
            else
            {
                QMessageBox msg;
                msg.setText("Student jest zapisany na zajęcia");
                msg.exec();
                current_pesel_save = current_pesel;
                pay = false;
                student_checked = true;
                return;
            }
        }
    }
    else if(ui->guest_button->isChecked())
    {
         QMessageBox msg;
         msg.setText("Sprawdzanie PESELu dla gościa nie ma sensu");
         msg.exec();
         return;
    }
}

void PortierAddVisit::on_check_aviability_clicked()
{
    QSqlQuery qry;
    qry.prepare("SELECT Lokalizacja.Limit_miejsc FROM Zajęcia JOIN Lokalizacja ON Zajęcia.idLokalizacja=Lokalizacja.idLokalizacji WHERE Zajęcia.Id_Zajęć = " + current_class_save);
    qry.exec();
    qry.first();
    int limit = qry.value(0).toInt();

    qry.prepare("SELECT COUNT(IdZapisu) FROM Zajęcia JOIN Zapisy ON Zapisy.Id_Zajęć = Zajęcia.Id_Zajęć WHERE Zapisy.Id_Zajęć = " + current_class_save);
    qry.exec();
    qry.first();
    int students = qry.value(0).toInt();

    qry.prepare("SELECT COUNT(Uczestnik_PESEL) FROM Zajęcia WHERE Do_godziny IS NULL AND Czy_opłacone = 1 AND Id_Zajęć = " + current_class_save);
    qry.exec();
    qry.first();
    int visitors = qry.value(0).toInt();

    //tutaj zakładam, że studenci mają zagwarantowane swoje miejsce na zajęciach

    if(students + visitors < limit)
    {
        QMessageBox msg;
        msg.setText("Na zajęciach są wolne miejsca");
        msg.exec();
        available = true;
        return;
    }
    else
    {
        QMessageBox msg;
        msg.setText("Na zajęciach nie ma wolnych miejsc");
        msg.exec();
        available = false;
        return;
    }
}

void PortierAddVisit::on_add_visit_clicked()
{
    if(ui->student_button->isChecked())
    {
        //nie pozwol na zapis, jesli student nie jest sprawdzony
        if(!student_checked)
        {
            QMessageBox msg;
            msg.setText("Sprawdź, czy podany student jest zapisany na zajęcia");
            msg.exec();
            return;
        }
        //nie pozwol na zapis, jesli nie ma wolnych miejsc oraz student chce wejść bez zapisu
        if(!available && closed_save)
        {
            QMessageBox msg;
            msg.setText("Brak miejsc na zajęciach dla niezapisanego studenta");
            msg.exec();
            return;
        }
    }

    else if(ui->guest_button->isChecked())
    {
        current_pesel = ui->pesel_input->text();

        if(current_pesel.toULongLong()<10000000000 || current_pesel.toULongLong()>=100000000000)
        {
            QMessageBox msg;
            msg.setText("Nieprawidłowy PESEL!");
            msg.exec();
            return;
        }

        QSqlQuery qry;
        qry.prepare("SELECT * FROM Student WHERE PESEL = " + current_pesel);
        qry.exec();
        if(qry.size() != 0)
        {
            QMessageBox msg;
            msg.setText("Podany PESEL należy do studenta");
            msg.exec();
            return;
        }

        if(!available)
        {
            QMessageBox msg;
            msg.setText("Brak miejsc na zajęciach");
            msg.exec();
            return;
        }
        qry.prepare("INSERT INTO Gość VALUES (" + current_pesel + ")");
        qry.exec();
        pay = true;
    }

    QString paid;
    if(pay)
    {
        paid = "1";
    }
    else
    {
        paid = "0";
    }

    QString from = QTime::currentTime().toString();
    QDate d = ui->date->date().currentDate();
    QString current_date = d.toString("yyyy-MM-dd");

    QSqlQuery qry;
    qry.prepare("INSERT INTO Uczestnictwo_w_zajęciach VALUES(0," + current_pesel_save + "," + current_class_save + ",'" + from + "',NULL,'" + current_date + "'," + paid + ",0)");
    if(qry.exec())
    {
        QMessageBox msg;
        msg.setText("Zapis udany!");
        msg.exec();
        available = false;
        student_checked = false;
        pay = false;
    }
    else
    {
        QMessageBox msg;
        msg.setText("Błąd podczas zapisu!");
        msg.exec();
    }
}

void PortierAddVisit::on_tableView_clicked(const QModelIndex &index)
{
    int row = index.row();
    current_class = index.sibling(row, 0).data().toString();
    closed = index.sibling(row, 4).data().toInt();
}

void PortierAddVisit::on_pesel_input_textChanged(const QString &arg1)
{
    student_checked = false;
}
