#ifndef FIXAREA_H
#define FIXAREA_H

#include <QWidget>
#include <QTableWidget>
#include <QDoubleSpinBox>
#include <QGridLayout>

#include <vector>

#include "Widgets/fixwidget.h"
#include "Matmod/Point.h"
#include "Matmod/Area.h"
#include "Matmod/mathmod.h"


using mathmod::PointStr;
using mathmod::Area;
using mathmod::FixedStruct;
using std::vector;

class FixArea : public QWidget
{
    Q_OBJECT
public:
    explicit FixArea(PointStr param, QWidget *parent = 0);
    ~FixArea();
    QString sequence();
    void setArea(Area area);
    vector<FixedStruct> fixedparameters();
signals:

public slots:
    bool isOneParametersUnckeded();

private:
    PointStr m_Parameters;
    QVector<FixWidget *> m_FixWidgets;
};

#endif // FIXAREA_H
