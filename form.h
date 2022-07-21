#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

public:
    Ui::Form *ui;

public slots:
    void form_slot(QString str);
    void clear_history();

};

#endif // FORM_H
