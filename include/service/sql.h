//
// Created by pbarbeira on 31-12-2023.
//

#ifndef NIBURU_OPTIMIZER_SQL_H
#define NIBURU_OPTIMIZER_SQL_H

#include <utility>
#include <vector>
#include <sqlite3.h>
#include <sstream>
#include "sql-statement.h"

namespace sql{
    static statement_t STATEMENTS;
    static std::string dbName = "../test.db";
    sqlite3* db = nullptr;

    void open(const char* name){
        int rc;
        rc = sqlite3_open(name, &db);
        if( rc ) {
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        } else {
            fprintf(stderr, "Opened database successfully\n");
        }
    }

    sqlite3* getDb(){
        if(db == nullptr){
            open(dbName.c_str());
        }
        return db;
    }

    static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
        int i;
        for(i = 0; i<argc; i++) {
            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        }
        printf("\n");
        return 0;
    }

    void execute_statement(sqlite3* dbCtx, const std::string& sql){
        char* zErrMsg = nullptr;
        int rc = sqlite3_exec(dbCtx, sql.c_str(), callback, nullptr, &zErrMsg);

        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } else {
            fprintf(stdout, "%s\n", sql.c_str());
        }
    }

    void execute_statement(sqlite3* dbCtx, const std::string& sql, const std::string& data){
        char* zErrMsg = nullptr;
        int rc = sqlite3_exec(dbCtx, sql.c_str(), callback, (void*)data.c_str(), &zErrMsg);

        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        } else {
            fprintf(stdout, "%s\n", sql.c_str());
        }
    }

    void insert_params(std::stringstream& ss, const std::vector<params_t*>& params){
        open_bracket(ss);
        for(auto data : params){
            ss << data->name << " " << data->type << " " << data->properties;
            if(data != *(params.end() - 1)){
                ss << ", ";
            }
        }
        close_bracket(ss);
    }

    void create_table(sqlite3 *dbCtx, const create_stmt& stmt){
        std::stringstream ss;
        ss << STATEMENTS.CREATE << " " << stmt.name;
        insert_params(ss, stmt.params);
        execute_statement(dbCtx, ss.str());
    }

    void insert_columns(std::stringstream& ss, const std::vector<std::string>& columns){
        open_bracket(ss);
        insert_strings(ss, columns, ",");
        close_bracket(ss, " ");
    }

    void insert_values(std::stringstream& ss, const std::vector<std::string>& values){
        open_bracket(ss, "VALUES");
        insert_strings(ss, values, ",");
        close_bracket(ss, ";");
    }

    void insert_into(sqlite3 *dbCtx, const insert_stmt& stmt){
        std::stringstream ss;
        ss << STATEMENTS.INSERT << " " << stmt.name << " ";
        insert_columns(ss, stmt.columns);
        insert_values(ss, stmt.values);
        execute_statement(dbCtx, ss.str());
    }

    void select_from_table(sqlite3* dbCtx){
        std::string sql = "SELECT * from COMPANY";
        std::string data = "Callback function called";
        execute_statement(dbCtx, sql, data);
    }

    void update_table(sqlite3* dbCtx){
        std::string sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1; " \
         "SELECT * from COMPANY";
        std::string data = "Callback function called";
        execute_statement(dbCtx, sql, data);
    }

    void delete_from_table(sqlite3* dbCtx){
        std::string sql = "DELETE from COMPANY where ID=2; " \
         "SELECT * from COMPANY";
        std::string data = "Callback function called";
        execute_statement(db, sql, data);
    }

    void clear_table(sqlite3* dbCtx){
        std::string sql = "DELETE from COMPANY";
        std::string data = "Callback function called";
        execute_statement(dbCtx, sql, data);
    }

    void drop_table(sqlite3* dbCtx, std::string name){
        std::stringstream ss;
        ss << STATEMENTS.DROP << " " << name << ";";
        std::string data = "Callback function called";
        execute_statement(dbCtx, ss.str(), data);
    }

    void execute(sqlite3* dbCtx, const create_stmt& stmt){
        create_table(dbCtx, stmt);
    }

    void execute(sqlite3* dbCtx, const insert_stmt& stmt){
        insert_into(dbCtx, stmt);
    }

    void execute(sqlite3* dbCtx, const stmt_t& stmt){
        drop_table(dbCtx, stmt.name);
    }

    void select_from(sqlite3* dbCtx, const std::string& name){
        std::stringstream ss;
        std::string data = "Callback function called";
        ss << STATEMENTS.SELECT << " * FROM " << name << ";";
        execute_statement(dbCtx, ss.str(), data);
    }

    void select_values_from(sqlite3* dbCtx, const select_stmt& stmt){
        std::stringstream ss;
        std::string data = "Callback function called";
        ss << STATEMENTS.SELECT << " * FROM " << stmt.name << ";";
        execute_statement(dbCtx, ss.str(), data);
    }

    void select_values_where(sqlite3* dbCtx, const select_stmt& stmt){
        std::stringstream ss;
        std::string data = "Callback function called";
        ss << STATEMENTS.SELECT << " * FROM " << stmt.name << ";";
        execute_statement(dbCtx, ss.str(), data);
    }

    void insert_where(std::stringstream& ss, std::vector<std::string> conditions){
        open_bracket(ss, "WHERE");
        insert_strings(ss, std::move(conditions), ", ");
        close_bracket(ss, ":");
    }

    void select_where(sqlite3* dbCtx, const select_stmt& stmt){
        std::stringstream ss;
        std::string data = "Callback function called";
        ss << STATEMENTS.SELECT << " * FROM " << stmt.name;
        insert_where(ss, stmt.conditions);
        execute_statement(dbCtx, ss.str(), data);
    }

    void execute(sqlite3* dbCtx, const select_stmt& stmt){
        if(!stmt.values.empty() && !stmt.conditions.empty()){
            return select_values_where(dbCtx, stmt);
        }
        if(!stmt.values.empty()){
            select_values_from(dbCtx, stmt);
        }
        if(!stmt.conditions.empty()){
            select_where(dbCtx, stmt);
        }

        return select_from(dbCtx, stmt.name);
    }
}

#endif //NIBURU_OPTIMIZER_SQL_H
