#include "parametrswidget.h"

ParametrsWidget::ParametrsWidget(QWidget *parent) :
    QWidget(parent), m_CurrentValue(1)
{
   // this->setSizePolicy(Qt::PreferredSize, Qt::PreferredSize);

    m_paramStep = 'a';

    QStringList horzHeaders("t");
    QStringList vertHeaders("Параметри");

    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->setSpacing(1);

    m_tableWidget = new QTableWidget(this);
    m_tableWidget->setRowCount(1);
    m_tableWidget->setColumnCount(1);
    m_tableWidget->setMinimumHeight(55);
    m_tableWidget->setMaximumHeight(75);
    //m_tableWidget->setMaximumSize(1000, 55);

    m_tableWidget->setHorizontalHeaderLabels(horzHeaders);
    m_tableWidget->setVerticalHeaderLabels(vertHeaders);

    m_checkT = new QCheckBox(this);
    m_checkT->setChecked(true);

    m_tableWidget->setCellWidget(0, 0, m_checkT);
    m_tableWidget->setColumnWidth(0, 15);
    m_tableWidget->setMinimumWidth(375);

    m_spinBox = new QSpinBox(this);
    m_spinBox->setMinimum(1);
    m_spinBox->setMaximum(26);
    m_spinBox->findChild<QLineEdit*>()->setReadOnly(true);
    m_spinBox->setMinimumSize(30, 30);

    hbox->addWidget(m_spinBox);
    hbox->addWidget(m_tableWidget);

    setLayout(hbox);

    connect(m_spinBox, SIGNAL(valueChanged(int)), this, SLOT(numParametersChange(int)));
}

PointStr ParametrsWidget::parameters()
{
    m_Parameters.clear();

    int n = m_tableWidget->columnCount();
    if(m_checkT->isChecked()) n++;

    if(m_checkT->isChecked()) m_Parameters.push_back("t");
    for(int i = 1; i < m_tableWidget->columnCount(); i++)
    {
        m_Parameters.push_back(m_tableWidget->item(0, i)->text().toStdString());
    }

    return m_Parameters;
}

void ParametrsWidget::numParametersChange(int num)
{
    m_tableWidget->setColumnCount(num);
    if(m_CurrentValue < num)
    {
        QTableWidgetItem *cellText = new QTableWidgetItem(QString(m_paramStep));
        m_paramStep++;
        if(m_paramStep == 't') m_paramStep++;

        m_tableWidget->setItem(0, num - 1, cellText);
        m_tableWidget->setColumnWidth(num - 1, 40);
    }
    else
    {
        m_paramStep--;
        if(m_paramStep == 't') m_paramStep--;
    }
    m_CurrentValue = num;
}
