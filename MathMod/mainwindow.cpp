#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_AreaWidget(NULL), m_ObservationPointWidget(NULL)
{
    ui->setupUi(this);
    m_ParametersWidget = new ParametrsWidget(ui->widget_4);
    ui->toolBox->setCurrentIndex(0);

    m_System = new System();
    m_PassportObject = new Passport(m_System);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_ParametersWidget;
}


void MainWindow::on_pushButton_pressed()
{
    if (m_AreaWidget != NULL)
        delete m_AreaWidget;

    m_System->setParameters(m_ParametersWidget->parameters());

    m_AreaWidget = new AreaWidget(m_ParametersWidget->parameters(), ui->widget_17);
  //  ui->widgetArea->update();
    ui->toolBox->setCurrentIndex(1);

    m_System->setArea(m_AreaWidget->area());

    rewritePassport();
}

void MainWindow::on_pushButton_2_clicked()
{
    if (m_ObservationPointWidget != NULL)
        delete m_ObservationPointWidget;

    m_System->setArea(m_AreaWidget->area());

    m_ObservationPointWidget = new ObservationPointWidget(m_AreaWidget->area(), ui->widget_6);
    ui->toolBox->setCurrentIndex(3);
    rewritePassport();
}

void MainWindow::on_pushButton_5_pressed()
{
    m_System->setDifferentialOperator(ui->lineEditL->text().toStdString());
    m_System->setProcess(ui->lineEditY->text().toStdString());
    ui->toolBox->setCurrentIndex(2);
    rewritePassport();
}


void MainWindow::on_radioButtonDirectProblem_pressed()
{
    m_System->setProblemType(mathmod::DIRECT_PROBLEM);
    ui->comboBoxControlType->setEnabled(false);
}

void MainWindow::on_radioButtonInverseProblem_pressed()
{
    m_System->setProblemType(mathmod::INVERSE_PROBLEM);
    ui->comboBoxControlType->setEnabled(true);
}

void MainWindow::on_comboBoxControlType_activated(int index)
{
    switch(index)
    {
    case 0:
        m_System->setControlType(mathmod::INITIAL_CONDITIONS);
        break;
    case 1:
        m_System->setControlType(mathmod::BOUNDARY_CONDITIONS);
        break;
    case 2:
         m_System->setControlType(mathmod::BOUNDARY_AND_INITIAL_CONDITIONS);
        break;
    }
}

void MainWindow::rewritePassport()
{
    QString parameters = QString::fromStdString(m_PassportObject->parameters());

    QString procces = "y(";
    procces += parameters;
    procces += ") = ";
    procces += QString::fromStdString(m_PassportObject->process());
    procces += "\n";

    QString difOperator = "L = ";
    difOperator += QString::fromStdString(m_PassportObject->differentialOperator());
    difOperator += "\n";

    QString problemType = "Тип задача: ";
    problemType += QString::fromStdString(m_PassportObject->problemType());
    problemType += "\n";

    QString controlType = "Куруємо: ";
    controlType += QString::fromStdString(m_PassportObject->controlType());
    controlType += "\n";

    QString area = "Область:\n";
    area += QString::fromStdString(m_PassportObject->area());
    area += "\n";

    ui->labelPassport->setText(procces + difOperator + problemType + controlType + area);
}
