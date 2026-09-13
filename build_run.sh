#!/bin/bash
gcc -o src/VaultCell src/CELL.c src/Pass.c src/Bcell.c src/SIL/SIL.c -Isrc/include
./src/VaultCell-Term
