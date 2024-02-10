#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const ll INF = (1LL << 62);
class SegTree {
private:
    ll r1, r2;
    vector<ll> A;
    SegTree *left, *right;
public:
    SegTree(const vector<ll> &A, ll r1, ll r2);
    ll query(ll q1, ll q2, ll q3);
};
SegTree::SegTree(const vector<ll> &A, ll r1, ll r2) {
    ll i, mid;
    this->r1 = r1;
    this->r2 = r2;
    this->A.reserve(r2 - r1 + 1);
    for(i = r1; i <= r2; i++)
        this->A.push_back(A[i]);
    sort(all(this->A));
    if(r1 == r2)
        left = right = NULL;
    else {
        mid = (r1 + r2) / 2;
        left = new SegTree(A, r1, mid);
        right = new SegTree(A, mid + 1, r2);
    }
}
ll SegTree::query(ll q1, ll q2, ll q3) {
    if(q2 < q1 || q2 < r1 || q1 > r2)
        return 0;
    else if(q1 <= r1 && q2 >= r2)
        return upper_bound(all(A), q3) - A.begin();
    else
        return left->query(q1, q2, q3) + right->query(q1, q2, q3);
}
int main() {
    FastIO;
    ll i, v, m, delta, ans, N, P, Q, Db;
    cin >> N >> P >> Q;
    vector<ll> X(N);
    for(i = 0; i < N; i++)
        cin >> X[i];
    vector<ll> Y(N);
    for(i = 0; i < N; i++)
        cin >> Y[i];
    ans = 0;
    m = -INF;
    vector<ll> vals(N);
    vector<ll> ms(N);
    for(i = 0; i < N; i++) {
        vals[i] = 1e9 * (Y[i] - P) / X[i];
        m = max(m, vals[i]);
        ms[i] = m;
        if(m <= vals[i])
            ans++;
        else
            vals[i] = INF;
    }
    SegTree seg(vals, 0, N - 1);
    while(Q--) {
        cin >> Db;
        vector<array<ll, 2>> q(Db);
        for(i = 0; i < Db; i++) {
            cin >> q[i][0] >> q[i][1];
            q[i][0]--;
        }
        delta = 0;
        m = -INF;
        for(i = 0; i < Db; i++) {
            v = 1e9 * (Y[q[i][0]] + q[i][1] - P) / X[q[i][0]];
            delta += (vals[q[i][0]] == INF && v > max(m, ms[q[i][0]]));
            delta -= (vals[q[i][0]] != INF && v <= max(m, ms[q[i][0]]));
            m = max(m, v);
            delta -= seg.query(q[i][0] + 1, (i >= Db - 1) ? N - 1 : q[i + 1][0] - 1, m);
        }
        cout << (ans + delta) << ' ';
    }
    cout << '\n';
    return 0;
}

