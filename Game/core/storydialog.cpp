#include "storydialog.h"
#include "ui_storydialog.h"

StoryDialog::StoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StoryDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Intro");
}

StoryDialog::~StoryDialog()
{
    delete ui;
}

void StoryDialog::on_pushButton_clicked()
{
    this->close();
}
