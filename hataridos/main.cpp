#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
using namespace std;
int main() {
    FastIO;
    ll i, t, N;
    cin >> N;
    vector<array<ll, 3>> jobs(N);
    for(i = 0; i < N; i++) {
        cin >> jobs[i][1] >> jobs[i][0];
        jobs[i][2] = i;
    }
    auto jobs_s = jobs;
    sort(all(jobs_s));
    vector<ll> ans;
    priority_queue<array<ll, 2>> q;
    for(i = N - 1; i >= 0; i--) {
        t = jobs_s[i][0] - (i ? jobs_s[i - 1][0] : 0);
        q.push({ -jobs_s[i][1], jobs_s[i][2] });
        while(t && !q.empty()) {
            auto nxt = q.top();
            q.pop();
            nxt[0] *= -1;
            if(nxt[0] <= t) {
                ans.push_back(nxt[1]);
                t -= nxt[0];
            }
            else {
                q.push({ -(nxt[0] - t), nxt[1] });
                t = 0;
            }
        }
    }
    sort(all(ans), [&](auto a, auto b) {
        return jobs[a][0] < jobs[b][0];
    });
    cout << ans.size() << '\n';
    for(const auto &x : ans)
        cout << (x + 1) << ' ';
    cout << '\n';
    return 0;
}

