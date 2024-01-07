#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
int main() {
    FastIO;
    ll i, v, cntr, N;
    cin >> N;
    vector<ll> B(N + 1);
    for(i = 1; i <= N; i++)
        cin >> B[i];
    vector<vector<ll>> graph(N + 1);
    for(i = 1; i <= N; i++)
        graph[B[i] == -1 ? 0 : B[i]].push_back(i);
    cntr = N;
    vector<ll> A(N + 1);
    queue<ll> q;
    q.push(0);
    while(!q.empty()) {
        v = q.front();
        q.pop();
        for(const auto &x : graph[v]) {
            A[x] = cntr--;
            q.push(x);
        }
    }
    for(i = 1; i <= N; i++)
        cout << A[i] << ' ';
    cout << '\n';
    return 0;
}

