#!/bin/sh
set -e

# собрать, если ещё не собран
[ -x ./sil ] || ./build_run.sh

# 2 — выбрать "to run", 1 — подтвердить файл programm.siv
printf '2\n1\n' | ./sil