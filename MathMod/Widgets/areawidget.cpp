#include "areawidget.h"

AreaWidget::AreaWidget(PointStr param, QWidget *parent) :
    QWidget(parent), m_Parameters(param)
{
    QVBoxLayout *vbox = new QVBoxLayout(this);
   // vbox->setSpacing(1);

    for(int i = 0; i < m_Parameters.size(); i++)
    {
        m_RangeWidgets.push_back(new RangeWidget(m_Parameters[i], this));
        vbox->addWidget(m_RangeWidgets.back());
    }

    setLayout(vbox);
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
