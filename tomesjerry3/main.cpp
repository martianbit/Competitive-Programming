#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
typedef struct {
    ll md;
    ll depth;
    ll parent;
    vector<ll> children;
} Branch;
ll build_tree(ll vertex, ll parent, ll depth, vector<Branch> &tree, const vector<vector<ll>> &graph) {
    tree[vertex].md = depth;
    tree[vertex].depth = depth;
    tree[vertex].parent = parent;
    for(const auto &x : graph[vertex]) {
        if(x == parent)
            continue;
        tree[vertex].md = max(tree[vertex].md, build_tree(x, vertex, depth + 1, tree, graph));
        tree[vertex].children.push_back(x);
    }
    return tree[vertex].md;
}
bool does_tom_win(const ll J, const ll K, const vector<Branch> &tree) {
    ll rj;
    rj = J;
    while(rj != -1) {
        if(tree[J].depth - tree[rj].depth >= tree[rj].depth - 1)
            return true;
        if(tree[rj].depth + min(K - 1 - (tree[J].depth - tree[rj].depth), tree[rj].md - tree[rj].depth) > K)
            return false;
        rj = tree[rj].parent;
    }
    return true;
}
int main() {
    FastIO;
    bool ok;
    ll i, j, u, v, N, T, J, K, C;
    cin >> C;
    while(C--) {
        cin >> N >> T >> J >> K;
        vector<vector<ll>> graph(N + 1);
        for(i = 1; i < N; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<Branch> tree(N + 1);
        build_tree(T, -1, 0, tree, graph);
        ok = does_tom_win(J, K, tree);
        if(!ok) {
            u = 0;
            while(tree[++u].depth != tree[T].md);
            tree = vector<Branch>(N + 1);
            build_tree(u, -1, 0, tree, graph);
            v = 0;
            while(tree[++v].depth != tree[u].md);
            for(i = 0; i < tree[u].md / 2; i++)
                v = tree[v].parent;
            tree = vector<Branch>(N + 1);
            build_tree(v, -1, 0, tree, graph);
            ok = (tree[v].md <= K);
        }
        cout << (ok ? "IGEN" : "NEM") << '\n';
    }
    return 0;
}

