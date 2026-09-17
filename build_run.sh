#!/bin/bash
mkdir -p bin
gcc -o bin/VaultCell src/CELL.c src/Pass.c src/Bcell.c src/SIL/SIL.c -Isrc/include
./bin/VaultCell