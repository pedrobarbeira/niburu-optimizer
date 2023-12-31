//
// Created by pbarbeira on 31-12-2023.
//

#ifndef NIBURU_OPTIMIZER_UNIT_OF_WORK_H
#define NIBURU_OPTIMIZER_UNIT_OF_WORK_H

#include <vector>
#include "../model/combat-unit.h"
#include "sql/table.h";

class UnitOfWork{
private:
    Table<CombatUnit> defenses;
    Table<CombatUnit> fleet;

public:
    UnitOfWork(){
        this->defenses = Table<CombatUnit>("defenses");
        this->fleet = Table<CombatUnit>("fleet");
    }

    void load(){
        this->defenses.load();
        this->fleet.load();
    }
};

#endif //NIBURU_OPTIMIZER_UNIT_OF_WORK_H
