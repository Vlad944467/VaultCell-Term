#!/bin/bash
gcc -o bin/VaultCell src/main.c src/Pass.c src/Bcell.c src/SIL/SIL.c -Isrc/include
./bin/VaultCell
