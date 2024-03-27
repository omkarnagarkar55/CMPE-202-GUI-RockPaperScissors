#include "../include/MainWindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_pushButton_3_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Define what happens when the Rock button is clicked
void MainWindow::on_pushButton_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    ui->label_4->setText(button->text());
}

// Define what happens when the Paper button is clicked
void MainWindow::on_pushButton_2_clicked()
{
    ui->label_4->setText("Paper");
}

// Define what happens when the Scissors button is clicked
void MainWindow::on_pushButton_3_clicked()
{
    ui->label_4->setText("Scissors");
}
