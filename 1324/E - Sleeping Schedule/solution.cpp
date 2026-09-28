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
#define rep(i,a,b) for(long i=(a);i<(b);i++)
#define rrep(i,a,b) for(long i=(a); i>=(b); i--)
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
 
void solve(){
 
    ll n, h, l, r;
    cin >> n >> h >> l >> r;
 
    vll a(n);
 
    rep(i, 0, n)
        cin >> a[i];
 
 
    vector<vector<ll>> dp(n + 1, vector<ll>(h, -1));
 
    dp[0][0] = 0;
 
    for (int i = 1; i <= n; i++) {
 
        for (int j = 0; j < h; j++) {
 
            if (dp[i - 1][j] == -1)
                continue;
 
 
            ll newTime = (j + a[i - 1]) % h;
 
            int good = (l <= newTime && newTime <= r);
 
            dp[i][newTime] = max(
                dp[i][newTime],
                dp[i - 1][j] + good
            );
 
  
            newTime = (j + a[i - 1] - 1) % h;
 
            good = (l <= newTime && newTime <= r);
 
            dp[i][newTime] = max(
                dp[i][newTime],
                dp[i - 1][j] + good
            );
        }
    }
 
    ll ans = 0;
 
    for (int j = 0; j < h; j++) {
        ans = max(ans, dp[n][j]);
    }
 
    cout << ans << '
';
}
 
int main(){
 
    fastio;
 
    int t = 1;
 
    while(t--)
        solve();
 
    return 0;
}