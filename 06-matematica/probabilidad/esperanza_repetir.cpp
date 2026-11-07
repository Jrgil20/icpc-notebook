// Requiere: reales/base_flotante.cpp (ld)
// Valor esperado con "repetir": E = (sum p_i * costo_i) / (1 - p_repetir)
// en cada intento: con prob pRep se repite gastando cRep; si no, termina gastando E_fin
ld expectedRetry(ld pRep, ld cRep, ld costFinalPromedio){ return (costFinalPromedio * (1 - pRep) + pRep * cRep) / (1 - pRep); }
