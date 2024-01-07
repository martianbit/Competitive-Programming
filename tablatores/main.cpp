#include <bits/stdc++.h>
#define QUICK_SUM(x0, y0, x1, y1) \
    (acc[(y1) - 1][(x1) - 1] - \
    ((y0) ? acc[(y0) - 1][(x1) - 1] : 0) - \
    ((x0) ? acc[(y1) - 1][(x0) - 1] : 0) + \
    (((x0) && (y0)) ? acc[(y0) - 1][(x0) - 1] : 0))
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
using namespace std;
ll N, M;
ll solve(bool player, ll x0, ll y0, ll x1, ll y1, const vector<vector<ll>> &acc, vector<ll> &dp) {
    ll key;
    if(x0 == x1 || y0 == y1)
        return 0;
    key = y0 + y1 * N + x0 * N * (N + 1) + x1 * N * (N + 1) * M + player * N * (N + 1) * M * (M + 1);
    auto &ans = dp[key];
    if(ans != -1)
        return ans;
    array<ll, 4> opts;
    opts[0] = (player ? QUICK_SUM(x0, y0, x0 + 1, y1) : 0) + solve(!player, x0 + 1, y0, x1, y1, acc, dp);
    opts[1] = (player ? QUICK_SUM(x0, y0, x1, y0 + 1) : 0) + solve(!player, x0, y0 + 1, x1, y1, acc, dp);
    opts[2] = (player ? QUICK_SUM(x1 - 1, y0, x1, y1) : 0) + solve(!player, x0, y0, x1 - 1, y1, acc, dp);
    opts[3] = (player ? QUICK_SUM(x0, y1 - 1, x1, y1) : 0) + solve(!player, x0, y0, x1, y1 - 1, acc, dp);
    if(player)
        ans = *max_element(all(opts));
    else
        ans = *min_element(all(opts));
    return ans;
}
int main() {
    FastIO;
    ll i, j;
    cin >> N >> M;
    vector<vector<ll>> acc(N, vector<ll>(M));
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            cin >> acc[i][j];
            acc[i][j] += (i ? acc[i - 1][j] : 0) + (j ? acc[i][j - 1] : 0) - ((i && j) ? acc[i - 1][j - 1] : 0);
        }
    }
    vector<ll> dp(N * (N + 1) * M * (M + 1) * 2, -1);
    cout << solve(true, 0, 0, M, N, acc, dp) << '\n';
    return 0;
}

