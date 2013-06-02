#ifndef FIXWIDGET_H
#define FIXWIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QHBoxLayout>

#include "matmod/Range.h"
#include <Matmod/mathmod.h>

using mathmod::Rangef;
using mathmod::FixedStruct;

class FixWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FixWidget(std::string param, QWidget *parent = 0);
    QString value();
    void setRange(Rangef range);
    FixedStruct fixedStruct();
signals:

public slots:
    bool isCheched();
private slots:
    void valChanged(double val);

private:
    QRadioButton *m_checkParam;
    QDoubleSpinBox *m_dsbValue;
    QLabel *m_lblParameter;

};

#endif // FIXWIDGET_H
