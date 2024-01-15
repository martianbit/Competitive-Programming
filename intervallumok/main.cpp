#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const ll INF = (1LL << 62);
int main() {
    FastIO;
    bool ok;
    ll i, j, ms, st, N;
    cin >> N;
    vector<ll> A(N);
    for(i = 0; i < N; i++)
        cin >> A[i];
    vector<pair<ll, vector<ll>>> ans;
    for(i = N; i > 1; i--) {
        if(N % i)
            continue;
        ms = -INF;
        for(j = 0; j < N; j += i)
            ms = max(ms, A[j + i - 1] - A[j]);
        ok = true;
        pair<ll, vector<ll>> na = { ms, {} };
        for(j = i - 1; j < N && ok; j += i) {
            st = max(na.second.empty() ? -INF : (na.second.back() + ms + 1), A[j] - ms);
            if(st > A[j - i + 1]) {
                ok = false;
                break;
            }
            na.second.push_back(st);
        }
        if(ok)
            ans.push_back(na);
    }
    cout << ans.size() << '\n';
    for(const auto &x : ans) {
        cout << x.second.size() << ' ' << x.first << '\n';
        for(const auto &y : x.second)
            cout << y << '\n';
    }
    return 0;
}

