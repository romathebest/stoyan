#ifndef RANGEWIDGET_H
#define RANGEWIDGET_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QHBoxLayout>

#include "Matmod/Range.h"

using mathmod::Rangef;

class RangeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RangeWidget(bool aIsMod, std::string param, QWidget *parent = 0);
    Rangef range();
signals:
    
public slots:

private slots:
    void minimumRangeChanged(double val);
    void maximumRangeChanged(double val);

private:
    bool m_IsMod;
    Rangef m_Range;

    QDoubleSpinBox *m_dsbMinValue, *m_dsbMaxValue;
    QDoubleSpinBox *m_dsbMinValueLeft, *m_dsbMaxValueRight;
    QLabel *m_lblParameter;
    
};

#endif // RANGEWIDGET_H
