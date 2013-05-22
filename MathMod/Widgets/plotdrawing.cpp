#include "plotdrawing.h"

PlotDrawing::PlotDrawing(QCustomPlot *aWidget):
    m_PlotWidget(aWidget)
{
    m_PlotWidget->setRangeDrag(Qt::Horizontal | Qt::Vertical);
    m_PlotWidget->setRangeZoom(Qt::Horizontal | Qt::Vertical);
}

void PlotDrawing::DrawVectorPoints(const QVector<double>& x, const QVector<double>& y, QString str_x, QString str_y)
{
    m_PlotWidget->addGraph();
    m_PlotWidget->graph(0)->setData(x, y);

    m_PlotWidget->xAxis->setLabel(str_x);
    m_PlotWidget->yAxis->setLabel(str_y);
}

void PlotDrawing::SetBoundary(double left, double right, double top, double bottom)
{
    m_PlotWidget->xAxis->setRange(left, right);
    m_PlotWidget->yAxis->setRange(bottom, top);
    m_PlotWidget->replot();
}
