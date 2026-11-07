#!/bin/bash
# Compila y corre todos los tests de plantillas (carpetas */tests/*.cpp) y los autotests de Python.
# Uso: ./scripts/probar_plantillas.sh
cd "$(dirname "$0")/.." || exit 1
fallos=0; tmp=$(mktemp -d)
for t in $(find . -path '*/tests/*.cpp' | sort); do
    if ! g++ -std=c++20 -O2 "$t" -o "$tmp/t" 2> "$tmp/err"; then
        echo "[NO COMPILA] $t"; head -20 "$tmp/err"; fallos=$((fallos + 1)); continue
    fi
    if out=$("$tmp/t" 2>&1); then echo "[OK] $t -> $out"; else echo "[FALLA] $t"; echo "$out"; fallos=$((fallos + 1)); fi
done
for p in 05-strings/rachas.py; do
    if out=$(python3 "$p" 2>&1); then echo "[OK] $p -> $out"; else echo "[FALLA] $p"; echo "$out"; fallos=$((fallos + 1)); fi
done
rm -rf "$tmp"
[ $fallos -eq 0 ] && echo "Todo correcto" || { echo "$fallos con fallas"; exit 1; }
