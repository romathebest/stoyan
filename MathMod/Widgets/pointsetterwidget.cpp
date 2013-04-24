#include "pointsetterwidget.h"

PointSetterWidget::PointSetterWidget(int min, int max, QWidget *parent) :
    QWidget(parent)
{
     QHBoxLayout *hbox = new QHBoxLayout(this);

     m_lblMinimum = new QLabel(this);
     m_lblMaximum = new QLabel(this);
    // m_Slider = new QSliderJump(this);
     m_Slider = new QSlider(this);
     m_Slider->setOrientation(Qt::Horizontal);

     setRange(min, max);

     hbox->addWidget(m_lblMinimum);
     hbox->addWidget(m_Slider);
     hbox->addWidget(m_lblMaximum);

     connect(m_Slider, SIGNAL(valueChanged(int)), this, SLOT(sliderMove(int)));
}

 void PointSetterWidget::setRange(int min, int max)
 {
    m_lblMinimum->setText(QString::number(min));
    m_lblMaximum->setText(QString::number(max));
    m_Slider->setMinimum(min);
    m_Slider->setMaximum(max);
 }

  void PointSetterWidget::setValue(int val)
  {
    m_Slider->setValue(val);
  }

 void PointSetterWidget::sliderMove(int val)
 {
    emit valueChanged(val);
 }
