#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
int main() {
    FastIO;
    ll i, a, b, b1, b2, N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for(i = 0; i < N; i++)
        cin >> A[i];
    sort(all(A));
    for(i = 0; i < Q; i++) {
        cin >> a >> b;
        b1 = upper_bound(all(A), a + b - 1) - A.begin();
        b2 = lower_bound(A.begin(), A.begin() + b1, abs(a - b) + 1) - A.begin();
        cout << b1 - b2 << '\n';
    }
    return 0;
}

