#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
using namespace std;
int main() {
    FastIO;
    bool sgn;
    ll i, j, r1, r2, cntr, cand, ans, N;
    array<ll, 2> fst_neg;
    cin >> N;
    vector<ll> A(N);
    for(auto &x : A)
        cin >> x;
    ans = -2;
    r1 = r2 = 0;
    i = 0;
    while(i < N) {
        sgn = true;
        cntr = 0;
        fst_neg = { -1, 0 };
        for(j = i; j < N && A[j]; j++) {
            if(A[j] < 0)
                sgn = !sgn;
            cntr += (abs(A[j]) == 2);
            if(sgn) {
                if(ans < cntr) {
                    ans = cntr;
                    r1 = i;
                    r2 = j;
                }
            }
            else {
                if(fst_neg[0] == -1)
                    fst_neg = { j, cntr };
                else {
                    cand = cntr - fst_neg[1];
                    if(ans < cand) {
                        ans = cand;
                        r1 = fst_neg[0] + 1;
                        r2 = j;
                    }
                }
            }
        }
        if(j < N && ans < -1) {
            ans = -1;
            r1 = r2 = j;
        }
        i = j + 1;
    }
    cout << (r1 + 1) << ' ' << (r2 + 1) << '\n';
    return 0;
}

