#include "areawidget.h"

AreaWidget::AreaWidget(PointStr param, QWidget *parent) :
    QWidget(parent), m_Parameters(param)
{
    QGridLayout *vbox = new QGridLayout();
    vbox->setSpacing(1);

    for(int i = 0; i < m_Parameters.size(); i++)
    {
        m_RangeWidgets.push_back(new RangeWidget(m_Parameters[i]));
        vbox->addWidget(m_RangeWidgets.back(), i, 0, 1, 1, Qt::AlignCenter);
    }

    parent->setLayout(vbox);
}

AreaWidget::~AreaWidget()
{
    m_RangeWidgets.clear();
}

 Area AreaWidget::area()
 {
     Area area;
     for(int i = 0; i < m_RangeWidgets.size(); i++)
     {
         area.addRange(m_RangeWidgets[i]->range());
     }
     return area;
 }
