#ifndef MAPITEM_H
#define MAPITEM_H
#include "graphics/simplemapitem.h"

namespace Game{
class MapItem;
}
class MapItem: public Course::SimpleMapItem
{


public:
    /**
     * @brief Constructor
     * @param obj points to GameObject
     * @param size of the created item in pixels
     **/
    MapItem(const std::shared_ptr<Course::GameObject> &obj, int size);
    /**
     * @brief paints the item
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    /**
     * @brief Change items's coordinate.
     * @param coordinate The new coordinate.
     */
    void setCoordinates(int x, int y);

private:
    std::string objectType;
    std::shared_ptr<Course::GameObject> myObject;
    int x = 0;
    int y = 0;
};

#endif // MAPITEM_H
