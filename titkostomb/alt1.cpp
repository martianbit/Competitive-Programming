#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
int main() {
    FastIO;
    ll i, j, v, lo, hi, N;
    cin >> N;
    vector<ll> B(N);
    for(i = 0; i < N; i++)
        cin >> B[i];
    lo = 0;
    hi = N + 1;
    vector<ll> todo(N, -1);
    for(i = 0; i < N; i++) {
        if(todo[i] != -1)
            lo = todo[i];
        if(B[i] == -1)
            cout << --hi << ' ';
        else {
            j = B[i] - 1;
            v = lo + j - i;
            if(todo[j] == -1)
                todo[j] = v;
            cout << v << ' ';
        }
    }
    cout << '\n';
    return 0;
}

