#include <bits/stdc++.h>
#define MOD ((ll) (1e9 + 7))
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
using namespace std;
int main() {
    FastIO;
    ll i, j, T, ans;
    cin >> T;
    vector<ll> N(T);
    vector<ll> K(T);
    vector<vector<array<ll, 2>>> ranges(T);
    for(i = 0; i < T; i++) {
        cin >> N[i] >> K[i];
        ranges[i].resize(K[i]);
        for(j = 0; j < K[i]; j++) {
            cin >> ranges[i][j][0] >> ranges[i][j][1];
            ranges[i][j][0]--;
        }
    }
    for(i = 0; i < T; i++) {
        vector<vector<ll>> graph(N[i] + 1);
        for(j = 0; j < K[i]; j++) {
            graph[ranges[i][j][0]].push_back(ranges[i][j][1]);
            graph[ranges[i][j][1]].push_back(ranges[i][j][0]);
        }
        vector<ll> colors(N[i] + 1, 0);
        ans = 0;
        for(j = 0; j <= N[i]; j++) {
            if(colors[j])
                continue;
            stack<array<ll, 2>> st;
            st.push({ j, colors[j] = 1 });
            while(!st.empty()) {
                auto [box, color] = st.top();
                st.pop();
                for(const auto &x : graph[box]) {
                    if(!colors[x])
                        st.push({ x, colors[x] = 3 - color });
                    else if(colors[x] == color) {
                        cout << "0\n";
                        goto next;
                    }
                }
            }
            ans = ans ? ((ans * 2) % MOD) : 1;
        }
        cout << ans << '\n';
        next:;
    }
    return 0;
}

