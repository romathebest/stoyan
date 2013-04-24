#ifndef PARAMETRSWIDGET_H
#define PARAMETRSWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QSpinBox>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QLineEdit>

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
    QCheckBox *m_checkT;

    PointStr m_Parameters;
    int m_CurrentValue;
    char m_paramStep;
    
};

#endif // PARAMETRSWIDGET_H
