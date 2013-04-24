#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <Widgets/parametrswidget.h>
#include <Widgets/areawidget.h>
#include <Widgets/observationpointwidget.h>

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

private:
    Ui::MainWindow *ui;
    ParametrsWidget *m_ParametersWidget;
    AreaWidget *m_AreaWidget;
    ObservationPointWidget *m_ObservationPointWidget;
};

#endif // MAINWINDOW_H
