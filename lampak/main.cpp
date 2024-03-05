#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
bool is_binomial_odd(ll n, ll k) {
    if(!k)
        return true;
    if((1 - n & 1) && (k & 1))
        return false;
    return is_binomial_odd(n / 2, k / 2);
}
int main() {
    FastIO;
    ll i, ans, N, K, Q, P, S;
    cin >> N >> K >> Q;
    vector<ll> D(N + 1);
    D[1] = 0;
    for(i = 2; i <= N; i++) {
        cin >> P;
        D[i] = D[P] + 1;
    }
    while(Q--) {
        cin >> ans;
        for(i = 2; i <= N; i++) {
            cin >> S;
            if(S && is_binomial_odd(D[i] + K - 1, D[i]))
                ans ^= 1;
        }
        cout << ans << '\n';
    }
    return 0;
}

