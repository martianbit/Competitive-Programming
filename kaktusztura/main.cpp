#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
using namespace std;
typedef enum {
    UNVISITED,
    EXPLORED,
    VISITED
} VState;
typedef struct {
    ll vertex;
    ll parent;
    ll weight;
    ll clockwise;
} CycleExits;
typedef struct {
    ll entry;
    ll total_w;
    vector<ll> members;
    vector<CycleExits> exits;
} Cycle;
ll find_cycles(ll vertex, ll parent, vector<Cycle> &cycles, vector<VState> &states, const vector<vector<array<ll, 2>>> &AL) {
    ll r, result;
    if(states[vertex] == EXPLORED) {
        cycles.emplace_back();
        cycles.back().entry = vertex;
        return cycles.size();
    }
    if(states[vertex] == VISITED)
        return 0;
    result = 0;
    states[vertex] = EXPLORED;
    for(const auto &x : AL[vertex]) {
        if(x[0] == parent)
            continue;
        r = find_cycles(x[0], vertex, cycles, states, AL);
        if(r && cycles[r - 1].entry != vertex) {
            cycles[r - 1].members.push_back(vertex);
            result = r;
        }
    }
    states[vertex] = VISITED;
    return result;
}
ll solve(ll vertex, bool complete, ll parent, const vector<Cycle> &cycles, const vector<ll> &cid, const vector<vector<array<ll, 2>>> &AL, vector<array<ll, 2>> &dp) {
    ll full;
    auto &ans = dp[vertex][complete];
    if(ans != -1)
        return ans;
    full = 0;
    if(cid[vertex] == -1) {
        for(const auto &x : AL[vertex]) {
            if(x[0] != parent)
                full += 2 * x[1] + solve(x[0], true, vertex, cycles, cid, AL, dp);
        }
        ans = full;
        if(!complete) {
            for(const auto &x : AL[vertex]) {
                if(x[0] != parent)
                    ans = min(ans, full - x[1] - solve(x[0], true, vertex, cycles, cid, AL, dp) + solve(x[0], false, vertex, cycles, cid, AL, dp));
            }
        }
    }
    else {
        for(const auto &x : cycles[cid[vertex]].exits) {
            if(x.vertex != parent)
                full += 2 * x.weight + solve(x.vertex, true, x.parent, cycles, cid, AL, dp);
        }
        ans = cycles[cid[vertex]].total_w + full;
        if(!complete) {
            for(const auto &x : cycles[cid[vertex]].exits) {
                if(x.vertex != parent)
                    ans = min(ans, full - x.weight - solve(x.vertex, true, x.parent, cycles, cid, AL, dp) + solve(x.vertex, false, x.parent, cycles, cid, AL, dp) + 2 * min(x.clockwise, cycles[cid[vertex]].total_w - x.clockwise) + max(x.clockwise, cycles[cid[vertex]].total_w - x.clockwise));
            }
        }
    }
    return ans;
}
int main() {
    FastIO;
    ll i, u, v, w, N, M;
    cin >> N >> M;
    vector<vector<array<ll, 2>>> AL(N + 1);
    for(i = 0; i < M; i++) {
        cin >> u >> v >> w;
        AL[u].push_back({ v, w });
        AL[v].push_back({ u, w });
    }
    vector<Cycle> cycles;
    vector<VState> states(N + 1, UNVISITED);
    find_cycles(1, -1, cycles, states, AL);
    vector<ll> cid(N + 1, -1);
    for(i = 0; i < cycles.size(); i++) {
        cid[cycles[i].entry] = i;
        for(const auto &x : cycles[i].members)
            cid[x] = i;
    }
    for(auto &x : cycles) {
        stack<array<ll, 2>> st;
        st.push({ x.entry, -1 });
        while(!st.empty()) {
            auto [vertex, parent] = st.top();
            st.pop();
            for(const auto &y : AL[vertex]) {
                if(cid[y[0]] == cid[x.entry])
                    continue;
                x.exits.emplace_back();
                x.exits.back().vertex = y[0];
                x.exits.back().parent = vertex;
                x.exits.back().weight = y[1];
                x.exits.back().clockwise = x.total_w;
            }
            for(const auto &y : AL[vertex]) {
                if(y[0] == parent || cid[y[0]] != cid[x.entry])
                    continue;
                x.total_w += y[1];
                if(y[0] != x.entry)
                    st.push({ y[0], vertex });
                if(parent == -1)
                    break;
            }
        }
    }
    vector<array<ll, 2>> dp(N + 1, { -1, -1 });
    cout << solve(1, false, -1, cycles, cid, AL, dp) << '\n';
    return 0;
}

