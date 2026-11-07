#!/bin/bash
# Uso: ./t6_stress.sh   (necesita A.cpp compilado como ./A, brute.py y gen.py en esta carpeta)
for i in $(seq 1 500); do
  python3 gen.py $i > in.txt
  ./A < in.txt > o1.txt; python3 brute.py < in.txt > o2.txt
  if ! cmp -s o1.txt o2.txt; then echo "FALLA"; cat in.txt; break; fi
done
