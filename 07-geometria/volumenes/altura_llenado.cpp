// Altura de llenado de una taza (cono truncado, r abajo, R arriba) hasta fraccion f
// Requiere: volumenes/volumenes.cpp, reales/busqueda_binaria_real.cpp
ld fillHeight(ld r, ld R, ld h, ld f){
    auto vol = [&](ld y){ ld ry = r + (R - r) * y / h; return frustum(r, ry, y); };
    return bsReal(0, h, f * vol(h), vol); }
