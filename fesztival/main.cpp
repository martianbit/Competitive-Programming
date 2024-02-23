#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
using namespace std;
ll solve(ll day, const vector<vector<array<ll, 3>>> &A, vector<array<ll, 2>> &dp) {
    ll cand;
    if(day >= dp.size())
        return 0;
    auto &ans = dp[day];
    if(ans[0] != -1)
        return ans[0];
    ans = { solve(day + 1, A, dp), 0 };
    for(const auto &x : A[day]) {
        cand = x[1] + solve(x[0] + 1, A, dp);
        if(cand > ans[0])
            ans = { cand, x[2] };
    }
    return ans[0];
}
int main() {
    FastIO;
    ll i, N, E, B;
    cin >> N;
    vector<ll> U(N + 1);
    vector<vector<array<ll, 3>>> A(100001);
    for(i = 1; i <= N; i++) {
        cin >> E >> U[i] >> B;
        A[E].push_back({ U[i], B, i });
    }
    vector<array<ll, 2>> dp(100001, { -1, -1 });
    cout << solve(1, A, dp) << '\n';
    vector<ll> ans2;
    for(i = 1; i <= 100000; i++) {
        if(!dp[i][1])
            continue;
        ans2.push_back(dp[i][1]);
        i = U[dp[i][1]];
    }
    cout << ans2.size() << ' ';
    for(const auto &x : ans2)
        cout << x << ' ';
    cout << '\n';
    return 0;
}

