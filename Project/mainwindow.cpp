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

    QCustomPlot *customPlot = ui->qcpArea;
/*
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    customPlot->addGraph();
    customPlot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
    // generate some points of data (y0 for first, y1 for second graph):
    QVector<double> x(250), y0(250), y1(250);
    for (int i=0; i<250; i+=10)
    {
      x[i] = i;
      y0[i] = exp(-i/150.0)*cos(i/10.0); // exponentially decaying cosine
      y1[i] = exp(-i/150.0);             // exponential envelope
    }
    // configure right and top axis to show ticks but no labels (could've also just called customPlot->setupFullAxesBox):
    customPlot->xAxis2->setVisible(true);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setVisible(true);
    customPlot->yAxis2->setTickLabels(false);
    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
    // pass data points to graphs:
    customPlot->graph(0)->setData(x, y0);
    customPlot->graph(1)->setData(x, y1);
    customPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(1)->setScatterStyle(QCP::ssCircle);
    customPlot->graph(1)->setScatterSize(5);
    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    customPlot->graph(0)->rescaleAxes();
    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
    customPlot->graph(1)->rescaleAxes(true);
    // Note: we could have also just called customPlot->rescaleAxes(); instead
    // make range moveable by mouse interaction (click and drag):
    customPlot->setRangeDrag(Qt::Horizontal | Qt::Vertical);
    customPlot->setRangeZoom(Qt::Horizontal | Qt::Vertical);
    customPlot->setInteraction(QCustomPlot::iSelectPlottables); // allow selection of graphs via mouse click
    */

    QBrush *brush = new QBrush();
    brush->setColor(QColor(255,0,0));
    brush->setStyle(Qt::SolidPattern);


    QCPItemRect *rect = new QCPItemRect(customPlot);
    rect->topLeft->setCoords(0, 2);
    rect->bottomRight->setCoords(4, 0);
    rect->setBrush(*brush);
    customPlot->addItem(rect);
    customPlot->setRangeDrag(Qt::Horizontal | Qt::Vertical);
    customPlot->setRangeZoom(Qt::Horizontal | Qt::Vertical);

    connect(customPlot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(areaCliked(QMouseEvent*)));


      //labelItemAnchors(rect);
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

void MainWindow::areaCliked(QMouseEvent* event)
{

}
