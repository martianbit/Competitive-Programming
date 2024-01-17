#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
int main() {
    FastIO;
    ll i, ac, pc, N;
    string s;
    cin >> N >> s;
    pc = count(all(s), 'K');
    for(i = 0; i < N && ac < pc; i++) {
        ac += s[i] == 'A';
        pc -= s[i] == 'K';
    }
    cout << ac * 2 << '\n';
    return 0;
}

