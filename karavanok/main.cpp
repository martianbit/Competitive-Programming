#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
using namespace std;
void dfs(ll vertex, vector<bool> &vis, stack<ll> &st, const vector<vector<ll>> &AL) {
    if(vis[vertex])
        return;
    vis[vertex] = true;
    for(const auto &x : AL[vertex])
        dfs(x, vis, st, AL);
    st.push(vertex);
}
int main() {
    FastIO;
    ll i, v, N, M, A, B;
    cin >> N >> M;
    vector<vector<ll>> AL(N + 1);
    vector<vector<ll>> AL_tp(N + 1);
    for(i = 0; i < M; i++) {
        cin >> A >> B;
        AL[A].push_back(B);
        AL_tp[B].push_back(A);
    }
    vector<bool> vis(N + 1);
    stack<ll> st;
    for(i = 1; i <= N; i++)
        dfs(i, vis, st, AL);
    fill(all(vis), false);
    vector<vector<ll>> SCCs;
    while(!st.empty()) {
        v = st.top();
        st.pop();
        if(vis[v])
            continue;
        SCCs.emplace_back();
        stack<ll> st2;
        st2.push(v);
        while(!st2.empty()) {
            v = st2.top();
            st2.pop();
            if(vis[v])
                continue;
            vis[v] = true;
            SCCs.back().push_back(v);
            for(const auto &x : AL_tp[v])
                st2.push(x);
        }
    }
    vector<ll> ids(N + 1);
    for(i = 0; i < SCCs.size(); i++) {
        for(const auto &x : SCCs[i])
            ids[x] = i;
    }
    vector<bool> good(SCCs.size(), true);
    for(const auto &x : SCCs) {
        for(const auto &y : x) {
            for(const auto &z : AL[y]) {
                if(ids[z] != ids[y])
                    good[ids[z]] = false;
            }
        }
    }
    for(i = 0; i < SCCs.size(); i++) {
        if(!good[i])
            continue;
        sort(all(SCCs[i]));
        for(const auto &x : SCCs[i])
            cout << x << ' ';
        cout << '\n';
        return 0;
    }
    cout << "-1\n";
    return 0;
}

