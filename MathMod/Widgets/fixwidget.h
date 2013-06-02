#ifndef FIXWIDGET_H
#define FIXWIDGET_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QHBoxLayout>

#include "matmod/Range.h"

using mathmod::Rangef;

class FixWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FixWidget(std::string param, QWidget *parent = 0);
    QString value();
    void setRange(Rangef range);
signals:

public slots:

private slots:
    void valChanged(double val);

private:

    QDoubleSpinBox *m_dsbValue;
    QLabel *m_lblParameter;

};

#endif // FIXWIDGET_H
