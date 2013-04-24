#include "qsliderjump.h"

QSliderJump::QSliderJump(QWidget *parent) :
    QSlider(parent)
{
    setOrientation(Qt::Horizontal);
}

void QSliderJump::mousePressEvent ( QMouseEvent * event )
{
    if (event->button() == Qt::LeftButton)
        {
            /*if (orientation() == Qt::Vertical)
                setValue(minimum() + ((maximum()-minimum()) * (height()-event->y())) / height() ) ;
            else
                setValue(minimum() + ((maximum()-minimum()) * event->x()) / width() ) ;
                */
         if (orientation() == Qt::Horizontal)
             setValue(minimum() + ((maximum()-minimum()) * (event->x())) / width() ) ;

            event->accept();
        }
   QSlider::mousePressEvent(event);
}
