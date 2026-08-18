#if defined(ONLINE_JUDGE) && defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3,unroll-loops")
#endif
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <cstring>
#include <climits>
#include <iomanip>
#include <chrono>
#include <bitset>
 
using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b);i>=a;i--)
#define YES cout << "YES
"
#define NO cout << "NO
"
#define rt return
#define cn cout << "
"
#define all(v) v.begin(), v.end()
 
 
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vlpl = vector<pair<ll,ll>>;
using vlpi = vector<pair<ll,int>>;
using vb = vector<bool>;
 
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
const ll MOD = 998244353;
ll modAdd(ll a,ll b){ return (a+b)%MOD; }
ll modSub(ll a,ll b){ return (a-b+MOD)%MOD; }
ll modMul(ll a,ll b){ return (a%MOD)*(b%MOD)%MOD; }
ll Pow(ll b,ll e){
    ll r=1; b%=MOD;
    while(e){ if(e&1) r=modMul(r,b); b=modMul(b,b); e>>=1; }
    return r;
}
ll modInv(ll n){ return Pow(n,MOD-2); }
ll modDiv(ll a,ll b){ return modMul(a,modInv(b)); }
ll nCk(ll n, ll k){
    if(k < 0 || k > n) return 0;
    k = min(k, n - k);
    ll num = 1, den = 1;
    for(ll i = 1; i <= k; i++){
        num = modMul(num, n - i + 1);
        den = modMul(den, i);
    }
    return modMul(num,modInv(den));
}
 
template <typename T>
struct FenwickTree {
    int n;
    vector<T> tree;
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}
    void add(int i, T val) {
        for (; i <= n; i += i & -i) tree[i] += val;
    }
    T query(int i) {
        T sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
    T query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};
 
struct DSU {
    int components;
    vi parent, sz;
    DSU(int n) : components(n), parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
            components--;
            return true;
        }
        return false;
    }
    bool same(int i, int j) {
        return find(i) == find(j);
    }
    int size(int i) {
        return sz[find(i)];
    }
};
 
 
void solve() {
    ll n;
    cin >> n;
 
    string s;
    cin >> s;
 
    ll count=0,mx=0;
    rep(i,0,n){
        if(s[i]=='#')count++;
        else mx = max(count,mx), count=0;
    }
    mx = max(count,mx);
 
    cout << ceil((double)mx/2);
    cn;
    
}
 
int main(){
    fastio;
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}