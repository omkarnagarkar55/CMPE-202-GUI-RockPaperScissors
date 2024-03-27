#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "AppBackend/include/GameEngine.h"
#include "AppBackend/include/FrequencyMap.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void onClick_StartGame();
    void onClickRockButton();
    void onClickPaperButton();
    void onClickScissorButton();

private:
    Ui::MainWindow *ui;
    int gamePlayed = 0;
    GameEngine *gameEngine;
    FrequencyMap frequencyMap;
};
#endif // MAINWINDOW_H
