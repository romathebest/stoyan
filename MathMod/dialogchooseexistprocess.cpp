#include "dialogchooseexistprocess.h"
#include "ui_dialogchooseexistprocess.h"

#include <QMessageBox>

dialogChooseExistProcess::dialogChooseExistProcess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogChooseExistProcess)
{
    ui->setupUi(this);
}

dialogChooseExistProcess::~dialogChooseExistProcess()
{
    delete ui;
}

void dialogChooseExistProcess::on_buttonSend_pressed()
{
    accept();
    //send text to main window
    if ( !mTaskText.isEmpty())
    {
        emit sendTask(mTaskText);
    }
    else
    {
        QMessageBox::information(0, "УВАГА!!!", "Ви не обрали жодної запропонованої задачі.");
    }
}

void dialogChooseExistProcess::on_comboBoxModel_currentIndexChanged(int index)
{
    if (index == 0)
    {
        mTaskText = QString("Пряма задача:\n\n")
               +QString("L = 1;\n\n y(x) = d2y/dx2 - 4dy/dx + 1\n\nна проміжку xє[0,1]\n\n")
               +QString("Функція u(x) = sin(x)\n\nПроцес стаціонарний\n\n")
               +QString("Крайові умови першого роду: y(0)=1; y(1)=3\n");
        ui->textShowModel->setText(mTaskText);
    }
    else if (index == 1)
    {
        mTaskText = QString("Обернена задача:\n\n")
               +QString("L = 1;\n\n y = d2y/dx2 - 4dy/dx + 1\n\nна проміжку xє[0,1]\n\n")
               +QString("Функція u(x) = sin(x)\n\nПроцес стаціонарний\n\n")
               +QString("Керування крайовими умовами:\n(x,y): (0,1), (0.1, 2), (0.2, 2.5), (0.3, 0.2),\n (0.4, 5), (0.5, 2), (0.6, -0.4), (0.7, -2),\n (0.8, 1), (0.9, 4), (1, -2)");
        ui->textShowModel->setText(mTaskText);
    }
}
