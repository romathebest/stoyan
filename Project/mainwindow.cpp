#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    isInitialize(false),
    dialogProcess(NULL),
    dialogGetModel(NULL),
    analizator(NULL)
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
    delete dialogGetModel;
}

void MainWindow::on_actionQuit_triggered()
{
    qApp->exit();
}

void MainWindow::on_action_triggered()
{
    analizator->clearAllFields();
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

void MainWindow::on_actionExistModel_triggered()
{
    analizator->clearAllFields();
    dialogGetModel = new dialogChooseExistProcess();

    bool cond;
    cond = connect(dialogGetModel,SIGNAL(sendTask(QString)),
                   analizator,SLOT(setProcessParameters(QString)));

    Q_ASSERT(cond);

    if( dialogGetModel->exec() == QDialog::Accepted )
    {
        isInitialize = true;
        WriteTextField();
    }
    else return;
}

void MainWindow::on_pushButton_clicked()
{
    static bool isBig = false;

    QPropertyAnimation* animation = new QPropertyAnimation(ui->widget_3, "geometry");
    animation->setDuration(500);

    if ( !isBig)
    {
        startPosition = ui->widget_3->geometry();
        //ui->widget_3->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        ui->dataInfo->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        ui->dataInfo->resize(900,900);
        animation->setStartValue(startPosition);
        animation->setEndValue(QRect(0, 0, ui->centralWidget->size().width(), ui->centralWidget->size().height()));

    }
    else
    {
        animation->setStartValue(QRect(0, 0, ui->centralWidget->size().width(), ui->centralWidget->size().height()));
        animation->setEndValue(startPosition);
    }
    animation->start();
    isBig = !isBig;
}

void MainWindow::on_actionGrin_triggered()
{
    // TODO
}
