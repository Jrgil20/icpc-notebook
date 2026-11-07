// Probabilidad como fraccion mod p: P/Q mod p = P * Q^(p-2) mod p
// Requiere: aritmetica-modular/mulmod_int128.cpp y const ll MD (plantilla base)
ll fracMod(ll P, ll Q){ return mulmod(P % MD, powmod(Q, MD - 2, MD), MD); }
