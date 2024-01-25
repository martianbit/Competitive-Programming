#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
const int INF = (1 << 30);
int main() {
    FastIO;
    int i, u, v, d, na, ans, N, M, L;
    cin >> N >> M >> L;
    L--;
    vector<vector<array<int, 2>>> graph(N);
    for(i = 0; i < M; i++) {
        cin >> u >> v >> d;
        graph[u - 1].push_back({ v - 1, d });
        graph[v - 1].push_back({ u - 1, d });
    }
    vector<vector<pair<int, vector<int>>>> apsp(N, vector<pair<int, vector<int>>>(N));
    for(i = 0; i < N; i++) {
        vector<bool> vis(N, false);
        priority_queue<tuple<int, int, vector<int>>> q;
        q.push({ 0, i, {} });
        while(!q.empty()) {
            auto [dist, vertex, pth] = q.top();
            q.pop();
            if(vis[vertex])
                continue;
            vis[vertex] = true;
            pth.push_back(vertex);
            apsp[i][vertex] = { -dist, pth };
            for(const auto &x : graph[vertex])
                q.push({ dist - x[1], x[0], pth });
        }
    }
    ans = INF;
    vector<int> steps;
    stack<tuple<int, int, int, vector<int>>> st;
    st.push({ L, 0, 0, {} });
    while(!st.empty()) {
        auto [vertex, dist, vis, pth] = st.top();
        st.pop();
        vis |= (1 << vertex);
        pth.push_back(vertex);
        if(vis == (1 << N) - 1) {
            na = dist + apsp[vertex][L].first;
            if(na < ans) {
                ans = na;
                steps = pth;
            }
            continue;
        }
        for(i = 0; i < N; i++) {
            if(!(vis & (1 << i)))
                st.push({ i, dist + apsp[vertex][i].first, vis, pth });
        }
    }
    cout << ans << '\n';
    vector<bool> gvis(N, false);
    gvis[L] = true;
    for(i = 1; i < ((int) steps.size()); i++) {
        for(const auto &x : apsp[steps[i - 1]][steps[i]].second) {
            if(gvis[x])
                continue;
            cout << x + 1 << ' ';
            gvis[x] = true;
        }
    }
    cout << '\n';
    return 0;
}

