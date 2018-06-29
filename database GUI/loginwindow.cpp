#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "adminmainwindow.h"
#include "portiermainwindow.h"
#include "studentmainwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_return_button_clicked()
{
    this->close();
    w->show();
}

void LoginWindow::on_log_in_button_clicked()
{
    QString Name, Password;
    Name = ui->login_input->text();
    Password = ui->password_input->text();
    if(!w->db.open())
    {
        ui->info_label->setText("Database not open!");
    }
    else
    {
        QSqlQuery qry;
        qry.exec("SELECT * FROM Uczestnik WHERE PESEL = '" + Name + "' and Hasło = '" +Password + "'");
        if(qry.size() > 0)
        {
            qry.next();
            QString name = qry.value("Imię").toString().toUtf8().constData();
            {
                if(name == "admin")
                {
                    ui->info_label->setText("admin");
                    this->close();
                    AdminMainWindow adminpage;
                    adminpage.setModal(true);
                    adminpage.w = this->w;
                    adminpage.exec();
                }
                else if(name == "portier")
                {
                    ui->info_label->setText("portier");
                    this->close();
                    PortierMainWindow portierpage;
                    portierpage.setModal(true);
                    portierpage.w = this->w;
                    portierpage.exec();
                }
                else
                {
                    ui->info_label->setText("student");
                    this->close();
                    StudentMainWindow studentpage;
                    studentpage.setModal(true);
                    studentpage.w = this->w;
                    studentpage.exec();
                }
            }
        }
        else
        {
            ui->info_label->setText("Nie ma takiego użytkownika");
        }
    }
}
