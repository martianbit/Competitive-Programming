#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const ll INF = (1LL << 62);
ll dfs(ll vertex, ll depth, ll &ans1, vector<vector<ll>> &ds, const vector<vector<ll>> &tree) {
    ll cc;
    cc = 1;
    ds[depth].push_back(vertex);
    for(const auto &x : tree[vertex])
        cc += dfs(x, depth + 1, ans1, ds, tree);
    ans1 = min(ans1, depth + cc);
    return cc;
}
int main() {
    FastIO;
    ll i, v, ans1, N;
    cin >> N;
    vector<vector<ll>> tree(N + 1);
    for(i = 2; i <= N; i++) {
        cin >> v;
        tree[v].push_back(i);
    }
    ans1 = INF;
    vector<vector<ll>> ds(N);
    dfs(1, 0, ans1, ds, tree);
    vector<ll> ans2(N + 1);
    for(i = 0; i < N; i++) {
        for(const auto &x : ds[i])
            ans2[x] = max(ans1 - i, 1LL);
    }
    cout << ans1 << '\n';
    for(i = 1; i <= N; i++)
        cout << ans2[i] << ' ';
    cout << '\n';
    return 0;
}

