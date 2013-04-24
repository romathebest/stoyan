#ifndef AREAWIDGET_H
#define AREAWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QScrollBar>
#include <QDoubleSpinBox>
#include <QSize>

#include "Widgets/rangewidget.h"
#include "Matmod/Area.h"
#include "Matmod/Point.h"

using mathmod::Area;
using mathmod::PointStr;


class AreaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AreaWidget(PointStr param, QWidget *parent = 0);
    ~AreaWidget();
    Area area();
signals:
    
public slots:

private:
    PointStr m_Parameters;
    QVector<RangeWidget *> m_RangeWidgets;
};

#endif // AREAWIDGET_H
