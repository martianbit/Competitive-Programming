#include <bits/stdc++.h>
#define NS() ((i == (N[0] - '0')) ? N.substr(1) : string(N.size() - 1, '9'))
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
using namespace std;
ll solve(string N, ll limit, bool left, unordered_map<string, ll> &dp) {
    ll i, ans;
    string key = N + " " + to_string(limit) + " " + (left ? "1" : "0");
    auto found = dp.find(key);
    if(found == dp.end()) {
        if(N.empty())
            ans = !left;
        else {
            ans = 0;
            if(left) {
                for(i = limit; i <= (N[0] - '0'); i++) {
                    string ns = NS();
                    ans += solve(ns, i, true, dp) + solve(ns, i - 1, false, dp);
                }
            }
            else {
                for(i = min(limit, (ll) (N[0] - '0')); i >= 0; i--)
                    ans += solve(NS(), i, false, dp);
            }
        }
        dp[key] = ans;
    }
    else
        ans = found->second;
    return ans;
}
int main() {
    FastIO;
    ll i, ans;
    string N;
    unordered_map<string, ll> dp;
    cin >> N;
    if(N == "0") {
        cout << "0\n";
        return 0;
    }
    for(i = N.size() - 1; i >= 0; i--) {
        N[i]--;
        if(N[i] == '0' - 1)
            N[i] = '9';
        else
            break;
    }
    ans = 1 + solve(N, 1, true, dp);
    for(i = 0; i < N.size(); i++)
        ans += solve(string(i, '9'), 1, true, dp);
    cout << ans << '\n';
    return 0;
}

