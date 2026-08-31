#if defined(ONLINE_JUDGE) && defined(__GNUC__) && !defined(__clang__)
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
#define lrep(i,a,b) for(ll i=(a);i<(b);i++)
#define rev(i,a,b) for(int i=(a);i<(b);i--)
#define YES cout << "YES
"
#define NO cout << "NO
"
#define all(v) v.begin(), v.end()
#define rt return
#define cn cout<<"
"
 
 
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
 
struct Segment {
    int l, r;
 
    bool operator<(const Segment& other) const {
        int len1 = r - l + 1;
        int len2 = other.r - other.l + 1;
 
        if (len1 != len2)
            return len1 < len2;
 
        return l > other.l;
    }
};
 
void solve(){
    int n;
    cin >> n;
 
    priority_queue<Segment> pq;
    pq.push({1,n});
    
    
 
    vi ans(n+1,0);
    
    rep(i,1,n+1){
        auto [l,r] = pq.top();
    pq.pop();
        int mid = (l+r)/2;
 
        ans[mid] = i;
 
        
        if (l <= mid - 1)
            pq.push({l, mid - 1});
 
        if (mid + 1 <= r)
            pq.push({mid + 1, r});
    }
 
    rep(i,1,n+1){
        cout << ans[i] << " ";
    }
 
    cn;
}
 
int main(){
    fastio;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}