//
// Created by pbarbeira on 31-12-2023.
//

#ifndef NIBURU_OPTIMIZER_SQL_STATEMENT_H
#define NIBURU_OPTIMIZER_SQL_STATEMENT_H

namespace sql{
    struct statement_t{
        std::string CREATE = "CREATE TABLE";
        std::string INSERT = "INSERT INTO";
        std::string SELECT = "SELECT";
        std::string UPDATE = "UPDATE";
        std::string DELETE = "DELETE FROM";
        std::string DROP = "DROP TABLE";
    };

    struct params_t{
        std::string name;
        std::string type;
        std::string properties;
    };

    struct stmt_t{
        std::string name;

        stmt_t(std::string name){
            this->name = name;
        }
    };

    struct create_stmt : public stmt_t{
        std::vector<params_t*> params;

        create_stmt(const std::string& name,
                    const std::vector<params_t*>& params
        ) : stmt_t(name){
            this->params = params;
        }
    };

    struct insert_stmt : public stmt_t{
        std::vector<std::string> columns;
        std::vector<std::string> values;

        insert_stmt(const std::string& target,
                    const std::vector<std::string>& columns,
                    const std::vector<std::string>& values
            ) : stmt_t(target){
            this->columns = columns;
            this->values = values;
        }
    };

    struct select_stmt : public stmt_t{
        std::vector<std::string> values;

        select_stmt(std::string name, std::vector<std::string> values)
            : stmt_t(std::move(name)){
            this-> values = std::move(values);
        }

        explicit select_stmt(std::string name) : select_stmt(std::move(name), {}){}
    };

    void insert_strings(std::stringstream& ss, std::vector<std::string> strings, const std::string& separator){
        for(const auto& str : strings){
            ss << str;
            if(str != *(strings.end() - 1)){
                ss << separator;
            }
        }
    }

    void open_bracket(std::stringstream& ss, std::string prefix){
        ss << prefix << "(";
    }

    void open_bracket(std::stringstream& ss){
        open_bracket(ss, "");
    }

    void close_bracket(std::stringstream& ss, const std::string& suffix){
        ss << ")" << suffix;
    }

    void close_bracket(std::stringstream& ss){
        close_bracket(ss, "");
    }
}

#endif //NIBURU_OPTIMIZER_SQL_STATEMENT_H
