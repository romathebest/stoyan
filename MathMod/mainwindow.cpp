#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_AreaWidget(NULL), m_ObservationPointWidget(NULL)
{
    ui->setupUi(this);
    m_ParametersWidget = new ParametrsWidget(ui->widget_3);
    ui->toolBox->setCurrentIndex(0);
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

    m_AreaWidget = new AreaWidget(m_ParametersWidget->parameters(), ui->widget_5);
    ui->widgetArea->update();
    ui->toolBox->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    if (m_ObservationPointWidget != NULL)
        delete m_ObservationPointWidget;

    m_ObservationPointWidget = new ObservationPointWidget(m_AreaWidget->area(), ui->widget_6);
    ui->toolBox->setCurrentIndex(3);
}

void MainWindow::on_radioButton_2_pressed()
{
    ui->comboBox->setEnabled(true);
}

void MainWindow::on_radioButton_pressed()
{
    ui->comboBox->setEnabled(false);
}

void MainWindow::on_pushButton_5_pressed()
{
    ui->toolBox->setCurrentIndex(2);
}
