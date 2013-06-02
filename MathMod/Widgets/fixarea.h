#ifndef FIXAREA_H
#define FIXAREA_H

#include <QWidget>
#include <QTableWidget>
#include <QDoubleSpinBox>
#include <QGridLayout>

#include "Widgets/fixwidget.h"
#include "Matmod/Point.h"
#include "Matmod/Area.h"


using mathmod::PointStr;
using mathmod::Area;

class FixArea : public QWidget
{
    Q_OBJECT
public:
    explicit FixArea(PointStr param, QWidget *parent = 0);
    ~FixArea();
    QString sequence();
    void setArea(Area area);
signals:

public slots:
    bool isOneParametersUnckeded();
private:
    PointStr m_Parameters;
    QVector<FixWidget *> m_FixWidgets;
};

#endif // FIXAREA_H
