cmake_minimum_required(VERSION 3.25)
project(niburu_optimizer)

set(CMAKE_CXX_STANDARD 23)

find_package(SQLite3 REQUIRED)

add_executable(niburu_optimizer main.cpp include/model/combat-unit.h include/combat-unit/defense-unit/photon-cannon.h src/combat-unit/defense-unit/lepton-cannon.cpp include/combat-unit/defense-unit/lepton-cannon.h include/combat-unit/defense-unit/defense.h include/service/unit-of-work.h src/service/unit-of-work.cpp include/service/sql.h include/service/sql-statement.h include/service/cache.h include/model/emperor.h include/model/building.h include/model/research.h include/official.h)

target_link_libraries(niburu_optimizer SQLite::SQLite3)
