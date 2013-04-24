#ifndef POINTSETTERWIDGET_H
#define POINTSETTERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextBlock>

#include <Widgets/qsliderjump.h>

class PointSetterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PointSetterWidget(int min, int max, QWidget *parent = 0);
    void setRange(int min, int max);
    void setValue(int val);
signals:
    void valueChanged(int );
public slots:
private slots:
    void sliderMove(int val);
private:
    QLabel *m_lblMinimum;
    QLabel *m_lblMaximum;
    QSlider *m_Slider;
    QTextBlock *m_tbValue;
    
};

#endif // POINTSETTERWIDGET_H
