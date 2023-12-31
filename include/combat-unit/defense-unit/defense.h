//
// Created by pbarbeira on 29-12-2023.
//

#ifndef NIBURU_OPTIMIZER_DEFENSE_H
#define NIBURU_OPTIMIZER_DEFENSE_H

#include "lepton-cannon.h"

class DefenseFactory{
private:
    lepton_t lepton;

public:
    DefenseFactory(){
        this->lepton = lepton_t();
    }

    CombatUnit build(const std::string& unitName){
        resource_t* resource = buildResources(lepton);
        weapon_t* weapons = buildWeapons(lepton);
        defense_t* defenses = buildDefenses(lepton);
        return LeptonCannon(lepton.NAME, resource, weapons, defenses);
    }

    resource_t* buildResources(lepton_t lepton){
        return new resource_t(lepton.METAL_COST, lepton.CRYSTAL_COST, lepton.DEUTERIUM_COST);
    }

    weapon_t* buildWeapons(lepton_t lepton){
        return new weapon_t(lepton.LASER_DMG, lepton.ION_DMG, lepton.PLASMA_DMG, lepton.GRAVITON_DMG);
    }

    defense_t* buildDefenses(lepton_t lepton){
        return new defense_t(lepton.ARMOR, lepton.SHIELD);
    }
};

#endif //NIBURU_OPTIMIZER_DEFENSE_H
