#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
void bfs(vector<ll> &mind, const ll sv, const vector<vector<ll>> &graph) {
    queue<array<ll, 2>> q;
    q.push({ sv, 0 });
    while(!q.empty()) {
        auto [v, d] = q.front();
        q.pop();
        if(mind[v] != -1)
            continue;
        mind[v] = d;
        for(const auto &x : graph[v])
            q.push({ x, d + 1 });
    }
}
int main() {
    FastIO;
    ll i, u, v, ans1, N, M, A, B;
    cin >> N >> M >> A >> B;
    vector<vector<ll>> graph(N + 1);
    for(i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<ll> minda(N + 1, -1);
    vector<ll> mindb(N + 1, -1);
    bfs(minda, A, graph);
    bfs(mindb, B, graph);
    ans1 = 0;
    vector<bool> ans2(N + 1);
    array<ll, 2> cntr = { 0, 0 };
    for(i = 1; i <= N; i++) {
        ans1 += min(minda[i], mindb[i]);
        ans2[i] = (minda[i] < mindb[i]);
        cntr[minda[i] < mindb[i]]++;
    }
    vector<array<ll, 2>> diffs;
    for(i = 1; i <= N; i++) {
        if(ans2[i] == max_element(all(cntr)) - cntr.begin())
            diffs.push_back({ abs(minda[i] - mindb[i]), i });
    }
    sort(all(diffs));
    for(i = 0; i < abs(cntr[0] - cntr[1]) / 2; i++) {
        ans1 += diffs[i][0];
        ans2[diffs[i][1]] = !ans2[diffs[i][1]];
    }
    cout << ans1 << '\n';
    for(i = 1; i <= N; i++)
        cout << (ans2[i] ? 'A' : 'B');
    cout << '\n';
    return 0;
}

