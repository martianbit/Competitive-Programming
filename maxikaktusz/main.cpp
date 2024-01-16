#include <bits/stdc++.h>
#define HANDLE_STREAK \
    if(streak >= 3) { \
        ans++; \
        streak = 0; \
    }
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
ll remove_cycles(ll vertex, ll parent, vector<bool> &bad_nodes, vector<bool> &vis, const vector<vector<ll>> &graph) {
    ll detected, result;
    if(vis[vertex]) {
        bad_nodes[vertex] = true;
        return vertex;
    }
    vis[vertex] = true;
    result = 0;
    for(const auto &x : graph[vertex]) {
        if(x == parent || bad_nodes[x])
            continue;
        detected = remove_cycles(x, vertex, bad_nodes, vis, graph);
        if(detected) {
            bad_nodes[vertex] = true;
            if(detected != vertex)
                result = detected;
        }
    }
    return result;
}
ll dfs(ll vertex, ll streak, ll &ans, vector<bool> &vis, const vector<vector<ll>> &graph) {
    ll rem;
    vis[vertex] = true;
    vector<ll> nbs;
    for(const auto &x : graph[vertex]) {
        if(!vis[x])
            nbs.push_back(x);
    }
    if(nbs.empty()) {
        HANDLE_STREAK;
        return streak;
    }
    else if(nbs.size() == 1) {
        HANDLE_STREAK;
        return dfs(nbs[0], streak + 1, ans, vis, graph);
    }
    else if(nbs.size() >= 2) {
        vector<ll> rs;
        for(const auto &x : nbs) {
            rem = dfs(x, 1, ans, vis, graph);
            if(rem)
                rs.push_back(rem);
        }
        if(rs.empty()) {
            HANDLE_STREAK;
            return streak;
        }
        else if(rs.size() == 1) {
            HANDLE_STREAK;
            ans += (streak + rs[0]) / 3;
            return (streak + rs[0]) % 3;
        }
        else if(rs.size() >= 2) {
            ans++;
            return streak - 1;
        }
    }
    return streak;
}
int main() {
    FastIO;
    ll i, u, v, ans, N, M;
    cin >> N >> M;
    vector<vector<ll>> graph(N + 1);
    for(i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> vis(N + 1, false);
    vector<bool> bad_nodes(N + 1, false);
    remove_cycles(1, -1, bad_nodes, vis, graph);
    ans = 0;
    for(i = 1; i <= N; i++) {
        if(!bad_nodes[i])
            dfs(i, 1, ans, bad_nodes, graph);
    }
    cout << ans << '\n';
    return 0;
}

