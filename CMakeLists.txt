cmake_minimum_required(VERSION 3.25)
project(niburu_optimizer)

set(CMAKE_CXX_STANDARD 23)

find_package(SQLite3 REQUIRED)

add_executable(niburu_optimizer main.cpp include/model/combat-unit.h include/service/unit-of-work.h src/service/unit-of-work.cpp include/service/unit-of-work/sql.h include/service/unit-of-work/sql-statement.h include/service/unit-of-work/table.h include/model/emperor.h include/model/building.h include/model/research.h src/model/combat-unit.cpp src/model/combat-unit.cpp)

target_link_libraries(niburu_optimizer SQLite::SQLite3)
