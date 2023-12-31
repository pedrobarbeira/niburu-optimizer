# Nibiru Optimizer

This is a personal project aimed at solving the operational investigation problem posed by the online browser strategy game "Ogame". For this particular project, the context used was that of "Niburu Space", a private server which contains custom elements and units.

The vision is to develop a tool which allows the user to quickly access certain mathematically optimal solutions for his situations - for example, which would be the mathematically optimized fleet configuration to keep losses under a given bound during a fight against a given opponent. What would be the expected profit? How do two opponents compare numerically? 

These types of problems are the ones one faces while playing the game above introductory skill-level. Having got back to playing said classic, I found the idea  of developing a playing assistant in C++ - the legendary "macro-tool" I heard about in the recesses of Ogame's official foruns back in 2008 - quite the interesting engineering challenge - both programatically, due to the low-level nature of C++, and mathematically, due to the high degree of dimensions some of the problems reach.


In this game, users have planets. Each planet is capable of producing 4 types of resource:
* Metal
* Crystal
* Deuterium
* Energy

These resources are produced by the mines, which require energy to function. Energy can be produced through the Solar Power Plant, the Deuterium Power Plant and the Solar Satellites. There are also modifications to the rate of production of these resources - more on that later. Mines are the only buildings that consume energy.

Players in the game can use these resources to build defense units, as well as ships. These Combat Units have specific costs, deal specific types of damage, and have specific structural integrity and shield values. They also have the "RapidFire" property, which is particularly relevant for combat. Resources can also be used to research technologies, which in turn alter several modifieres - production speed, damage, resource production, etc.

Fleets can attack planets. These attacks take a certain amount of time, depending on fleet characteristics. In fact, time is of the essence in this game. Every action has a set amount of time that the system takes to acknowledge it. This makes this game a very interesting optimization playground, involving problems of both operational investigation and scheduling.

Lastly, players can own several planets, which can communicate - send resources and even ships - with each other. These secondary planets are also able to produce ships and resources, although they can't research technologies in parallel - but they do reduce the research time. There are also some server-specific systems we'll explore, if possible.

## Instalation
Compile and run. Will add a proper Makefile as soon as possible.

The system automatically creates a sqlite3 database with constant value tlempates.

## Documentation

### Fleet Calculator

```
    $ nibot calc <metal> <crystal> <deuterium> -f|-d <-t>
```
This command produces a table of how many CombatUnits of any given type you can produce using the input amount of resources. The flags can be used to restrict calculations to fleet (-f) or defense (-d) units. Option <-t> outputs the expected time to produce each set of units. This is the tool's most basic use case.