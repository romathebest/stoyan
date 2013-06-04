#ifndef AREAOUTSIDEWIDGET_H
#define AREAOUTSIDEWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QDoubleSpinBox>
#include <QGridLayout>

#include "Widgets/rangewidget.h"
#include "Matmod/Area.h"
#include "Matmod/Point.h"

using mathmod::Area;
using mathmod::PointStr;

class AreaOutsideWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AreaOutsideWidget(PointStr param, QWidget *parent = 0);
    ~AreaOutsideWidget();
    Area area();
signals:
    
public slots:
private:
    PointStr m_Parameters;
    QVector<RangeWidget *> m_RangeWidgets;
};

#endif // AREAOUTSIDEWIDGET_H
