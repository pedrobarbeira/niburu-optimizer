//
// Created by pbarbeira on 29-12-2023.
//

#ifndef NIBURU_OPTIMIZER_LEPTON_CANNON_H
#define NIBURU_OPTIMIZER_LEPTON_CANNON_H

#include "../combat-unit.h"

struct lepton_t{
    int METAL_COST = 9000000;
    int CRYSTAL_COST = 4500000;
    int DEUTERIUM_COST = 1350000;

    int LASER_DMG = 200000 + 100000;
    int ION_DMG = 0;
    int PLASMA_DMG = 0;
    int GRAVITON_DMG = 200000 + 80000;

    int ARMOR = 1500000;
    int SHIELD = 500000;
    std::string NAME = "Lepton Cannon";
};

class LeptonCannon : public CombatUnit{
private:
public:
    LeptonCannon(const std::string& name, resource_t* cost, weapon_t* weapons, defense_t* defenses)
        :CombatUnit(name, cost, weapons, defenses){
    }
};


#endif //NIBURU_OPTIMIZER_LEPTON_CANNON_H
