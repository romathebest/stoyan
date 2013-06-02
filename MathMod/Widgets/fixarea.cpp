#include "fixarea.h"

FixArea::FixArea(PointStr param, QWidget *parent) :
    QWidget(parent), m_Parameters(param)
{
    QGridLayout *vbox = new QGridLayout();
    vbox->setSpacing(1);

    for(int i = 0; i < m_Parameters.size(); i++)
    {
        m_FixWidgets.push_back(new FixWidget(m_Parameters[i]));
        vbox->addWidget(m_FixWidgets.back(), 0, i, 1, 1, Qt::AlignCenter);
    }

    parent->setLayout(vbox);
}

void FixArea::setArea(Area area)
{
    for(int i = 0; i < area.size(); ++i)
    {
        // area size == widgets size
        m_FixWidgets.at(i)->setRange(area[i]);
    }
}

FixArea::~FixArea()
{
    m_FixWidgets.clear();
}

 QString FixArea::sequence()
 {
     QString res("");
     for(int i = 0; i < m_Parameters.size(); i++)
         res += QString::fromStdString(m_Parameters[i]) + " ";
     return res;
 }

