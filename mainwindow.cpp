#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <memory>
#include "AppBackend/include/GameEngine.h"
#include "AppBackend/include/HumanPlayer.h"
#include "AppBackend/include/RandomStrategy.h"
#include "AppBackend/include/SmartStrategy.h"
#include "AppBackend/include/Strategy.h"
#include "AppBackend/include/Player.h"
#include "AppBackend/include/FrequencyMap.h"
#include "AppBackend/include/FileHandler.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gameEngine(nullptr)
{
    ui->setupUi(this);

    connect(ui->startGameButton, &QPushButton::clicked, this, &MainWindow::onClick_StartGame);
    connect(ui->pushButtonRock, &QPushButton::clicked, this, &MainWindow::onClickRockButton);
    connect(ui->pushButtonPaper, &QPushButton::clicked, this, &MainWindow::onClickPaperButton);
    connect(ui->pushButtonScissor, &QPushButton::clicked, this, &MainWindow::onClickScissorButton);

    // Initially disable the game control buttons
    ui->pushButtonRock->setEnabled(false);
    ui->pushButtonPaper->setEnabled(false);
    ui->pushButtonScissor->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gameEngine;
}

// Define what happens when the Rock button is clicked

void MainWindow::onClickRockButton(){

    ui->label_4->setText("Rock");
    ui->winnerLabel->setText(QString::fromStdString(gameEngine->playRound(ROCK)));
    frequencyMap.updateFrequencyMap('R');
}

void MainWindow::onClickPaperButton(){
    ui->label_4->setText("Paper");
    ui->winnerLabel->setText(QString::fromStdString(gameEngine->playRound(PAPER)));
    frequencyMap.updateFrequencyMap('P');
}

void MainWindow::onClickScissorButton(){
    ui->label_4->setText("Scissor");
    ui->winnerLabel->setText(QString::fromStdString(gameEngine->playRound(SCISSORS)));
    frequencyMap.updateFrequencyMap('S');
}

void MainWindow::onClick_StartGame()
{
    // Check if buttons are disabled, and enable them if they are
    if (!ui->pushButtonRock->isEnabled()) ui->pushButtonRock->setEnabled(true);
    if (!ui->pushButtonPaper->isEnabled()) ui->pushButtonPaper->setEnabled(true);
    if (!ui->pushButtonScissor->isEnabled()) ui->pushButtonScissor->setEnabled(true);

    QString strategyChoice = ui->strategySelection->currentText();
    int value = ui->numberOfRounds->value();

    std::unique_ptr<Strategy> strategy;
    FileHandler fileHandler;

    if (strategyChoice == "Random") {
        strategy = std::make_unique<RandomStrategy>();
    } else {
        fileHandler.readFrequenciesFromFile("frequencies.txt",frequencyMap.frequencyMap);
        strategy = std::make_unique<SmartStrategy>(&frequencyMap);
    }

    Player* computerPlayer = new ComputerPlayer(std::move(strategy));

    // Create human player object
    HumanPlayer humanPlayer;

    // Create the game engine and start the game
    gameEngine = new GameEngine(&humanPlayer, dynamic_cast<ComputerPlayer*>(computerPlayer));

}
