#ifndef PLOTDRAWING_H
#define PLOTDRAWING_H

#include "QVector"
#include "qcustomplot.h"

class PlotDrawing
{
public:
    PlotDrawing(QCustomPlot* aWidget);
    void DrawVectorPoints(const QVector<double>& x, const QVector<double>& y, QString str_x, QString str_y);
    void SetBoundary(double left, double right, double top, double bottom);

private:
    QCustomPlot* m_PlotWidget;
};

#endif // PLOTDRAWING_H
