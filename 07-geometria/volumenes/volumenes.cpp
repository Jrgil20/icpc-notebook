// Volumenes y areas
// Requiere: reales/base_flotante.cpp
ld cone(ld r, ld h){ return PI * r * r * h / 3; }
ld frustum(ld r, ld R, ld h){ return PI * h * (R*R + r*r + R*r) / 3; }  // cono truncado
ld cylinder(ld r, ld h){ return PI * r * r * h; }
ld sphere(ld r){ return 4 * PI * r * r * r / 3; }
ld sphereArea(ld r){ return 4 * PI * r * r; }
ld cap(ld r, ld h){ return PI * h * h * (3 * r - h) / 3; }               // casquete de altura h
ld pyramid(ld baseArea, ld h){ return baseArea * h / 3; }
