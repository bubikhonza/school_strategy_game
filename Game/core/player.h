#ifndef PLAYER_H
#define PLAYER_H
#include <core/playerbase.h>
#include <core/resourcemaps.h>

namespace Game{
class Player;
}
/**
 * @class Player
 * @brief The Player describe player in game
 * class inherit from PlayerBase
 * The class can be used to store and access GameObjects.
 * Expired weak pointers are automatically removed when requesting or removing
 * objects.
 *
 * @note Objects are stored as weak pointers.
 */
class Player:public Course::PlayerBase
{
public:
    /**
     * @brief Constructor for the class
     * @param name A std::string for player's name
     * @param objects (optional) A std::vector of shared-pointers to
     * GameObjects.
     */
    Player(const std::string& name,
           const std::vector<std::shared_ptr<Course::GameObject>> objects ={});
    Course::ResourceMap myResourceMap = {
        {Course::MONEY, 1000},
        {Course::FOOD, 1000},
        {Course::WOOD, 1000},
        {Course::STONE, 1000},
        {Course::ORE, 1000},
    };
    /**
     * @brief Returns final score of player
     */
    float getFinalScore();
    /**
     * @brief Increase players score
     * @param value we want to add
     */
    void addScore(double x);
    /**
     * @brief Increase players score
     * @param value we want to remove
     */
    void removeScore(double x);
    /**
     * @brief Returns maximum count of Leaders player
     * can currently have
     */
    int getLeaderMax();
    /**
     * @brief Increase maximum of leaders
     * that player can have
     */
    void increaseMaxLeaders();
    /**
     * @brief Returns how many Leaders player has
     */
    int getLeadersNum();
    /**
     * @brief Increase count of Leaders that
     *  player has
     * @param number we add to LeadersNum
     */
    void setLeadersNum(int n);

private:
    double score = 0;
    int leadersNum = 0;
    int leaderMax = 2;

};



#endif // PLAYER_H
