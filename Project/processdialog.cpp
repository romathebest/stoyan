#include "processdialog.h"

ProcessDialog::ProcessDialog(QDialog *parent) :
    QDialog(parent), dialogForm(new Ui::Dialog)
{
    dialogForm->setupUi(this);
}

ProcessDialog::~ProcessDialog()
{
    delete dialogForm;
}

void ProcessDialog::on_doneButton_clicked()
{
    emit sendProcess(dialogForm->processEdit->text(), dialogForm->grinEdit->text(), dialogForm->controlEdit->text());

    accept();
}
