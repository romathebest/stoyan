#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "processdialog.h"
#include "analizator.h"

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
    void on_actionQuit_triggered();

    void on_action_triggered();
    void areaCliked(QMouseEvent* event);


private:
    Ui::MainWindow *ui;

    bool isInitialize;
    ProcessDialog* dialogProcess;
    Analizator* analizator;

    void WriteTextField();

};

#endif // MAINWINDOW_H
