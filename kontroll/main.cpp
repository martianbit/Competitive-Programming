#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
bool dfs(ll vertex, ll &ans1, vector<ll> &root, vector<ll> &down, vector<ll> &up, vector<ll> &pid, vector<bool> &vis, const vector<vector<ll>> &DAG) {
    ll i;
    if(vertex == DAG.size() - 1) {
        ans1++;
        return true;
    }
    if(vis[vertex])
        return false;
    vis[vertex] = true;
    for(i = 0; i < DAG[vertex].size(); i++) {
        if(!dfs(DAG[vertex][i], ans1, root, down, up, pid, vis, DAG))
            continue;
        up[DAG[vertex][i]] = vertex;
        if(vertex == 1)
            root[ans1 - 1] = DAG[vertex][i];
        else {
            down[vertex] = i;
            pid[vertex] = ans1;
            return true;
        }
    }
    return false;
}
int main() {
    FastIO;
    ll i, j, n, v, cand, ans1, N;
    cin >> N;
    vector<vector<ll>> DAG(N + 1);
    for(i = 1; i < N; i++) {
        cin >> n;
        DAG[i].resize(n);
        for(j = 0; j < n; j++)
            cin >> DAG[i][j];
    }
    ans1 = 0;
    vector<bool> vis(N + 1, false);
    vector<ll> root(N + 1);
    vector<ll> down(N + 1);
    vector<ll> up(N + 1);
    vector<ll> pid(N + 1, 0);
    dfs(1, ans1, root, down, up, pid, vis, DAG);
    vector<ll> ans2(ans1);
    for(i = ans1 - 1; i >= 0; i--) {
        if(i != ans1 - 1) {
            v = ans2[i + 1];
            while(v != 1 && !down[v])
                v = up[v];
            if(v != 1) {
                cand = DAG[v][down[v] - 1];
                while(pid[cand] != i + 1)
                    cand = DAG[cand].back();
                ans2[i] = cand;
                continue;
            }
        }
        cand = root[i];
        while(DAG[cand][down[cand]] != N) {
            if(down[cand] != DAG[cand].size() - 1) {
                v = cand;
                while(v != N && !pid[DAG[v].back()])
                    v = DAG[v].back();
                if(v == N || pid[DAG[v].back()] != pid[cand])
                    break;
            }
            cand = DAG[cand][down[cand]];
        }
        ans2[i] = cand;
    }
    cout << ans1 << '\n';
    for(const auto &x : ans2)
        cout << x << ' ';
    cout << '\n';
    return 0;
}

