#include <bits/stdc++.h>
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const ll D4[][2] = {{ -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 }};
int main() {
    FastIO;
    ll i, j, k, u, v, ans, N, M, K;
    cin >> N >> M >> K;
    vector<vector<ll>> graph(N * M + 1);
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            for(k = 0; k < 4; k++)
                graph[i * M + j + 1].push_back(MOD(i + D4[k][1], N) * M + MOD(j + D4[k][0], M) + 1);
        }
    }
    while(K--) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        ans = -1;
        for(i = 1; i <= N * M; i++) {
            vector<bool> vis(N * M + 1, false);
            queue<array<ll, 2>> q;
            q.push({ i, 0 });
            while(!q.empty()) {
                auto [cv, d] = q.front();
                q.pop();
                if(vis[cv])
                    continue;
                vis[cv] = true;
                ans = max(ans, d);
                for(const auto &x : graph[cv])
                    q.push({ x, d + 1 });
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

