#ifndef DIALOGCHOOSEEXISTPROCESS_H
#define DIALOGCHOOSEEXISTPROCESS_H

#include <QDialog>

namespace Ui {
class dialogChooseExistProcess;
}

class dialogChooseExistProcess : public QDialog
{
    Q_OBJECT
    
public:
    explicit dialogChooseExistProcess(QWidget *parent = 0);
    ~dialogChooseExistProcess();
    
signals:
    void sendTask(QString);

private slots:
    void on_buttonSend_pressed();

    void on_comboBoxModel_currentIndexChanged(int index);

private:
    QString mTaskText;
    Ui::dialogChooseExistProcess *ui;
};

#endif // DIALOGCHOOSEEXISTPROCESS_H
