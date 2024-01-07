#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
using namespace std;
const ll INF = ~(1LL << 63);
int main() {
    FastIO;
    ll i, N, M, capital, n1, n2, key;
    vector<ll> edge(2);
    queue<array<ll, 3>> q;
    cin >> N >> M >> capital;
    unordered_set<ll> ans(M);
    vector<vector<ll>> G(N + 1);
    vector<ll> dist(N + 1, INF);
    for(i = 0; i < M; i++) {
        cin >> n1 >> n2;
        G[n1].push_back(n2);
        G[n2].push_back(n1);
    }
    q.push({ capital, 0, 0 });
    while(!q.empty()) {
        array<ll, 3> cs = q.front();
        q.pop();
        if(dist[cs[0]] < cs[2])
            continue;
        dist[cs[0]] = cs[2];
        if(cs[1]) {
            edge[0] = cs[0];
            edge[1] = cs[1];
            sort(edge.begin(), edge.end());
            key = edge[0] | (edge[1] << 32);
            if(ans.find(key) != ans.end())
                continue;
            ans.insert(key);
        }
        for(const auto &x : G[cs[0]]) {
            if(dist[x] > cs[2])
                q.push({ x, cs[0], cs[2] + 1 });
        }
    }
    cout << ans.size() << '\n';
    for(const auto &x : ans)
        cout << (x & ((1LL << 32) - 1)) << ' ' << (x >> 32) << '\n';
    return 0;
}

