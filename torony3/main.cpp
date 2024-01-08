#include <bits/stdc++.h>
#define MOD 20210108LL
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
int main() {
    FastIO;
    ll i, N;
    cin >> N;
    vector<ll> a(N + 1);
    a[0] = 1;
    a[1] = 0;
    a[2] = 2;
    a[3] = 2;
    for(i = 4; i <= N; i++)
        a[i] = (2 * a[i - 2] + 2 * a[i - 3]) % MOD;
    cout << a[N] << '\n';
    return 0;
}

