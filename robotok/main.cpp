#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
int main() {
    FastIO;
    ll i, N, M, K;
    cin >> N >> M >> K;
    vector<array<ll, 2>> objs(K);
    for(i = 0; i < K; i++)
        cin >> objs[i][0] >> objs[i][1];
    sort(all(objs));
    vector<ll> robots;
    for(const auto &x : objs) {
        auto it = lower_bound(all(robots), -x[1]);
        if(it == robots.end())
            robots.push_back(-x[1]);
        else
            *it = -x[1];
    }
    cout << robots.size() << '\n';
    return 0;
}

