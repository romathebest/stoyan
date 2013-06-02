#ifndef FIXWIDGET_H
#define FIXWIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QHBoxLayout>

#include "matmod/Range.h"
#include <Matmod/mathmod.h>
#include <Matmod/Range.h>
#include <string>

using mathmod::Rangef;
using mathmod::FixedStruct;
using std::string;
using mathmod::Converter;

class FixWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FixWidget(std::string param, QWidget *parent = 0);
    QString value();
    void setRange(Rangef range);
    FixedStruct fixedStruct();
    string valueWithRange();
signals:

public slots:
    bool isCheched();
private slots:
    void valChanged(double val);

private:
    QRadioButton *m_checkParam;
    QDoubleSpinBox *m_dsbValue;
    QLabel *m_lblParameter;
    Rangef m_Range;

};

#endif // FIXWIDGET_H
