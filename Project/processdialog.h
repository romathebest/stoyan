#ifndef PROCESSDIALOG_H
#define PROCESSDIALOG_H

#include <QDialog>

#include "ui_chooseProcess.h"

class ProcessDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ProcessDialog(QDialog *parent = 0);
    
signals:
    void sendProcess(QString, QString, QString);

private slots:
    void on_doneButton_clicked();

private:
    Ui::Dialog * dialogForm;
};

#endif // PROCESSDIALOG_H
