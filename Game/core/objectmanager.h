#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <interfaces/iobjectmanager.h>

#include <tiles/tilebase.h>

namespace Game {
    class ObjectManager;
}
/**
 * @brief Class ObjectManager implements iObjectManager interface
 *  class interract with objects
 */
class ObjectManager : public Course::iObjectManager
{   

public:
    /**
     * @brief Adds new tiles to the ObjectManager.
     * @param tiles a vector that contains the Tiles to be added.
     * @post The tile-pointers in the vector are stored in the ObjectManager.
     * Exception Guarantee: Basic
     *
     */
    void addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles);
    /**
     * @brief Returns a shared pointer to a Tile that has specified coordinate.
     * @param coordinate Requested Tile's Coordinate
     * @return a pointer to a Tile that has the given coordinate.
     * If no for the coordinate exists, return empty pointer.
     * @post Exception Guarantee: Basic
     */
    std::shared_ptr<Course::TileBase> getTile(const Course::Coordinate &coordinate);
    /**
     * @brief Returns a shared pointer to a Tile that has specified ID
     * @param id Tile's ObjectId.
     * @return a pointer to the Tile that has the given ID
     * If no for the id exists, return empty pointer.
     * @post Exception Guarantee: Basic
     */
    std::shared_ptr<Course::TileBase> getTile(const Course::ObjectId &id);

    /**
     * @brief Returns a vector of shared pointers to Tiles specified by
     * a vector of Coordinates.
     * @param coordinates a vector of Coordinates for the requested Tiles
     * @return Vector of that contains pointers to Tile's that match
     * the coordinates. The vector is empty if no matches were made.
     * @post Exception Guarantee: Basic
     */
    std::vector<std::shared_ptr<Course::TileBase> > getTiles(const std::vector<Course::Coordinate> &coordinates);
    /**
     * @brief Returns a vector of shared pointers to Tiles
     * @return tiles
     */
    std::vector<std::shared_ptr<Course::TileBase> > getAllTiles();
    /**
     * @brief Returns a nubmer of free tiles in a game
     * @return count of free tiles in a game
     */
    int getNumberOfFreeTiles();

private:
    std::vector<std::shared_ptr<Course::TileBase>> tiles;
};

#endif // OBJECTMANAGER_H
