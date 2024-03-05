#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
ll fulls, C;
vector<ll> A;
vector<vector<ll>> DAG;
vector<multiset<ll>*> rems;
ll dfs(ll vertex) {
    ll largest;
    vector<ll> children;
    largest = 0;
    children.reserve(DAG[vertex].size());
    for(const auto &x : DAG[vertex]) {
        children.push_back(dfs(x));
        if(!largest || rems[children.back()]->size() > rems[largest]->size())
            largest = children.back();
    }
    if(largest) {
        for(const auto &x : children) {
            if(x != largest)
                rems[largest]->insert(rems[x]->begin(), rems[x]->end());
        }
        stack<ll> st;
        for(auto it = --(rems[largest]->end()); A[vertex]; it--) {
            if(A[vertex] >= C - *it) {
                fulls++;
                A[vertex] -= C - *it;
            }
            else {
                rems[largest]->insert(*it + A[vertex]);
                A[vertex] = 0;
            }
            st.push(*it);
            if(it == rems[largest]->begin())
                break;
        }
        while(!st.empty()) {
            rems[largest]->erase(rems[largest]->find(st.top()));
            st.pop();
        }
    }
    else {
        rems[vertex] = new multiset<ll>();
        largest = vertex;
    }
    fulls += A[vertex] / C;
    if(A[vertex] % C)
        rems[largest]->insert(A[vertex] % C);
    return largest;
}
int main() {
    FastIO;
    ll i, ri, ans, N, K, P;
    cin >> N >> K >> C;
    A.resize(N + 1);
    DAG.resize(N + 1);
    rems.resize(N + 1);
    for(i = 1; i <= N; i++) {
        cin >> P >> A[i];
        DAG[P].push_back(i);
    }
    ri = dfs(1);
    ans = min(fulls, K) * C;
    i = K - fulls - 1;
    for(auto it = --(rems[ri]->end()); i >= 0; it--, i--)
        ans += *it;
    cout << ans << '\n';
    return 0;
}

