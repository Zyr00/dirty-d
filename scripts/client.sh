#!/usr/bin/env bash

printf "\n\nBUILD CLIENT\n\n"
cmake --build build --target client

printf "\n\nRUNNING CLIENT\n\n"
./build/src/client/client
