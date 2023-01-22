#!/bin/bash
g++ -isystem googletest/googletest/include -I googletest/googletest -pthread -c googletest/googletest/src/gtest-all.cc

ar -rv libtest.a gtest-all.o

g++ -isystem googletest/googletest/include -pthread mytests.cpp ../src/Game.cpp ../src/Player.cpp ../src/Ball.cpp ../src/Board.cpp libtest.a -o test -lsfml-graphics -lsfml-window -lsfml-system

./test