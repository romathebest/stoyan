#include "fixwidget.h"

FixWidget::FixWidget(std::string param, QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *vbox = new QHBoxLayout(this);
    vbox->setSpacing(1);

    m_checkParam = new QRadioButton(this);
    m_checkParam->setChecked(true);

    m_dsbValue = new QDoubleSpinBox(this);

    m_lblParameter = new QLabel(QString::fromStdString(param), this);

    vbox->addWidget(m_checkParam);
    vbox->addWidget(m_lblParameter);
    vbox->addWidget(m_dsbValue);

    connect(m_dsbValue, SIGNAL(valueChanged(double)), this, SLOT(valChanged(double)));
}

void FixWidget::setRange(Rangef range)
{
    m_Range = range;
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

bool FixWidget::isCheched()
{
    return m_checkParam->isChecked();
}

FixedStruct FixWidget::fixedStruct()
{
    FixedStruct fs;
    fs.param = m_lblParameter->text().toStdString();
    fs.value = QString::number(m_dsbValue->value()).toStdString();
    return fs;
}

 string FixWidget::valueWithRange()
 {
     string str = "{" + m_Range.param + ", " + Converter::toStr<float>(m_Range.min) +
             ", " + Converter::toStr<float>(m_Range.max) + "}";
     return str;
 }

