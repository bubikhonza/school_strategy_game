#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>

namespace Ui {
class GameOver;
}
/**
 * @brief This is a form class which displays when game ends
 */
class GameOver : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the class.
     * @param winner's name
     * @param winner's score
     */
    explicit GameOver(QString winnerName,double max, QWidget *parent = nullptr);
    ~GameOver();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GameOver *ui;
};

#endif // GAMEOVER_H
