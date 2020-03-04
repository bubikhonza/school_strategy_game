#ifndef MYRESOURCEMAPS_H
#define MYRESOURCEMAPS_H

#include "core/basicresources.h"

using namespace Course;
namespace Game{
const ResourceMap EMPTY = {};

// Building - Farm


const ResourceMap DESERT_BP = {
    {MONEY, 3},
    {FOOD, 1},
    {WOOD, 1},
    {STONE, 3},
    {ORE, 1},
};

const ResourceMap MOUNTAINS_BP = {
    {MONEY, 1},
    {FOOD, 2},
    {WOOD, 2},
    {STONE, 4},
    {ORE, 4},
};
const ResourceMap SWAMP_BP = {
    {MONEY, 2},
    {FOOD, 1},
    {WOOD, 2},
    {STONE, 3},
    {ORE, 3},
};

// Worker - EngineerWorker
const ResourceMapDouble EW_WORKER_EFFICIENCY = {
    {MONEY, 1.25},
    {FOOD, 0.25},
    {WOOD, 0.25},
    {STONE, 0.25},
    {ORE, 1.00}
};
// Worker - EngineerWorker RECRUITMENT
const ResourceMap EW_RECRUITMENT_COST = {
    {MONEY, 20},
    {FOOD, 40}
};
// Worker - Leader
const ResourceMapDouble LEADER_EFFICIENCY = {
    {MONEY, 3.0},
    {FOOD, 3.0},
    {WOOD, 3.00},
    {STONE, 3.0},
    {ORE, 3.00}
};
// Worker - Leader RECRUITMENT
const ResourceMap LEADER_RECRUITMENT_COST = {
    {MONEY, 40},
    {FOOD, 30}
};
// Worker - FarmerWorker
//NOT USED
const ResourceMapDouble FW_WORKER_EFFICIENCY = {
    {MONEY, 0.50},
    {FOOD, 1.50},
    {WOOD, 0.75},
    {STONE, 0.25},
    {ORE, 0.25}
};
// Worker - Leader RECRUITMENT
const ResourceMap FW_RECRUITMENT_COST = {
    {MONEY, 30},
    {FOOD, 35}
};
// Aristocrat
const ResourceMapDouble ARISTOCRAT_WORKER_EFFICIENCY = {
    {MONEY, 0.00},
    {FOOD, 0.00},
    {WOOD, 0.00},
    {STONE, 0.00},
    {ORE, 0.0}
};
// Worker - Aristocrat RECRUITMENT
const ResourceMap ARISTOCRAT_RECRUITMENT_COST = {
    {MONEY, 200},
    {FOOD, 60}
};
// Building - Mine
const ResourceMap MINE_BUILD_COST = {
    {BasicResource::MONEY, 300},
    {BasicResource::FOOD, 200},
    {BasicResource::WOOD, 200},
    {BasicResource::STONE, 200}
};

const ResourceMap MINE_PRODUCTION = {
    {BasicResource::MONEY, 4},
    {BasicResource::FOOD, 0},
    {BasicResource::STONE, 4},
    {BasicResource::ORE, 2}
};
// Building - Sawmill
const ResourceMap SAWMILL_BUILD_COST = {
    {BasicResource::MONEY, 100},
    {BasicResource::FOOD, 200},
    {BasicResource::WOOD, 200},
    {BasicResource::STONE, 200}
};

const ResourceMap SAWMILL_PRODUCTION = {
    {BasicResource::MONEY, 3},
    {BasicResource::WOOD, 5}
};

// Building - Fortress
const ResourceMap FORTRESS_BUILD_COST = {
    {BasicResource::MONEY, 1500},
    {BasicResource::FOOD, 900},
    {BasicResource::WOOD, 2000},
    {BasicResource::STONE, 3000},
    {BasicResource::ORE, 2500}
};

const ResourceMap FORTRESS_PRODUCTION = {
    {BasicResource::MONEY, 5},
    {BasicResource::WOOD, 0}
};
}



#endif // RESOURCEMAPS_H
