//
// Created by pbarbeira on 31-12-2023.
//

#ifndef NIBURU_OPTIMIZER_UNIT_OF_WORK_H
#define NIBURU_OPTIMIZER_UNIT_OF_WORK_H

#include <vector>
#include "../combat-unit/defense-unit/defense.h"

class UnitOfWork{
private:
    std::vector<CombatUnit*> defenses;
    std::vector<CombatUnit*> fleet;

    void loadDefenses(){

    }

    void loadFleet(){

    }

public:
    UnitOfWork(){
        this->defenses.clear();
        this->fleet.clear();
    }

    void load(){
        this->loadDefenses();
        this->loadFleet();
    }
};

#endif //NIBURU_OPTIMIZER_UNIT_OF_WORK_H
