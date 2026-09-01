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
 
bool check(int k, multiset<int>& ms){
    vector<int> used;
 
    for(int x = k - 1; x >= 0; x--){
        auto it = ms.find(x);
 
        if(it != ms.end()){
            used.pb(x);
            ms.erase(it);
        }
        else{
            it = ms.upper_bound(2 * x);
 
            if(it == ms.end()){
                for(auto v : used)
                    ms.insert(v);
                return false;
            }
 
            used.pb(*it);
            ms.erase(it);
        }
    }
 
    for(auto v : used)
        ms.insert(v);
 
    return true;
}
 
void solve(){
    int n;
    cin >> n;
 
    vll a(n);
 
    rep(i,0,n)
        cin >> a[i];
 
    multiset<int> ms(a.begin(), a.end());
 
    int lo = 0, hi = n + 1;
 
    while(lo < hi){
        int mid = (lo + hi) / 2;
 
        if(check(mid, ms))
            lo = mid + 1;
        else
            hi = mid;
    }
 
    cout << lo - 1 << '
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