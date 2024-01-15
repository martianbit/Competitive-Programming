#include <bits/stdc++.h>
#include <bits/extc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ost;
ost dfs(ll vertex, vector<bool> &states, const vector<vector<ll>> &tree) {
    bool si;
    ost signals;
    for(const auto &x : tree[vertex]) {
        auto ns = dfs(x, states, tree);
        for(const auto &y : ns)
            signals.insert(y);
    }
    si = (states[vertex] + signals.order_of_key(vertex)) % 2;
    states[vertex] = (states[vertex] + signals.size()) % 2;
    if(si)
        signals.insert(vertex);
    return signals;
}
int main() {
    FastIO;
    ll i, u, s, N, K, Q;
    cin >> N >> K >> Q;
    vector<vector<ll>> tree(N);
    for(i = 1; i < N; i++) {
        cin >> u;
        tree[u - 1].push_back(i);
    }
    vector<bool> states(N);
    while(Q--) {
        for(i = 0; i < N; i++) {
            cin >> s;
            states[i] = s;
        }
        for(i = 0; i < K; i++)
            dfs(0, states, tree);
        cout << states[0] << '\n';
    }
    return 0;
}

