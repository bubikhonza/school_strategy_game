#include "gameover.h"
#include "ui_gameover.h"


GameOver::GameOver(QString winnerName, double max, QWidget *parent):
QDialog(parent),
ui(new Ui::GameOver)
{

ui->setupUi(this);
ui->winnerLabel->setText("Winner is: " + winnerName);
ui->scoreLabel->setText("Score: " + QString::number(max));
}

GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_pushButton_clicked()
{

    this->close();
}
