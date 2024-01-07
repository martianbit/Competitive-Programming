#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
int main() {
    FastIO;
    bool ok, same;
    ll i, j, rs, cntr, N;
    cin >> N;
    vector<ll> lucky(N);
    for(i = 0; i < N; i++)
        cin >> lucky[i];
    rs = lucky[0] - 1;
    ok = same = true;
    vector<ll> ans(N, 0);
    stack<ll> free_places;
    for(i = 1; i < N; i++) {
        if(lucky[i] == lucky[i - 1])
            continue;
        same = false;
        if(lucky[i] < lucky[i - 1] || ((lucky[i] - lucky[i - 1]) > (i - rs + ((ll) free_places.size())))) {
            ok = false;
            break;
        }
        for(j = 0; j < min(lucky[i] - lucky[i - 1], i - rs); j++)
            ans[i - j] = j + lucky[i - 1];
        while(j < i - rs)
            free_places.push(i - j++);
        while(j < lucky[i] - lucky[i - 1]) {
            ans[free_places.top()] = j++ + lucky[i - 1];
            free_places.pop();
        }
        rs = i;
    }
    if(same) {
        if(!lucky[0])
            fill(all(ans), 1);
        else if(lucky[0] > 1)
            ok = false;
    }
    else if(ok) {
        cntr = lucky.back();
        while(!free_places.empty()) {
            ans[free_places.top()] = ++cntr;
            free_places.pop();
        }
        for(i = rs + 1; i < N; i++)
            ans[i] = ++cntr;
    }
    if(ok) {
        cout << "IGEN\n";
        for(const auto &x : ans)
            cout << x << ' ';
        cout << '\n';
    }
    else
        cout << "NEM\n";
    return 0;
}

