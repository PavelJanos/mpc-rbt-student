#!/bin/bash

# Přesun do složky projektu
cd "$(dirname "$0")"

# Smazání staré build složky a vytvoření nové
rm -rf build
mkdir build
cd build

# Spuštění CMake a Make
cmake ..
make
