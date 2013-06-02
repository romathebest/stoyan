#include "fixwidget.h"

FixWidget::FixWidget(std::string param, QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *vbox = new QHBoxLayout(this);
    vbox->setSpacing(1);

    m_dsbValue = new QDoubleSpinBox(this);

    m_lblParameter = new QLabel(QString::fromStdString(param), this);

    vbox->addWidget(m_lblParameter);
    vbox->addWidget(m_dsbValue);

    connect(m_dsbValue, SIGNAL(valueChanged(double)), this, SLOT(valChanged(double)));
}

void FixWidget::setRange(Rangef range)
{
    m_dsbValue->setMinimum(range.min);
    m_dsbValue->setMaximum(range.max);
}

void FixWidget::valChanged(double val)
{
    m_dsbValue->setValue(val);
}

QString FixWidget::value()
{
    return m_dsbValue->text();
}

