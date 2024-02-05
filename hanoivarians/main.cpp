#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
void solve(vector<array<ll, 2>> &steps, vector<ll> &S, const vector<ll> &E) {
    ll i, j, k;
    if(S.empty())
        return;
    for(i = S.size() - 1; i >= 0; i--) {
        if(S[i] == E[i])
            continue;
        vector<ll> ns(i);
        vector<ll> ne(i);
        for(j = 0; j < 3 && (S[i] == j || E[i] == j); j++);
        for(k = 0; k < i; k++) {
            ns[k] = S[k];
            ne[k] = j;
        }
        solve(steps, ns, ne);
        steps.push_back({ S[i], E[i] });
        S = ne;
    }
}
void trans(vector<ll> &result, const array<vector<ll>, 3> &state) {
    ll i;
    for(i = 0; i < 3; i++) {
        for(const auto &x : state[i])
            result[x - 1] = i;
    }
}
int main() {
    FastIO;
    ll i, j, N, D;
    N = 1;
    array<array<vector<ll>, 3>, 2> states;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 3; j++) {
            while(true) {
                cin >> D;
                if(!D)
                    break;
                N = max(N, D);
                states[i][j].push_back(D);
            }
        }
    }
    vector<ll> S(N);
    vector<ll> E(N);
    trans(S, states[0]);
    trans(E, states[1]);
    vector<array<ll, 2>> steps;
    solve(steps, S, E);
    cout << steps.size() << '\n';
    for(const auto &x : steps)
        cout << (x[0] + 1) << ' ' << (x[1] + 1) << '\n';
    return 0;
}

