


#include "parametrswidget.h"

ParametrsWidget::ParametrsWidget(QWidget *parent) :
    QWidget(parent)
{
    QStringList vertHeaders("Параметри");

    QGridLayout *layout = new QGridLayout();
    layout->setSpacing(1);

    m_tableWidget = new QTableWidget(parent);
    m_tableWidget->setRowCount(1);
    m_tableWidget->setColumnCount(1);
    m_tableWidget->setMaximumWidth(135);

    m_tableWidget->setHorizontalHeaderLabels(vertHeaders);

    m_checkT = new QTableWidgetItem("t");
    m_checkT->setTextAlignment(Qt::AlignCenter);
    m_checkT->setCheckState(Qt::Checked);

    m_tableWidget->setItem(0, 0, m_checkT);

    m_spinBox = new QSpinBox(parent);
    m_spinBox->setMinimum(1);
    m_spinBox->setMinimumSize(50, 30);
    m_spinBox->setMaximumSize(80, 30);

    layout->addWidget(m_spinBox, 0, 0, 1, 1, Qt::AlignCenter);
    layout->addWidget(m_tableWidget, 1, 0, 1, 1);

    parent->setLayout(layout);

    connect(m_spinBox, SIGNAL(valueChanged(int)), this, SLOT(numParametersChange(int)));
}


PointStr ParametrsWidget::parameters()
{
    m_Parameters.clear();

    if(m_checkT->checkState() == Qt::Checked)
        m_Parameters.push_back("t");

    for(int i = 1; i < m_tableWidget->rowCount(); i++)
    {
        m_Parameters.push_back(m_tableWidget->item(i, 0)->text().toStdString());
    }

    return m_Parameters;
}

void ParametrsWidget::numParametersChange(int num)
{
    int columnCount = m_tableWidget->columnCount();
    m_tableWidget->setRowCount(num);
    for(int i = columnCount; i < num; i++)
    {
        QTableWidgetItem *cellText = new QTableWidgetItem("x" + QString::number(i));
        cellText->setTextAlignment(Qt::AlignCenter);

        m_tableWidget->setItem(i, 0, cellText);
        m_tableWidget->setColumnWidth(i, 40);
    }
}
