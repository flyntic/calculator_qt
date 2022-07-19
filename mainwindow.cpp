#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    form_history =new Form();
    form_history->setGeometry(this->geometry().x()+1220,this->geometry().y()+268,form_history->geometry().width(),form_history->geometry().height());

    ui->buffer_label->setAlignment(Qt::AlignmentFlag::AlignRight);

    connect(ui->pushButton__0,&QPushButton::clicked,this,&MainWindow::didgit_num);
    connect(ui->pushButton__1,&QPushButton::clicked,this,&MainWindow::didgit_num);
    connect(ui->pushButton__2,&QPushButton::clicked,this,&MainWindow::didgit_num);
    connect(ui->pushButton__3,&QPushButton::clicked,this,&MainWindow::didgit_num);
    connect(ui->pushButton__4,&QPushButton::clicked,this,&MainWindow::didgit_num);
    connect(ui->pushButton__5,&QPushButton::clicked,this,&MainWindow::didgit_num);
    connect(ui->pushButton__6,&QPushButton::clicked,this,&MainWindow::didgit_num);
    connect(ui->pushButton__7,&QPushButton::clicked,this,&MainWindow::didgit_num);
    connect(ui->pushButton__8,&QPushButton::clicked,this,&MainWindow::didgit_num);
    connect(ui->pushButton__9,&QPushButton::clicked,this,&MainWindow::didgit_num);

    connect(ui->pushButton__dot,&QPushButton::clicked,this,&MainWindow::didgit_dot);
    connect(ui->pushButton__ac,&QPushButton::clicked,this,&MainWindow::didgit_remove);


    connect(ui->pushButton__plus, &QPushButton::clicked,this,&MainWindow::operation);
    connect(ui->pushButton__minus,&QPushButton::clicked,this,&MainWindow::operation);
    connect(ui->pushButton__dis,  &QPushButton::clicked,this,&MainWindow::operation);
    connect(ui->pushButton__multy,&QPushButton::clicked,this,&MainWindow::operation);

    connect(ui->pushButton__eq,&QPushButton::clicked,this,&MainWindow::eq);

  //  connect(ui->result_show, ,this,&MainWindow::show_history);

    connect(this,&MainWindow::form_signal,form_history,&Form::form_slot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::didgit_num()
{


   if (ui->result_show->text() == "0") ui->result_show->setText("");
   ui->result_show->setText(ui->result_show->text() + qobject_cast<QPushButton*>(sender())->text());
}

void MainWindow::didgit_remove()
{

    ui->result_show->setText("0");

}

void MainWindow::didgit_dot()
{
    if(!(ui->result_show->text().contains('.')))
        ui->result_show->setText(ui->result_show->text() + '.');

}

void MainWindow::operation()
{
    if (_operation != '\0')
    {
        ui->buffer_label->setText(QString::number(number1) + _operation + ui->result_show->text());
        switch (_operation) {
        case '+':
        {
            number1 += ui->result_show->text().toDouble();
            break;
        }
        case '-':
        {
            number1 -= ui->result_show->text().toDouble();
            break;
        }
        case 'x':
        {
            number1 *= ui->result_show->text().toDouble();
            break;
        }
        case '/':
        {
            number1 /= ui->result_show->text().toDouble();
            break;
        }
        }
        ui->buffer_label->setText(ui->buffer_label->text() + "=" + QString::number(number1));
        emit form_signal(ui->buffer_label->text());
    }else
    {
        ui->buffer_label->setText(ui->result_show->text()+qobject_cast<QPushButton*>(sender())->text()[0].toLatin1());
        emit form_signal(ui->buffer_label->text());
        number1 = ui->result_show->text().toDouble();
    }
    _operation=qobject_cast<QPushButton*>(sender())->text()[0].toLatin1();
    ui->result_show->setText("0");
}

void MainWindow::eq()
{
    if (_operation != '\0')
    {
        ui->buffer_label->setText(QString::number(number1) + _operation + ui->result_show->text());
        switch (_operation) {
        case '+':
        {
            number1 += ui->result_show->text().toDouble();
            break;
        }
        case '-':
        {
            number1 -= ui->result_show->text().toDouble();
            break;
        }
        case 'x':
        {
            number1 *= ui->result_show->text().toDouble();
            break;
        }
        case '/':
        {

            if (ui->result_show->text().toDouble()==0)  QMessageBox::about(this,"А-яй","Нельзя делить на ноль");
            else
            number1 /= ui->result_show->text().toDouble();
            break;
        }
        }
        ui->result_show->setText( QString::number(number1));
    }

}

void MainWindow::show_history()
{
    form_history->show();
}

void MainWindow::close_history()
{
    form_history->close();
}

void MainWindow::add_history(QString str)
{

   //form_history->ui-> ->ui ui->listView->Add(str);
}






