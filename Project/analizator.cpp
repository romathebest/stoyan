#include<QDebug>

#include "analizator.h"

Analizator::Analizator(QObject* parent) : QObject(parent)
{
}

Analizator::~Analizator()
{
}

void Analizator::clearAllFields()
{
    mProcess.clear();
    mGrin.clear();
    mControl.clear();
    mFullTask.clear();
}

void Analizator::setProcessParameters(QString process, QString grin, QString control)
{
    mProcess = process;
    mGrin = grin;
    mControl = control;
}

void Analizator::setProcessParameters(QString task)
{
    mFullTask = task;
}

QString Analizator::getTextField()
{
    if (!mFullTask.isEmpty())
    {
        return mFullTask;
    }

    QString text;
    text = " Процес: \n"+mProcess +"\n Функція Гріна: \n"+mGrin;

    if (mControl != "")
    {
        text += "\n Функція керування:\n"+mControl;
    }
    return text;
}
