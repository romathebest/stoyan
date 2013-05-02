#ifndef PARAMETRSWIDGET_H
#define PARAMETRSWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QSpinBox>
#include <QGridLayout>

#include "Matmod/Point.h"

using mathmod::PointStr;

class ParametrsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ParametrsWidget(QWidget *parent = 0);
    PointStr parameters();
signals:

public slots:
    void numParametersChange(int num);
private:
    QTableWidget *m_tableWidget;
    QSpinBox *m_spinBox;
    QTableWidgetItem *m_checkT;

    PointStr m_Parameters;
};

#endif // PARAMETRSWIDGET_H
