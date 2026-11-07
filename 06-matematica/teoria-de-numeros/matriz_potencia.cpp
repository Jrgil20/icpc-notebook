// Exponenciacion de matrices (recurrencias lineales: Fibonacci, etc.)
typedef vector<vector<ll>> Mat;
Mat mul(const Mat& A, const Mat& B, ll m){ int n = A.size(), k = B.size(), p = B[0].size(); Mat C(n, vector<ll>(p, 0));
    for (int i = 0; i < n; i++) for (int l = 0; l < k; l++) if (A[i][l]) for (int j = 0; j < p; j++) C[i][j] = (C[i][j] + A[i][l] * B[l][j]) % m;
    return C; }
Mat matpow(Mat A, ll e, ll m){ int n = A.size(); Mat R(n, vector<ll>(n, 0)); for (int i = 0; i < n; i++) R[i][i] = 1 % m;
    while (e){ if (e & 1) R = mul(R, A, m); A = mul(A, A, m); e >>= 1; } return R; }
ll fib(ll n, ll m){ if (n == 0) return 0; Mat F = {{1, 1}, {1, 0}}; return matpow(F, n - 1, m)[0][0]; } // F(1)=F(2)=1
