#ifndef HOWTOPLAY_H
#define HOWTOPLAY_H

#include <QDialog>

namespace Ui {
class HowToPlay;
}
/**
 * @brief This is form class which displays rules of game
 */
class HowToPlay : public QDialog
{
    Q_OBJECT

public:
    explicit HowToPlay(QWidget *parent = nullptr);
    ~HowToPlay();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HowToPlay *ui;
};

#endif // HOWTOPLAY_H
