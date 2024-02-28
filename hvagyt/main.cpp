#include <bits/stdc++.h>
#define ADD_EDGE(a, b) EL.push_back({ A[a] - 1 + N * !X[a], A[b] - 1 + N * X[b] })
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
using namespace std;
ll N;
bool solve_2SAT(vector<bool> &ans, const vector<array<ll, 2>> &EL) {
    ll i, u, v, cntr;
    vector<vector<ll>> AL(2 * N);
    vector<vector<ll>> AL_tp(2 * N);
    for(const auto &x : EL) {
        AL[x[0]].push_back(x[1]);
        AL_tp[x[1]].push_back(x[0]);
    }
    vector<bool> vis(2 * N, false);
    stack<ll> st;
    for(i = 0; i < 2 * N; i++) {
        if(vis[i])
            continue;
        stack<ll> st2;
        st2.push(i);
        while(!st2.empty()) {
            v = st2.top();
            st2.pop();
            if(vis[v])
                continue;
            vis[v] = true;
            st.push(v);
            for(const auto &x : AL[v])
                st2.push(x);
        }
    }
    cntr = 1;
    vector<ll> scc_ids(2 * N, 0);
    while(!st.empty()) {
        v = st.top();
        st.pop();
        if(scc_ids[v])
            continue;
        stack<ll> st2;
        st2.push(v);
        while(!st2.empty()) {
            u = st2.top();
            st2.pop();
            if(scc_ids[u])
                continue;
            scc_ids[u] = cntr;
            for(const auto &x : AL_tp[u])
                st2.push(x);
        }
        cntr++;
    }
    for(i = 0; i < N; i++) {
        if(scc_ids[i] == scc_ids[i + N])
            return false;
        ans[i] = (scc_ids[i] < scc_ids[i + N]);
    }
    return true;
}
int main() {
    FastIO;
    bool ok;
    ll i, j, T, M;
    array<ll, 3> A;
    array<bool, 3> X;
    string S;
    cin >> T;
    while(T--) {
        cin >> N >> M;
        vector<array<ll, 2>> EL;
        EL.reserve(6 * M);
        for(i = 0; i < M; i++) {
            for(j = 0; j < 3; j++) {
                cin >> A[j] >> S;
                X[j] = S == "H";
            }
            ADD_EDGE(0, 1);
            ADD_EDGE(1, 0);
            ADD_EDGE(0, 2);
            ADD_EDGE(2, 0);
            ADD_EDGE(1, 2);
            ADD_EDGE(2, 1);
        }
        vector<bool> ans(N);
        ok = solve_2SAT(ans, EL);
        if(ok) {
            for(const auto &x : ans)
                cout << (x ? 'H' : 'T') << ' ';
            cout << '\n';
        }
        else
            cout << "-1\n";
    }
    return 0;
}

