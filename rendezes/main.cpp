#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
int main() {
    FastIO;
    ll i, j, fr, active, ans, N, M;
    cin >> N >> M;
    vector<ll> seq(N);
    for(i = 0; i < N; i++)
        cin >> seq[i];
    vector<array<ll, 2>> ranges(M);
    for(i = 0; i < M; i++) {
        cin >> ranges[i][0] >> ranges[i][1];
        ranges[i][0]--;
    }
    vector<array<ll, 2>> eps(N + 1, { 0, 0 });
    for(i = 0; i < M; i++) {
        for(j = 0; j < 2; j++)
            eps[ranges[i][j]][j]++;
    }
    fr = active = 0;
    for(i = 0; i <= N; i++) {
        active -= eps[i][1];
        if(!active && fr != -1) {
            sort(seq.begin() + fr, seq.begin() + i);
            fr = -1;
        }
        active += eps[i][0];
        if(active && fr == -1)
            fr = i;
    }
    ans = 0;
    for(i = 0; i < N; i++)
        ans += (seq[i] == i + 1);
    cout << ans << '\n';
    return 0;
}

