#!/bin/bash

if [ -d "build" ]
then
    rm -r build && rm -r lib && rm r-type_*
    mkdir build && cd build && conan install .. --build=missing && cmake .. -G "Unix Makefiles" && cmake --build . && mv bin/* ../
else
    mkdir build && cd build && conan install .. --build=missing && cmake .. -G "Unix Makefiles" && cmake --build . && mv bin/* ../
fi