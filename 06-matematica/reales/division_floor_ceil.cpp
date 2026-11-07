// Division entera con negativos (floor/ceil reales)
ll floorDiv(ll a, ll b){ return a / b - ((a % b != 0) && ((a < 0) != (b < 0))); }
ll ceilDiv(ll a, ll b){ return a / b + ((a % b != 0) && ((a < 0) == (b < 0))); }
