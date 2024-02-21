#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, bool> Event;
int main() {
    FastIO;
    ll i, nxt, ans1, ans2, ans3, M, N;
    cin >> M >> N;
    vector<ll> E(N);
    vector<ll> H(N);
    priority_queue<Event, vector<Event>, greater<Event>> q;
    for(i = 0; i < N; i++) {
        cin >> E[i] >> H[i];
        q.push({ E[i], i, true });
    }
    ans2 = ans3 = 0;
    vector<ll> ans4(N);
    queue<ll> waiting;
    set<ll> rooms;
    for(i = 0; i < M; i++)
        rooms.insert(i);
    while(!q.empty()) {
        auto [t, n, arrives] = q.top();
        q.pop();
        ans3 = max(ans3, (ll) waiting.size());
        if(arrives) {
            if(rooms.empty())
                waiting.push(n);
            else {
                ans4[n] = *(rooms.begin());
                rooms.erase(rooms.begin());
                q.push({ t + H[n], n, false });
            }
        }
        else {
            rooms.insert(ans4[n]);
            if(!waiting.empty()) {
                nxt = waiting.front();
                waiting.pop();
                ans2 = max(ans2, t - E[nxt]);
                q.push({ t, nxt, true });
            }
            if(q.empty())
                ans1 = t;
        }
    }
    cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
    for(const auto &x : ans4)
        cout << (x + 1) << '\n';
    return 0;
}

