#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define lrep(i,a,b) for(ll i=(a);i<(b);i++)
#define rev(i,a,b) for(int i=(a);i>(b);i--)
#define YES cout << "YES
"
#define NO cout << "NO
"
#define all(v) v.begin(), v.end()
#define rt return
#define cn cout << "
"
 
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
 
void solve(){
    ll n, m, d;
    cin >> n >> m >> d;
 
    vll a(m);
    ll sum = 0;
 
    rep(i, 0, m){
        cin >> a[i];
        sum += a[i];
    }
 
    ll empty = n - sum;
 
    if(empty > (m + 1) * (d - 1)){
        NO;
        return;
    }
 
    YES;
 
    vll ans(n, 0);
    ll pos = 0;
 
    rep(i, 0, m){
        ll gap = min(empty, d - 1);
        pos += gap;
 
        rep(j, 0, a[i]){
            ans[pos] = i + 1;
            pos++;
        }
 
        empty -= gap;
    }
 
    rep(i, 0, n){
        cout << ans[i] << " ";
    }
 
    cn;
}
 
int main(){
    fastio;
 
    int t = 1;
 
    while(t--)
        solve();
 
    return 0;
}