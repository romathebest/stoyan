#ifndef ANALIZATOR_H
#define ANALIZATOR_H

#include <QObject>

class Analizator : public QObject
{
    Q_OBJECT
public:
    Analizator(QObject *parent = NULL);
    ~Analizator();

    QString getTextField();

public slots:
    void setProcessParameters(QString, QString, QString);

private:
    QString mProcess;
    QString mControl;
    QString mGrin;

};

#endif // ANALIZATOR_H
