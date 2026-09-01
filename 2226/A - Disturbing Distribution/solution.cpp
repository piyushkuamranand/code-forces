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
    int n;
    cin >> n;
 
    vll a(n);
 
    rep(i, 0, n)
        cin >> a[i];
 
    ll ans = 0;
 
    rep(i, 0, n){
        if(a[i] > 1)
            ans += a[i];
    }
 
    if(a[n - 1] == 1)
        ans++;
 
    cout << ans << '
';
}
 
int main(){
    fastio;
 
    int t;
    cin >> t;
 
    while(t--)
        solve();
 
    return 0;
}