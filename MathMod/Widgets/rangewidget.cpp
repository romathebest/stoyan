#include "rangewidget.h"

RangeWidget::RangeWidget(bool aIsMod, std::string param, QWidget *parent) :
    QWidget(parent),
    m_IsMod(aIsMod)
{
    m_Range.param = param;

    QHBoxLayout *vbox = new QHBoxLayout(this);
    vbox->setSpacing(1);

    m_dsbMaxValue = new QDoubleSpinBox(this);
    m_dsbMinValue = new QDoubleSpinBox(this);
    if (m_IsMod)
    {
        m_dsbMinValueLeft = new QDoubleSpinBox(this);
        m_dsbMaxValueRight = new QDoubleSpinBox(this);
    }

    m_lblParameter = new QLabel(QString::fromStdString(m_Range.param), this);

    if (m_IsMod) vbox->addWidget(m_dsbMinValueLeft);
    vbox->addWidget(m_dsbMinValue);
    vbox->addWidget(m_lblParameter);
    vbox->addWidget(m_dsbMaxValue);
    if (m_IsMod) vbox->addWidget(m_dsbMaxValueRight);

    m_dsbMinValue->setMaximum(0.0d);
    connect(m_dsbMaxValue, SIGNAL(valueChanged(double)), this, SLOT(maximumRangeChanged(double)));
    connect(m_dsbMinValue, SIGNAL(valueChanged(double)), this, SLOT(minimumRangeChanged(double)));
}

void RangeWidget::minimumRangeChanged(double val)
{
    m_dsbMaxValue->setMinimum(val);
}

void RangeWidget::maximumRangeChanged(double val)
{
    m_dsbMinValue->setMaximum(val);
}

Rangef RangeWidget::range()
{
    m_Range.min = m_dsbMinValue->value();
    m_Range.max = m_dsbMaxValue->value();
    return m_Range;
}
