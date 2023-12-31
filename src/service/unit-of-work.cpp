//
// Created by pbarbeira on 31-12-2023.
//

#include "../../include/service/unit-of-work.h"

std::vector<CombatUnit*> UnitOfWork::load_defenses(){
    sqlite3* dbCtx = sql::getDb();
    sql::select_stmt stmt("defense");
    sql::execute(dbCtx, stmt);
    return {};
}

std::vector<CombatUnit*> UnitOfWork::load_fleet(){

}


