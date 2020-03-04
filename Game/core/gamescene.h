#ifndef GAMESCENE_H
#define GAMESCENE_H
#include "graphics/simplegamescene.h"
#include "core/mapitem.h"

namespace Game {
    class GameScene;
}
class GameScene: public Course::SimpleGameScene
{
    Q_OBJECT
public:

    /**
     * @brief Constructor for the class.
     *
     * @param qt_parent points to the parent object per Qt's parent-child-system.
     * @param width in tiles for the game map.
     * @param height in tiles for the game map.
     * @param scale is the size in pixels of a single square tile.
     *
     * @pre 0 < width <= 100 && 0 < height <= 100 && 0 < scale <= 500. Otherwise
     * default values are used for the created object.
     */
    GameScene(QWidget* qt_parent = nullptr,
              int width = 10,
              int height = 10,
              int scale = 50);

    /**
     * @brief simple event handler that notifies when objects or the play
     * area is clicked.
     * @param event that has happened.
     * @return True: if event was  handled in the handler.
     * False: if the event handling was passed over.
     */
    bool event(QEvent* event) override;
    /**
     * @brief draws building
     */
    void drawBuilding( std::shared_ptr<Course::GameObject> obj);
    /**
     * @brief draws tile
     */
    void drawTile( std::shared_ptr<Course::GameObject> obj);
    /**
     * @brief draws worker
     */
    void drawWorker( std::shared_ptr<Course::GameObject> obj);
    /**
     * @brief removes worker
     */
    void removeWorker( QGraphicsItem *obj);


signals:
    void signal_tile_clicked(std::shared_ptr<Course::GameObject>, QGraphicsItem*);
    void signal_update_window();

};

#endif // GAMESCENE_H
