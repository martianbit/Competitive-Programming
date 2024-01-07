#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;
const ll INF = ~(1LL << 63);
ll N, M, K;
bool walk(ll node, ll C, vector<vector<array<ll, 2>>> &G) {
    ll i;
    unordered_set<ll> vis(N);
    vector<array<ll, 2>> best(N + 1, { -1, -1 });
    queue<array<ll, 3>> q;
    q.push({ node, K, 0 });
    while(!q.empty()) {
        array<ll, 3> cs = q.front();
        q.pop();
        vis.insert(cs[0]);
        if(vis.size() == N)
            return true;
        if(best[cs[0]][0] != -1 && (best[cs[0]][0] > cs[1] || (best[cs[0]][0] == cs[1] && best[cs[0]][1] >= cs[2])))
            continue;
        best[cs[0]][0] = cs[1];
        best[cs[0]][1] = cs[2];
        for(const auto &x : G[cs[0]]) {
            if(x[1] <= cs[2])
                q.push({ x[0], cs[1], cs[2] - x[1] });
            else if(x[1] <= C && cs[1] > 0)
                q.push({ x[0], cs[1] - 1, C - x[1] });
        }
    }
    return vis.size() == N;
}
int main() {
    FastIO;
    ll i, n1, n2, C, bsmin, bsmax;
    cin >> N >> M >> K;
    vector<vector<array<ll, 2>>> G(N + 1);
    bsmin = INF;
    bsmax = 0;
    for(i = 0; i < M; i++) {
        cin >> n1 >> n2 >> C;
        G[n1].push_back({ n2, C });
        G[n2].push_back({ n1, C });
        bsmin = min(C, bsmin);
        bsmax += C;
    }
    while(bsmin != bsmax - 1) {
        C = bsmin + (bsmax - bsmin) / 2;
        for(i = 1; i <= N; i++) {
            if(!walk(i, C, G)) {
                bsmin = C;
                goto next;
            }
        }
        bsmax = C;
        next:;
    }
    cout << bsmax << '\n';
    return 0;
}

