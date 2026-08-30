#!/bin/bash
gcc -o src/VaultCell src/CELL.c src/Pass.c src/Bcell.c -Isrc/include
./src/VaultCell
