#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
int main() {
    FastIO;
    ll i, c1, c2, lo, hi, mid, ans, N, Q, X, Y;
    array<ll, 2> p1, p2;
    cin >> N;
    vector<array<ll, 2>> A(N);
    for(i = 0; i < N; i++) {
        cin >> A[i][0];
        A[i][1] = i;
    }
    sort(all(A));
    cin >> Q;
    while(Q--) {
        cin >> X >> Y;
        ans = lo = 0;
        hi = N - 1;
        while(lo + 1 < hi) {
            mid = (lo + hi) / 2;
            p1 = { X, mid };
            p2 = { X, 0 };
            c1 = upper_bound(all(A), p1) - lower_bound(all(A), p2);
            p1 = { Y, N - 1 };
            p2 = { Y, mid + 1 };
            c2 = upper_bound(all(A), p1) - lower_bound(all(A), p2);
            ans = max(ans, min(c1, c2));
            if(c1 < c2)
                lo = mid;
            else
                hi = mid;
        }
        cout << ans << '\n';
    }
    return 0;
}

