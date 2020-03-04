#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QDialog>
#include "core/worldgenerator.h"
#include "tiles/forest.h"
#include "tiles/grassland.h"
#include <core/objectmanager.h>
#include <core/worldgenerator.h>
#include <core/myresourcemaps.h>


namespace Ui {
class MenuWindow;
}
/**
 * @brief This is form class which displays
 * after starting game
 * it is displays Menu window
 **/
class MenuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    
    ~MenuWindow();
    template<typename T>
    friend void Course::WorldGenerator::addConstructor(unsigned int weight);
    friend void Course::WorldGenerator::addConstructor<Course::Forest>(unsigned int weight);


private slots:
    void on_players3Btn_clicked();

    void on_players2Btn_clicked();

    void on_players4Btn_clicked();

    void on_exitBtn_clicked();

    void on_howToPlayBtn_clicked();

private:
    Ui::MenuWindow *ui;
    void generateWorld();
    void getDifficulty();
    uint forest;
    uint grassland;
    uint desert;
    uint mountains;
    uint swamp;
};


#endif // MENUWINDOW_H
