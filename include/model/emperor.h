//
// Created by pbarbeira on 31-12-2023.
//

#ifndef NIBURU_OPTIMIZER_EMPEROR_H
#define NIBURU_OPTIMIZER_EMPEROR_H

#include <map>
#include "building.h"
#include "research.h"
#include "combat-unit.h";

class Emperor{
    std::map<std::string, Building> buildings;
    std::map<std::string, Research> researches;
    std::map<std::string, CombatUnit> defenses;
    std::map<std::string, CombatUnit> weapons;

public:

};

#endif //NIBURU_OPTIMIZER_EMPEROR_H
