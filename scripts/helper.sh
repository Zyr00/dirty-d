#!/usr/bin/env bash

# CONFIGURE CMAKE WITH NINJA
printf "\n\nCONFIGURE CMAKE WITH NINJA\n\n"
cmake -S . -B build -GNinja

# BUILD ALL
printf "\n\nBUILDING ALL PROJECTS\n\n"
cmake --build build
