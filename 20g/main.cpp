#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
int main() {
    FastIO;
    ll i, m, N, Q;
    cin >> N >> Q;
    vector<ll> T(N);
    for(i = 0; i < N; i++)
        cin >> T[i];
    map<ll, vector<ll>> M;
    for(i = 0; i < Q; i++) {
        cin >> m;
        if(M.find(m) == M.end())
            M.insert({ m, {} });
        M[m].push_back(i);
    }
    vector<ll> ans(Q, N);
    auto it = M.begin();
    for(i = 0; i < N && it != M.end(); i++) {
        auto b = M.lower_bound(T[i]);
        while((b == M.end() && it != M.end()) || it->first < b->first) {
            for(const auto &x : it->second)
                ans[x] = i + 1;
            it++;
        }
    }
    for(const auto &x : ans)
        cout << x << '\n';
    return 0;
}

