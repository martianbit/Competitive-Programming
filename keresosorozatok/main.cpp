#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
using namespace std;
const ll INF = (1LL << 62);
int main() {
    FastIO;
    bool ok;
    ll i, j, lo, hi, K, H, S1, S2;
    cin >> K;
    for(i = 0; i < K; i++) {
        cin >> H;
        ok = true;
        lo = -INF;
        hi = INF;
        S1 = -1;
        for(j = 0; j < H; j++) {
            cin >> S2;
            if(!ok)
                continue;
            if(S1 != -1) {
                if(S2 < lo || S2 > hi || S1 == S2) {
                    ok = false;
                    continue;
                }
                if(S1 < S2)
                    lo = max(lo, S1 + 1);
                else
                    hi = min(hi, S1 - 1);
            }
            S1 = S2;
        }
        cout << (ok ? "IGEN" : "NEM") << '\n';
    }
    return 0;
}

