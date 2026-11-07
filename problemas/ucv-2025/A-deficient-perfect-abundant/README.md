# UCV-2025 A · Deficient, Perfect, Abundant

- **Concurso:** XXXI Contest UCV 2025 — enunciado en [`enunciados/ucv-2025.pdf`](../../../enunciados/ucv-2025.pdf)
- **Técnica:** Suma de divisores en O(√N)
- **Complejidad:** O(√N) por número probado
- **Plantilla relacionada:** [`06-matematica/teoria-de-numeros/divisores_suma.cpp`](../../../06-matematica/teoria-de-numeros/divisores_suma.cpp)
- **Solución:** [`dpa.cpp`](dpa.cpp)

## Idea

S(N) = sigma(N) - N, con sigma desde la factorizacion en O(sqrt N). El siguiente abundante esta cerca (todo multiplo de 6 mayor que 6 es abundante), asi que se prueba N+1, N+2, ... a lo sumo unos pocos.

## Probar

```bash
python3 scripts/probar_problemas.py ucv-2025/A-deficient-perfect-abundant
```

3 ejemplo(s) oficial(es) en [`ejemplos/`](ejemplos), todos correctos.
