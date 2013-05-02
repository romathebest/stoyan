#include "observationpointwidget.h"

ObservationPointWidget::ObservationPointWidget(mathmod::Area area, QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *hbox = new QHBoxLayout();

   // QVBoxLayout *vboxSlider = new QVBoxLayout();
    QVBoxLayout *vboxTable = new QVBoxLayout();

    QStringList horzHeaders;
    for(int i = 0; i < area.size(); i++)
    {
        horzHeaders.push_back(QString::fromStdString(area[i].param));
        //QHBoxLayout *hbox = new QHBoxLayout();
        //hbox->addWidget(new QLabel("| " + QString::fromStdString(area[i].param) + " |"));
        //PointSetterWidget *psw = new PointSetterWidget(area[i].min, area[i].max);
        //hbox->addWidget(psw);
       // m_vPointsSetter.push_back(psw);
       // vboxSlider->addLayout(hbox);
    }

    horzHeaders.push_back("y");

    m_twPoints = new QTableWidget();
    m_twPoints->setColumnCount(area.size() + 1);

    m_twPoints->setHorizontalHeaderLabels(horzHeaders);
    m_twPoints->resizeColumnsToContents();

    m_pbAddPoint = new QPushButton();
    m_pbAddPoint->setText("Додати точку");
    vboxTable->addWidget(m_twPoints);
    vboxTable->addWidget(m_pbAddPoint);

   // hbox->addLayout(vboxSlider);
    hbox->addLayout(vboxTable);

    parent->setLayout(hbox);

    connect(m_pbAddPoint, SIGNAL(clicked()), this, SLOT(addPoint()));

}

void ObservationPointWidget::addPoint()
{
    m_twPoints->insertRow(m_twPoints->rowCount());
}
