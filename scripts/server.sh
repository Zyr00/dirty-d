#!/usr/bin/env bash

printf "\n\nBUILD SERVER\n\n"
cmake --build build --target server

printf "\n\nRUNNING SERVER\n\n"
./build/src/server/server
