// Base b: digitos y palindromo
vector<ll> toBase(ll n, ll b){ vector<ll> d; if (n == 0) d.push_back(0); while (n){ d.push_back(n % b); n /= b; } reverse(d.begin(), d.end()); return d; }
bool isPal(const vector<ll>& d){ for (size_t i = 0, j = d.size() - 1; i < j; i++, j--) if (d[i] != d[j]) return false; return true; }
