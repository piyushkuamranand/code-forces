#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<long long> a(n + 1);
    vector<long long> pref(n + 1, 0);
 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
 
 
    vector<vector<long long>> dp(k + 1,
                                vector<long long>(n + 1, 0));
 
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
 
            dp[j][i] = dp[j][i - 1];
 
            if (i >= j * m) {
                long long segmentSum = pref[i] - pref[i - m];
 
                dp[j][i] = max(
                    dp[j][i],
                    dp[j - 1][i - m] + segmentSum
                );
            }
        }
    }
 
    cout << dp[k][n] << '
';
 
    return 0;
}