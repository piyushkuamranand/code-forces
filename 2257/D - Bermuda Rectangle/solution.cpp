#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
 
#define int long long
 
inline void solve(){
    int s, numofquery;
    cin >> s >> numofquery;
 
    vector<pair<int,int>> q(numofquery);
 
    for(int i = 0; i < numofquery; i++){
        cin >> q[i].first >> q[i].second;
    }
 
    vector<int> x;
 
    for(int i = 1; i * i <= s; i++){
        if(s % i == 0){
            x.push_back(i);
 
            if(i != s / i){
                x.push_back(s / i);
            }
        }
    }
 
    sort(x.begin(), x.end());
 
    int n = x.size();
 
    vector<int> area(n), prew(n + 1), prea(n + 1);
 
    for(int i = 0; i < n; i++){
        int prev = (i == 0 ? 0 : x[i - 1]);
 
        area[i] = s / x[i];
 
        prew[i + 1] = prew[i] + (x[i] - prev);
        prea[i + 1] = prea[i] + (x[i] - prev) * area[i];
    }
 
    for(int i = 0; i < numofquery; i++){
        int X = q[i].first;
        int Y = q[i].second;
 
        int ind = lower_bound(x.begin(), x.end(), X) - x.begin();
 
        int l = 0, r = ind - 1;
        int pos = -1;
 
        while(l <= r){
            int mid = (l + r) / 2;
 
            if(area[mid] >= Y){
                pos = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
 
        int ans = prew[pos + 1] * Y + (prea[ind] - prea[pos + 1]);
 
        int prev = (ind == 0 ? 0 : x[ind - 1]);
 
        ans += (X - prev) * min(Y, area[ind]);
 
        cout << ans << '
';
    }
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while(t--){
        solve();
    }
 
    return 0;
}