#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    vector<int> a(n), p(n + 1, 0);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i + 1] = (p[i] + a[i]) % k;
    }
 
    vector<long long> cnt(k, 0);
    long long ans = 0;
 
    for (int i = k + 1; i <= n; i++) {
        cnt[p[i - k - 1]]++;
        ans += cnt[p[i]];
    }
 
    cout << ans << '
';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) solve();
    return 0;
}