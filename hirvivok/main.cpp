#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
const int INF = (1 << 30);
int main() {
    FastIO;
    int i, j, d, v, lo, hi, mid, groups, N, M, H, K;
    cin >> N >> M >> H >> K;
    vector<array<int, 2>> agents(H);
    for(i = 0; i < H; i++) {
        cin >> agents[i][1] >> agents[i][0];
        agents[i][0]--;
        agents[i][1]--;
    }
    vector<vector<array<int, 2>>> md(H, vector<array<int, 2>>(H));
    for(i = 0; i < H; i++) {
        for(j = i; j < H; j++) {
            d = abs(agents[i][0] - agents[j][0]) + abs(agents[i][1] - agents[j][1]);
            md[i][j] = { d, j };
            md[j][i] = { d, i };
        }
    }
    for(i = 0; i < H; i++)
        sort(all(md[i]));
    lo = -1;
    hi = N + M - 1;
    while(lo + 1 < hi) {
        mid = (lo + hi) / 2;
        vector<vector<int>> graph(H);
        for(i = 0; i < H; i++) {
            array<int, 2> search = { mid, INF };
            auto b = upper_bound(all(md[i]), search);
            for(auto it = md[i].begin(); it != b; it++)
                graph[i].push_back((*it)[1]);
        }
        groups = 0;
        vector<bool> vis(H, false);
        for(i = 0; i < H; i++) {
            if(vis[i])
                continue;
            groups++;
            stack<int> st;
            st.push(i);
            while(!st.empty()) {
                v = st.top();
                st.pop();
                if(vis[v])
                    continue;
                vis[v] = true;
                for(const auto &x : graph[v])
                    st.push(x);
            }
        }
        if(groups <= K)
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << '\n';
    return 0;
}

