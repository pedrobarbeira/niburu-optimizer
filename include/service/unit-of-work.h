//
// Created by pbarbeira on 31-12-2023.
//

#ifndef NIBURU_OPTIMIZER_UNIT_OF_WORK_H
#define NIBURU_OPTIMIZER_UNIT_OF_WORK_H

#include <vector>
#include "../model/combat-unit.h"

class UnitOfWork{
private:
    std::vector<CombatUnit*> defenses;
    std::vector<CombatUnit*> fleet;

public:
    UnitOfWork(){
        this->defenses.clear();
        this->fleet.clear();
    }

    void load(){
        this->defenses = loadDefenses();
        this->fleet = loadFleet();
    }
};

#endif //NIBURU_OPTIMIZER_UNIT_OF_WORK_H
