#include "player.h"
#include "core/playerbase.h"
#include "QDebug"
#include <math.h>
#include <tiles/tilebase.h>

Player::Player(const std::string& name,
               const std::vector<std::shared_ptr<Course::GameObject>> objects):Course::PlayerBase(name,objects)
{
}

float Player::getFinalScore()
{
    auto objects = getObjects();
    int points = 0;
    std::vector<std::shared_ptr<Course::BuildingBase>> buildings;
    foreach(auto o, objects){
        std::shared_ptr<Course::TileBase> tile = std::dynamic_pointer_cast<Course::TileBase>(o);
        auto bs = tile->getBuildings();
        foreach(auto b, bs){
           buildings.push_back(b);
        }
    }

    foreach(auto o, buildings){
        if(o->getType() == "Farm"){
            points += 1;
        }
        if(o->getType() == "Sawmill"){
            points += 1;
        }
        if(o->getType() == "Mine"){
            points += 1;
        }
        if(o->getType() == "Fortress"){
            points += 3;
        }
    }
    return points + this->score;
}

void Player::addScore(double x)
{
    this->score += x;
}

void Player::removeScore(double x)
{
    this->score -= x;
}

int Player::getLeaderMax()
{
    return this->leaderMax;
}

void Player::increaseMaxLeaders()
{
    this->leaderMax++;
}

int Player::getLeadersNum()
{
    return this->leadersNum;
}

void Player::setLeadersNum(int n)
{
    this->leadersNum += n;
}
