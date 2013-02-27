#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    isInitialize(false)
{
    analizator = new Analizator();
    ui->setupUi(this);

    ui->dataInfo->setText("ЗАДАЧА НЕ ЗАДАНА!");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dialogProcess;
    delete analizator;
}

void MainWindow::on_actionQuit_triggered()
{
    qApp->exit();
}

void MainWindow::on_action_triggered()
{
    dialogProcess = new ProcessDialog();

    bool cond;
    cond = connect(dialogProcess,SIGNAL(sendProcess(QString, QString, QString)),
                   analizator,SLOT(setProcessParameters(QString, QString, QString)));

    Q_ASSERT(cond);

    if( dialogProcess->exec() == QDialog::Accepted )
    {
        isInitialize = true;
        WriteTextField();
    }
    else return;
}

void MainWindow::WriteTextField()
{
    ui->dataInfo->setText(analizator->getTextField());
}
