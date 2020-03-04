#include "objectmanager.h"
#include <vector>
#include <QDebug>

void ObjectManager::addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles)
{
    this->tiles.insert(std::end(this->tiles), std::begin(tiles), std::end(tiles));
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::Coordinate &coordinate)
{
    for(int i = 0; i<this->tiles.size(); i++){
        if(this->tiles.at(i)->getCoordinate() == coordinate){
            return this->tiles.at(i);
        }
    }
    return nullptr;
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::ObjectId &id)
{
    for(int i = 0; i<this->tiles.size(); i++){
        if(this->tiles.at(i)->ID == id){
            return this->tiles.at(i);
        }
    }
    return nullptr;
}



std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getTiles(const std::vector<Course::Coordinate> &coordinates)
{
    std::vector<std::shared_ptr<Course::TileBase>> vec;

    for(int i=0; i<coordinates.size(); i++){
        vec.push_back(this->getTile(coordinates.at((long long)i)));
    }
    return vec;

}

std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getAllTiles()
{
    return tiles;

}

int ObjectManager::getNumberOfFreeTiles()
{
    int count = 0;
    foreach(auto tile, tiles){
        auto buildings = tile->getBuildings();
        if(buildings.size() < 1){
            count++;
        }
    }
    return count;
}
