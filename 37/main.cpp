#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
int main() {
    FastIO;
    ll N;
    cin >> N;
    cout << ((N % 37) ? "NEM" : "IGEN") << '\n';
    while(N > 0) {
        N = N / 10 - (N % 10) * 11;
        if(N >= 0)
            cout << N << ' ';
    }
    cout << '\n';
    return 0;
}

