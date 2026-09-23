#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int MOD = 998244353;
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    const int MAXN = 200000;
 
    vector<int> fact(MAXN + 1);
    fact[0] = 1;
 
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
 
    while (t--) {
        int n;
        cin >> n;
 
        vector<int> a(n);
 
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        if (n == 1) {
            cout << 0 << '
';
            continue;
        }
 
        sort(a.begin(), a.end());
 
        int totalSum = 0;
 
        for (int x : a) {
            totalSum = (totalSum + x) % MOD;
        }
 
        int suffixSum = totalSum;
        int ans = 0;
 
        for (int i = 0; i < n - 1; i++) {
            suffixSum = (suffixSum - a[i] + MOD) % MOD;
 
            int cnt = n - 1 - i;
 
            int cost = (suffixSum - (cnt % MOD) * (a[i] % MOD)) % MOD;
            cost = (cost + MOD) % MOD;
 
            int ways = fact[n - 1];
 
            int inv = 1;
 
            int x = cnt;
            int y = MOD - 2;
 
            while (y) {
                if (y & 1)
                    inv = inv * x % MOD;
                x = x * x % MOD;
                y >>= 1;
            }
 
            ways = ways * inv % MOD;
 
            ans = (ans + cost * ways) % MOD;
        }
 
        cout << ans << '
';
    }
 
    return 0;
}