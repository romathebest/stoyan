#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogchooseexistprocess.h"
#include "qcustomplot.h"

#include <Widgets/parametrswidget.h>
#include <Widgets/areawidget.h>
#include <Widgets/observationpointwidget.h>
#include <Widgets/plotdrawing.h>
#include <Widgets/fixarea.h>
#include <Widgets/areaoutsidewidget.h>

#include <Matmod/System.h>
#include <Matmod/wolframconverter.h>
#include <Matmod/passport.h>
#include <Matmod/mathmod.h>
#include "Matmod/wolframconnector.h"

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

//    void on_comboBoxControlType_activated(int index);

    void rewritePassport();
    void rewriteWolframCode();

    void writePassportFromExistTask(QString text);

    void on_pushButton_6_pressed();

    void on_pushButton_7_pressed();

    void on_pushButton_8_pressed();

    void on_pushButton_9_pressed();

    void on_radioButtonInverseProblem_3_pressed();

    void on_radioButtonDirectProblem_3_pressed();

    void on_pushButtonConnectWithWolfram_clicked();

    void on_pushButtonSolve_clicked();

    void on_pushButtonBuildPassport_clicked();

    void on_pushButton_3_clicked();

private:
    bool* m_Control;
    Ui::MainWindow *ui;
    ParametrsWidget *m_ParametersWidget;
    AreaWidget *m_AreaWidget;
    AreaOutsideWidget *m_AreaWidgetModU;
    AreaOutsideWidget *m_AreaWidgetModUg;
    FixArea * m_FixPointsWidget;
    ObservationPointWidget *m_ObservationPointWidget;
    ObservationPointWidget *m_PointWidgetU0;
    ObservationPointWidget *m_PointWidgetU;
    ObservationPointWidget *m_PointWidgetUG;
    dialogChooseExistProcess* m_DialogGetProcess;

    PlotDrawing* m_PlotDrawing;
    WolframConnector* m_WolframObject;
    WolframConverter *m_WolframConverter;
    IConverterObject *m_PassportObject;
    System *m_System;
};

#endif // MAINWINDOW_H
