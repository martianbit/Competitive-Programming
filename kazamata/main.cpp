#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
int main() {
    FastIO;
    ll i, until, ans, N;
    cin >> N;
    vector<ll> rooms(N);
    for(i = 0; i < N; i++)
        cin >> rooms[i];
    vector<bool> keys(N, false);
    until = 0;
    ans = -1;
    while(until < N) {
        ans++;
        for(i = 0; i <= until; i++)
            keys[(rooms[i] + ans) % N] = true;
        while(keys[until])
            keys[(rooms[++until] + ans) % N] = true;
    }
    cout << ans << '\n';
    return 0;
}

