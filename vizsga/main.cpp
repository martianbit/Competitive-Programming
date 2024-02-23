#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
using namespace std;
int main() {
    FastIO;
    ll i, sc, ans1, ans2, N, P;
    string s, S;
    cin >> N >> P >> s >> S;
    sc = 0;
    for(i = 0; i < N; i++)
        sc += (s[i] == S[i]);
    ans1 = abs(P - N + sc);
    ans2 = N - abs(P - sc);
    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}

