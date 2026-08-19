#if defined(ONLINE_JUDGE) && defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3,unroll-loops")
#endif
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
 
using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define pb push_back
#define rep(i,a,b) for(long long i=(a);i<(b);i++)
#define YES cout << "YES
"
#define NO cout << "NO
"
#define rt return
#define all(v) v.begin(), v.end()
 
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
 
struct DSU {
    vi parent, sz;
 
    DSU(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
 
    int find(int i) {
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
 
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
 
        if(a == b) return;
 
        if(sz[a] < sz[b]) swap(a, b);
 
        parent[b] = a;
        sz[a] += sz[b];
    }
};
 
void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
 
    vll p(n), pos(n);
 
    rep(i,0,n) {
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }
 
    DSU dsu(n);
 
    rep(i,0,n) {
        if(i + x < n) {
            dsu.unite(i, i + x);
        }
 
        if(i + y < n) {
            dsu.unite(i, i + y);
        }
    }
 
    rep(i,0,n) {
        if(dsu.find(i) != dsu.find(pos[i])) {
            NO;
            rt;
        }
    }
 
    YES;
}
 
int main() {
    fastio;
 
    int t;
    cin >> t;
 
    while(t--) {
        solve();
    }
 
    return 0;
}