//
// Created by pbarbeira on 31-12-2023.
//

#ifndef NIBURU_OPTIMIZER_CACHE_H
#define NIBURU_OPTIMIZER_CACHE_H

#include <map>
#include <string>
#include "sql.h"

template<typename T>
class Table{
    std::map<std::string, T*> data;
    std::string name;

    T* _getById(const std::string& id){
        return nullptr;
    }

public:
    explicit Table(const std::string& name){
        this->name = name;
        data.clear();
    }

    T* get(std::string id){
        auto item = data.find(id);
        if(item == data.end()){
            return _getById(id);
        }
        return item;
    }
};

#endif //NIBURU_OPTIMIZER_CACHE_H
