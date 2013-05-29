#ifndef FIXWIDGET_H
#define FIXWIDGET_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QHBoxLayout>

class FixWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FixWidget(std::string param, QWidget *parent = 0);
    QString value();
signals:

public slots:

private slots:
    void valChanged(double val);

private:

    QDoubleSpinBox *m_dsbValue;
    QLabel *m_lblParameter;

};

#endif // FIXWIDGET_H
