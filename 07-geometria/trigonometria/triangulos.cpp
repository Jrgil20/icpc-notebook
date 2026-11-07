// Triangulos: lados a,b,c (c opuesto a C)
// Requiere: reales/funciones_seguras.cpp
ld angleFromSides(ld a, ld b, ld c){ return safeAcos((a*a + b*b - c*c) / (2*a*b)); } // angulo C
ld sideFromAngle(ld a, ld b, ld C){ return safeSqrt(a*a + b*b - 2*a*b*cosl(C)); }   // lado c
ld heron(ld a, ld b, ld c){ ld s = (a + b + c) / 2; return safeSqrt(s * (s-a) * (s-b) * (s-c)); }
ld areaSAS(ld a, ld b, ld C){ return a * b * sinl(C) / 2; }
// ley de senos: a / sin(A) = b / sin(B) = c / sin(C) = 2R  (R = radio circunscrito)
