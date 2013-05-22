#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_AreaWidget(NULL),
    m_ObservationPointWidget(NULL),
    m_DialogGetProcess(NULL),
    m_WolframObject(NULL)
{
    ui->setupUi(this);

    m_PlotDrawing = new PlotDrawing(ui->ResultGraphic);

    m_ParametersWidget = new ParametrsWidget(ui->widget_4);
    ui->toolBox->setCurrentIndex(0);

    m_System = new System();
    m_PassportObject = new Passport(m_System);

    ui->widget_2->setVisible(false);
    ui->ResultGraphic->setVisible(false);
    DisableProcessInput();

    m_WolframObject = new WolframConnector(m_System);

    ui->pushButtonSolve->setEnabled(false);
}

void MainWindow::DisableProcessInput()
{
    ui->widget_GrinInput->setEnabled(false);
    ui->widget_10->setEnabled(false);
    ui->widget_11->setEnabled(false);
    ui->widget_12->setEnabled(false);
    ui->widget_15->setEnabled(false);
}

MainWindow::~MainWindow()
{
    m_WolframObject->close();
    delete m_WolframObject;

    delete m_PlotDrawing;
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

    QString controlType = "Керуємо: ";
    controlType += QString::fromStdString(m_PassportObject->controlType());
    controlType += "\n";

    QString area = "Область:\n";
    area += QString::fromStdString(m_PassportObject->area());
    area += "\n";

    ui->labelPassport->setText(procces + difOperator + problemType + controlType + area);
}

void MainWindow::writePassportFromExistTask(QString text)
{
    ui->labelPassport->setText(text);
}


void MainWindow::on_pushButton_6_pressed()
{
    DisableProcessInput();
    ui->widget_10->setEnabled(true);
    ui->widget_11->setEnabled(true);
    ui->widget_12->setEnabled(true);
    ui->widget_15->setEnabled(true);
}

void MainWindow::on_pushButton_7_pressed()
{
    DisableProcessInput();
    m_DialogGetProcess = new dialogChooseExistProcess();

    bool cond;
    cond = connect(m_DialogGetProcess,SIGNAL(sendTask(QString)),
                   this,SLOT(writePassportFromExistTask(QString)));

    Q_ASSERT(cond);

    if( m_DialogGetProcess->exec() == QDialog::Accepted )
    {
        ui->widget_2->setVisible(true);
    }
    else return;

}

void MainWindow::on_pushButton_8_pressed()
{
    DisableProcessInput();

    ui->widget_GrinInput->setEnabled(true);
    ui->widget_15->setEnabled(true);
}

void MainWindow::on_pushButton_9_pressed()
{
    ui->toolBox->setCurrentIndex(4);
}

void MainWindow::on_radioButtonInverseProblem_2_pressed()
{
    ui->widget_23->setEnabled(false);
}

void MainWindow::on_radioButtonDirectProblem_2_pressed()
{
    ui->widget_23->setEnabled(true);
}

void MainWindow::on_pushButtonConnectWithWolfram_clicked()
{
    if(m_WolframObject->open())
    {
        ui->labelWolframStatus->setText("З'єднання встановлено.");
        ui->pushButtonSolve->setEnabled(true);
    }
    else
    {
        ui->labelWolframStatus->setText("Не вдалося встановити з'єднання");
    }
}

void MainWindow::on_pushButtonSolve_clicked()
{
    if (m_WolframObject->isOpen())
    {
        //пішла жара

        QVector<double> x(1001), y(1001); // initialize with entries 0..100
        for (int i=0; i<1001; ++i)
        {
          x[i] = i/50.0 - 10; // x goes from -10 to 10
          y[i] = cos(x[i]); // let's plot a quadratic function
        }

        m_PlotDrawing->SetBoundary(-10, 10, 10, -10);
        m_PlotDrawing->DrawVectorPoints(x, y, "x", "t");
    }

    ui->ResultGraphic->setVisible(true);
}

void MainWindow::on_pushButtonBuildPassport_clicked()
{
    ui->widget_2->setVisible(true);
}
