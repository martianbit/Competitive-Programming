#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
int main() {
    FastIO;
    ll i, j, cntr, ans, N;
    string dns;
    cin >> dns;
    N = dns.size();
    ans = 1;
    for(i = 0; i < 4; i++) {
        vector<ll> same(N * 2 + 1, -1);
        cntr = N;
        for(j = 0; j < N; j++) {
            cntr += (dns[j] == "ACGT"[i]) * 2 - 1;
            if(same[cntr] == -1)
                same[cntr] = j;
            else
                ans = max(ans, j - same[cntr]);
        }
        if(cntr >= N)
            ans = N;
    }
    cout << ans << '\n';
    return 0;
}

