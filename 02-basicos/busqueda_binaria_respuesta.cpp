// Busqueda binaria sobre la respuesta: menor x en [lo,hi] con ok(x)=true (ok monotona F..FT..T)
template<class F> ll firstTrue(ll lo, ll hi, F ok){ while (lo < hi){ ll mid = lo + (hi - lo) / 2; if (ok(mid)) hi = mid; else lo = mid + 1; } return lo; }
