#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <form.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  enum lastOperation
  {l_operation,
   l_number
  };
    double number1=0;
    char _operation='\0';
    lastOperation flag_oper;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void clear_history();
private slots:
   void didgit_num();
   void didgit_remove();
   void didgit_dot();
   void operation();
   void eq();
   void pm();
   void cls();
   void show_history();
   void close_history();

   void on_buffer_label_clicked();

signals:
   void form_signal(QString str);
private:
    Ui::MainWindow *ui;
    Form *form_history;
    void add_history(QString str);
};
#endif // MAINWINDOW_H
