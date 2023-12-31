#include <iostream>
#include <cmath>
#include <sqlite3.h>

#include "include/service/sql.h"

std::string str_from_ch(char* str){
	int size;
	for(size = 0; str[size] != '\0'; size++);
	return std::string(str, size);
}

int contains(std::string str, char ch){
	for(int i = 0 ; i < str.size(); i++){
		if(str[i] == ch){
			return i;
		}
	}
	return 0;
}

double int_from_str(std::string str, int size){
	double total = 0;
	int value;
	for(int i = 0; i < size; i++){
		value = str[i] - '0';
		total = total * 10 + value;
	}
	return total;
}

double float_from_str(std::string str, int pointIndex){
	double total = 0;
	double value;
	for(int i = pointIndex + 1; i < str.size(); i++){
		int exp = i - pointIndex;
		value = (str[i] - '0') * pow(10, -exp);
		total += value;
	}
	return total;
}

double double_from_str(std::string str){
	int pointIndex = contains(str, '.');

	if(pointIndex){
		double intPart = int_from_str(str, pointIndex);
		double floatPart = float_from_str(str, pointIndex);
		return intPart + floatPart;
	}else{
		return int_from_str(str, str.size());
	}
}

int usage_display(){
	std::cout << "Usage: ./nibot <price-a> <price-b> <capital> <flag>"
		<< std::endl;
	
	return 1;
}

int invalid_flag_display(){
	std::cout << "Invalid flag"
		<< "\n<flag>: -a|-b"
		<< std::endl;
	return 1;
}

bool invalid_flag(std::string arg){
    return arg != "-a" || arg != "-b";
}

int main(int argc, char* argv[]){
    sqlite3 *db = sql::getDb();
    sql::stmt_t dropStmt(
        "test"
    );

    sql::execute(db, dropStmt);

    auto param1 = new sql::params_t("param1", "int", "primary key not null");
    auto param2 = new sql::params_t("param2", "text", "not null");
    auto param3 = new sql::params_t("param3", "real", "not null");
    sql::create_stmt createStmt(
        "test",
        {param1, param2, param3}
    );
    sql::execute(db, createStmt);

    sql::insert_stmt insertStmt(
        "test",
        {"param1", "param2", "param3"},
        {"1, \"this is a test\", 3.141592"}
    );
    sql::execute(db, insertStmt);

    sql::select_stmt selectStmt(
        "test"
    );
    sql::execute(db, selectStmt);

    if(db != nullptr){
        sqlite3_close(db);
    }

	return 0;
}
