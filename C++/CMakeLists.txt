cmake_minimum_required(VERSION 3.12)
project(Cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(Lab1/Critter)
include_directories(Lab1/Critter2)
include_directories(Lab2/a3p1)
include_directories(Lab2/a3p2)
include_directories(Lab2/a3p3)
include_directories(Lab2/a3p4)
include_directories(Lab2/a3p6)
include_directories(Lab2/a4p1)
include_directories(Lab2/a4p3)
include_directories(Lab2/a4p4)
include_directories(Lab2/a4p5)
include_directories(Lab2/a4p6)
include_directories("Lab2/Vector not working/a4p6")
include_directories(Lab3/a5p1)
include_directories(Lab3/a5p2)
include_directories(Lab3/a5p5)

add_executable(Cpp
        Lab1/Critter/Critter.cpp
        Lab1/Critter/Critter.h
        Lab1/Critter/testcritter.cpp
        Lab1/Critter2/Critter.cpp
        Lab1/Critter2/Critter.h
        Lab1/Critter2/testcritter.cpp
        Lab1/a1p1.cpp
        Lab1/a1p2.cpp
        Lab1/a1p3.cpp
        Lab1/a1p4.cpp
        Lab1/a1p5.cpp
        Lab1/a1p6.cpp
        Lab1/a2p1.cpp
        Lab1/a2p2.cpp
        Lab1/a2p3.cpp
        Lab1/a2p4.cpp
        Lab1/a2p5.cpp
        Lab1/a2p6.cpp
        Lab2/a3p1/City.cpp
        Lab2/a3p1/City.h
        Lab2/a3p1/testcity.cpp
        Lab2/a3p2/Critter.cpp
        Lab2/a3p2/Critter.h
        Lab2/a3p2/testcritter.cpp
        Lab2/a3p3/Critter.cpp
        Lab2/a3p3/Critter.h
        Lab2/a3p3/testcritter.cpp
        Lab2/a3p4/Critter.cpp
        Lab2/a3p4/Critter.h
        Lab2/a3p4/testcritter.cpp
        Lab2/a3p5/copyconstructor.cpp
        Lab2/a3p6/Complex.cpp
        Lab2/a3p6/Complex.h
        Lab2/a3p6/testcomplex.cpp
        Lab2/a4p1/Box.cpp
        Lab2/a4p1/Box.h
        Lab2/a4p1/testbox.cpp
        Lab2/a4p2/creature.cpp
        Lab2/a4p3/Creature.cpp
        Lab2/a4p3/Creature.h
        Lab2/a4p3/testcreature.cpp
        Lab2/a4p4/Creature.cpp
        Lab2/a4p4/Creature.h
        Lab2/a4p4/testcreature.cpp
        Lab2/a4p5/Shapes.cpp
        Lab2/a4p5/Shapes.h
        Lab2/a4p5/testshapes.cpp
        Lab2/a4p6/testvector.cpp
        Lab2/a4p6/Vector.cpp
        Lab2/a4p6/Vector.h
        "Lab2/Vector not working/a4p6/testvector.cpp"
        "Lab2/Vector not working/a4p6/Vector.cpp"
        "Lab2/Vector not working/a4p6/Vector.h"
        Lab3/a5p1/Shapes.cpp
        Lab3/a5p1/Shapes.h
        Lab3/a5p1/testHexgon.cpp
        Lab3/a5p2/testTournamentMember.cpp
        Lab3/a5p2/TournamentMember.cpp
        Lab3/a5p2/TournamentMember.h
        Lab3/a5p5/fraction.cpp
        Lab3/a5p5/fraction.h
        Lab3/a5p5/testfraction.cpp)
