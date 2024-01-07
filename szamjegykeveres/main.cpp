#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
using namespace std;
int main() {
    FastIO;
    string N;
    cin >> N;
    cout << (((N[0] > '1' && count(all(N), '0') == N.size() - 1) ? (N[0] - '0' + (N.size() - 1) * 9) : accumulate(all(N), 0LL, [](auto a, auto b) { return a + ((ll) (b - '0')); })) + N.size() * (N.size() - 1LL) * 9LL / 2LL) << '\n';
    return 0;
}

