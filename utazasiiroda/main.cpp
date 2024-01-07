#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
using namespace std;
ll dfs(ll v, ll lst, vector<ll> &ccs, const vector<set<ll>> &tree) {
    for(const auto &x : tree[v]) {
        if(x != lst)
            ccs[v] += dfs(x, v, ccs, tree);
    }
    return ccs[v];
}
int main() {
    FastIO;
    ll i, u, v, sn, N, K;
    cin >> N >> K;
    vector<set<ll>> tree(N + 1);
    for(i = 1; i < N; i++) {
        cin >> u >> v;
        tree[u].insert(v);
        tree[v].insert(u);
    }
    sn = (K / N) + 1;
    K %= N;
    vector<ll> ccs(N + 1, 1);
    dfs(sn, 0, ccs, tree);
    u = 0;
    stack<ll> st;
    st.push(sn);
    while(!st.empty() && K) {
        v = st.top();
        st.pop();
        cout << v << ' ';
        K--;
        if(!K)
            break;
        for(const auto &x : tree[v]) {
            if(x == u)
                continue;
            if(K > ccs[x])
                K -= ccs[x];
            else {
                st.push(x);
                break;
            }
        }
        u = v;
    }
    cout << '\n';
    return 0;
}

