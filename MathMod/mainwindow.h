#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <Widgets/parametrswidget.h>
#include <Widgets/areawidget.h>
#include <Widgets/observationpointwidget.h>

#include <Matmod/System.h>
#include <Matmod/passport.h>
#include <Matmod/mathmod.h>


using namespace mathmod;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    
    void on_pushButton_pressed();

    void on_pushButton_2_clicked();

    void on_pushButton_5_pressed();


    void on_radioButtonDirectProblem_pressed();

    void on_radioButtonInverseProblem_pressed();

    void on_comboBoxControlType_activated(int index);

    void rewritePassport();

private:
    Ui::MainWindow *ui;
    ParametrsWidget *m_ParametersWidget;
    AreaWidget *m_AreaWidget;
    ObservationPointWidget *m_ObservationPointWidget;

    IConverterObject *m_PassportObject;
    System *m_System;
};

#endif // MAINWINDOW_H
