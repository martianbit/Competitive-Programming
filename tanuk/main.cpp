#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
int main() {
    FastIO;
    bool flag;
    ll i, j, mh, N, H, K;
    cin >> N >> H >> K;
    vector<ll> tss(K);
    vector<array<ll, 2>> guests(N);
    for(i = 0; i < K; i++)
        cin >> tss[i];
    for(i = 0; i < N; i++)
        cin >> guests[i][0] >> guests[i][1];
    sort(all(tss));
    vector<array<vector<ll>, 2>> eps(H + 1);
    for(i = 0; i < N; i++) {
        for(j = 0; j < 2; j++)
            eps[guests[i][j]][j].push_back(i);
    }
    unordered_set<ll> here;
    vector<bool> bad_guests(N, false);
    if(N <= 80000) {
        fill(all(bad_guests), true);
        j = 0;
        for(i = 1; i <= H && j < K; i++) {
            for(const auto &x : eps[i][0])
                here.insert(x);
            if(i == tss[j]) {
                for(const auto &x : here)
                    bad_guests[x] = false;
                j++;
            }
            for(const auto &x : eps[i][1])
                here.erase(x);
        }
        here.clear();
    }
    unordered_set<ll> lc;
    vector<ll> ans;
    j = 0;
    for(i = 1; i <= H; i++) {
        for(const auto &x : eps[i][0]) {
            if(!bad_guests[x])
                here.insert(x);
        }
        if(j < K && i == tss[j]) {
            if(ans.empty())
                lc = here;
            else {
                for(const auto &x : here) {
                    if(guests[ans.back()][1] < guests[x][0])
                        lc.insert(x);
                }
            }
            j++;
        }
        flag = !lc.empty();
        if(flag) {
            flag = false;
            for(const auto &x : eps[i][1]) {
                if(lc.find(x) != lc.end()) {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) {
            mh = *(here.begin());
            for(const auto &x : here) {
                if(guests[mh][1] < guests[x][1])
                    mh = x;
            }
            ans.push_back(mh);
            j = upper_bound(all(tss), guests[mh][1]) - tss.begin();
            lc.clear();
        }
        for(const auto &x : eps[i][1]) {
            if(!bad_guests[x])
                here.erase(x);
        }
    }
    cout << ans.size() << '\n';
    for(const auto &x : ans)
        cout << x + 1 << ' ';
    cout << '\n';
    return 0;
}

