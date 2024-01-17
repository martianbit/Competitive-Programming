#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
int main() {
    FastIO;
    ll i, ans, N, P;
    cin >> N >> P;
    vector<ll> prices(N);
    for(i = 0; i < N; i++)
        cin >> prices[i];
    vector<ll> acc(N);
    acc[0] = prices[0];
    for(i = 1; i < N; i++)
        acc[i] = acc[i - 1] + prices[i];
    if(P >= acc.back()) {
        cout << N << '\n';
        return 0;
    }
    ans = 0;
    for(i = 0; i < N; i++)
        ans = max(ans, i - (lower_bound(all(acc), acc[i] - P) - acc.begin()));
    cout << ans << '\n';
    return 0;
}

