#include <bits/stdc++.h>
#define MAX_V ((ll) 4e5)
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
using namespace std;
int main() {
    FastIO;
    ll i, cntr, ans, N, K, V;
    cin >> N;
    vector<array<ll, 2>> calls(MAX_V + 1, { 0, 0 });
    while(N--) {
        cin >> K >> V;
        calls[K][0]++;
        calls[V][1]++;
    }
    ans = cntr = 0;
    for(i = 1; i <= MAX_V; i++) {
        cntr += calls[i][0];
        ans = max(ans, cntr);
        cntr -= calls[i][1];
    }
    cout << ans << '\n';
    return 0;
}

