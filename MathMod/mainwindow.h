#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogchooseexistprocess.h"
#include "qcustomplot.h"

#include <Widgets/parametrswidget.h>
#include <Widgets/areawidget.h>
#include <Widgets/observationpointwidget.h>

#include <Matmod/System.h>
#include <Matmod/passport.h>
#include <Matmod/mathmod.h>
#include "Matmod/wolframobject.h"

using namespace mathmod;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void DisableProcessInput();

    ~MainWindow();
private slots:
    
    void on_pushButton_pressed();

    void on_pushButton_2_clicked();

    void on_pushButton_5_pressed();

    void on_radioButtonDirectProblem_pressed();

    void on_radioButtonInverseProblem_pressed();

    void on_comboBoxControlType_activated(int index);

    void rewritePassport();

    void writePassportFromExistTask(QString text);

    void on_pushButton_3_pressed();

    void on_pushButton_4_pressed();

    void on_pushButton_6_pressed();

    void on_pushButton_7_pressed();

    void on_pushButton_8_pressed();

    void on_pushButton_9_pressed();

private:
    Ui::MainWindow *ui;
    ParametrsWidget *m_ParametersWidget;
    AreaWidget *m_AreaWidget;
    ObservationPointWidget *m_ObservationPointWidget;
    dialogChooseExistProcess* m_DialogGetProcess;

    WolframObject* m_WolframObject;
    IConverterObject *m_PassportObject;
    System *m_System;
};

#endif // MAINWINDOW_H
