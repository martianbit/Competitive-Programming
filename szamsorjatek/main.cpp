#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const ll INF = (1LL << 62);
int main() {
    FastIO;
    ll i, j, N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for(i = N - 1; i >= 0; i--)
        cin >> A[i];
    vector<ll> B(M);
    for(i = M - 1; i >= 0; i--)
        cin >> B[i];
    vector<array<ll, 3>> Q(K);
    for(i = 0; i < K; i++) {
        cin >> Q[i][0] >> Q[i][1];
        Q[i][0] = N - Q[i][0] + 1;
        Q[i][1] = M - Q[i][1] + 1;
        Q[i][2] = i;
    }
    sort(all(Q));
    vector<ll> ans(K);
    vector<vector<array<ll, 2>>> dp(2, vector<array<ll, 2>>(M + 1));
    dp[0][0][1] = 0;
    i = 0;
    for(const auto &x : Q) {
        while(i <= x[0]) {
            for(j = !i; j <= M; j++) {
                dp[i&1][j][0] = max(i ? (A[i - 1] + dp[1-i&1][j][1]) : 0, max(j ? (B[j - 1] + dp[i&1][j - 1][1]) : 0, (i && j) ? (A[i - 1] + B[j - 1] + dp[1-i&1][j - 1][1]) : 0));
                dp[i&1][j][1] = min(i ? dp[1-i&1][j][0] : INF, min(j ? dp[i&1][j - 1][0] : INF, (i && j) ? dp[1-i&1][j - 1][0] : INF));
            }
            i++;
        }
        ans[x[2]] = dp[x[0]&1][x[1]][0];
    }
    for(const auto &x : ans)
        cout << x << '\n';
    return 0;
}

