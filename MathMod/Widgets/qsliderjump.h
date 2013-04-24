#ifndef QSLIDERJUMP_H
#define QSLIDERJUMP_H

#include <QSlider>
#include <QMouseEvent>

class QSliderJump : public QSlider
{
    Q_OBJECT
public:
    explicit QSliderJump(QWidget *parent = 0);
    
signals:
    
public slots:

protected:
    void mousePressEvent ( QMouseEvent * event );
    
};

#endif // QSLIDERJUMP_H
