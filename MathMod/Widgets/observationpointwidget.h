#ifndef OBSERVATIONPOINTWIDGET_H
#define OBSERVATIONPOINTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>
#include <QTableWidget>
#include <QPushButton>

#include <Matmod/Area.h>
#include <Widgets/pointsetterwidget.h>

class ObservationPointWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ObservationPointWidget(mathmod::Area a, QWidget *parent = 0);
    
signals:
    
public slots:
private slots:
    void addPoint();
private:
    QVector<PointSetterWidget *> m_vPointsSetter;
    QTableWidget *m_twPoints;
    QPushButton *m_pbAddPoint;
    
};

#endif // OBSERVATIONPOINTWIDGET_H
