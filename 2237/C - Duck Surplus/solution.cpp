#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
bool check(const vector<ll>& a, ll X) {
    vector<ll> st;
 
    for (ll x : a) {
        st.push_back(x);
 
        while (st.size() >= 2) {
            int n = st.size();
 
            if (st[n - 2] <= st[n - 1])
            break;
 
            ll y = st[n - 1];
            ll z = st[n - 2];
 
            st.pop_back();
            st.pop_back();
 
            // (z, y) -> (y, z+y)
            if (z + y > X)
            return false;
 
            st.push_back(y);
            st.push_back(z + y);
        }
}
 
for (ll x : st)
if (x > X)
return false;
 
return true;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
 
    while (T--) {
        int n;
        cin >> n;
 
        vector<ll> a(n);
 
        ll lo = 0, hi = 0;
 
        for (auto &x : a) {
            cin >> x;
            lo = max(lo, x);
            hi += x;
        }
 
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
 
        if (check(a, mid))
        hi = mid;
        else
        lo = mid + 1;
    }
 
cout << lo << '
';
}
 
return 0;
}