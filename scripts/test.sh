#!/bin/bash
mkdir ../build
cd ../build
cmake ..
make
cd tests
ctest
