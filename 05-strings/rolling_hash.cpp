// Rolling hash (mod 2^61-1, base aleatoria)
typedef unsigned long long ull;
const ull MOD = (1ULL << 61) - 1;
ull mulmod(ull a, ull b){ __uint128_t c = (__uint128_t)a * b; ull r = (ull)(c & MOD) + (ull)(c >> 61); return r >= MOD ? r - MOD : r; }
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
const ull BASE = rng64() % (MOD - 1000) + 500;
struct Hash {
    vector<ull> h, pw;
    Hash(const string& s) : h(s.size() + 1, 0), pw(s.size() + 1, 1) {
        for (size_t i = 0; i < s.size(); i++){
            h[i+1] = (mulmod(h[i], BASE) + (ull)s[i]) % MOD; pw[i+1] = mulmod(pw[i], BASE); } }
    ull get(int l, int r){ // hash de s[l..r) (r exclusivo)
        return (h[r] + MOD - mulmod(h[l], pw[r - l])) % MOD; }
};
