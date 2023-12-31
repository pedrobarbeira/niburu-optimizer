//
// Created by pbarbeira on 29-12-2023.
//

#ifndef NIBURU_OPTIMIZER_COMBAT_UNIT_H
#define NIBURU_OPTIMIZER_COMBAT_UNIT_H

#include<iostream>
#include<vector>

struct resource_t{
    int metal;
    int crystal;
    int deut;

    resource_t() {
        this->metal = 0;
        this->crystal = 0;
        this->deut = 0;
    }

    resource_t(int metal, int crystal, int deut) {
        this->metal = metal;
        this->crystal = crystal;
        this->deut = deut;
    }

    [[nodiscard]] int toResourcePoints() const {
        return this->metal + this->crystal + this->deut;
    }
};

struct weapon_t{
    int laser;
    int ion;
    int plasma;
    int gravitons;

    weapon_t() {
        this->laser = 0;
        this->ion = 0;
        this->plasma = 0;
        this->gravitons = 0;
    }

    weapon_t(int laser, int ion, int plasma, int gravitons) {
        this->laser = laser;
        this->ion = ion;
        this->plasma = plasma;
        this->gravitons = gravitons;
    }

    [[nodiscard]] int totalWeapons() const{
        return this->laser + this->ion + this->plasma + this->gravitons;
    }
};

struct defense_t{
    int armor;
    int shield;

    defense_t() {
        this->armor = 0;
        this->shield = 0;
    }

    defense_t(int armor, int shield) {
        this->armor = armor;
        this->shield = shield;
    }
};

class CombatUnit{
private:
    std::string name;
    int quantity;
    resource_t* cost;
    weapon_t* weapons;
    defense_t* defenses;
    int resourceCost;
protected:
    CombatUnit(const std::string& name, resource_t* cost, weapon_t* weapons, defense_t* defenses) {
        this->name = name;
        this->quantity = 1;
        this->cost = cost;
        this->weapons = weapons;
        this->defenses = defenses;
        this->resourceCost = toResourcePoints();
    }
public:

    int toResourcePoints() {
        return this->cost->toResourcePoints();
    }

    void setQuantity(int newQuantity){
        this->quantity = newQuantity;
    }

    resource_t* getCost(){
        return this->cost;
    }

    weapon_t* getWeapons(){
        return this->weapons;
    }

    defense_t* getDefenses(){
        return this->defenses;
    }

    double resourcePointsPerQuantity(){
        return this->quantity * this->toResourcePoints();
    }

    resource_t* resourcePerQuantity(){
        int metal = this->quantity * this->cost->metal;
        int crystal = this->quantity * this->cost->crystal;
        int deut = this->quantity * this->cost->deut;
        //TODO change to smart pointers to avoid messes
        return new resource_t(metal, crystal, deut);
    }

    weapon_t* weaponsPerQuantity(){
        int laser = this->quantity * this->weapons->laser;
        int ion = this->quantity * this->weapons->ion;
        int plasma = this->quantity * this->weapons->plasma;
        int gravitons = this->quantity * this->weapons->gravitons;
        //TODO change to smart poitners to avoid messes
        return new weapon_t(laser, ion, plasma, gravitons);
    }

    defense_t* defensesPerQuantity(){
        int armor = this->quantity * this->defenses->armor;
        int shield = this->quantity * this->defenses->shield;
        //TODO change to smart poitners to avoid messes
        return new defense_t(armor, shield);
    }

    friend std::ostream& operator<<(std::ostream& os, const CombatUnit& unit){
        os << "Unit Name: " << unit.name
        << "\nMetal: " << unit.cost->metal
        << "\nCrystal: " << unit.cost->crystal
        << "\nDeuterium: " << unit.cost->deut
        << "\nLaser: " << unit.weapons->laser
        << "\nIon: " << unit.weapons->ion
        << "\nPlasma: " << unit.weapons->plasma
        << "\nGraviton: " << unit.weapons->gravitons
        << "\nArmor: " << unit.defenses->armor
        << "\nShields: " << unit.defenses->shield;
        return os;
    }
};

std::vector<CombatUnit*> loadDefenses();
std::vector<CombatUnit*> loadFleet();

#endif //NIBURU_OPTIMIZER_COMBAT_UNIT_H
