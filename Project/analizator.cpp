#include<QDebug>

#include "analizator.h"

Analizator::Analizator(QObject* parent) : QObject(parent)
{
}

Analizator::~Analizator()
{
}

void Analizator::setProcessParameters(QString process, QString grin, QString control)
{
    mProcess = process;
    mGrin = grin;
    mControl = control;
}

QString Analizator::getTextField()
{
    QString text;
    text = " Процес: \n"+mProcess +"\n Функція Гріна: \n"+mGrin;

    if (mControl != "")
    {
        text += "\n Функція керування:\n"+mControl;
    }
    return text;
}
