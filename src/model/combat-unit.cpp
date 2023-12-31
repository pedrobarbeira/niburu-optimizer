//
// Created by pbarbeira on 31-12-2023.
//

#include "../../include/model/combat-unit.h"
#include "../../include/service/unit-of-work/sql.h"

std::vector<CombatUnit*> loadDefenses(){
    sqlite3* dbCtx = sql::getDb();
    sql::select_stmt stmt("defense");
    sql::execute(dbCtx, stmt);
    return {};
}

std::vector<CombatUnit*> loadFleet(){

}