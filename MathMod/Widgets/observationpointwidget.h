#ifndef OBSERVATIONPOINTWIDGET_H
#define OBSERVATIONPOINTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPushButton>

#include <Matmod/Area.h>
#include <Widgets/pointsetterwidget.h>
#include <Matmod/Point.h>

#include <vector>
using std::vector;

class ObservationPointWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ObservationPointWidget(mathmod::Area a, QWidget *parent = 0);
    vector<mathmod::Pointf> points();
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
