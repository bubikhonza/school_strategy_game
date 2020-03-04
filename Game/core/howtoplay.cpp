#include "howtoplay.h"
#include "ui_howtoplay.h"

HowToPlay::HowToPlay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HowToPlay)
{
    ui->setupUi(this);
    this->setWindowTitle("How to play");
}

HowToPlay::~HowToPlay()
{
    delete ui;
}

void HowToPlay::on_pushButton_clicked()
{
    this->close();
}
