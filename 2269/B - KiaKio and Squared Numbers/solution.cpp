#include <bits/stdc++.h>
using namespace std;
 
int f(int x) {
    int s = 0;
    while (x > 0) {
        int d = x % 10;
        s += d * d;
        x /= 10;
    }
    return s;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        map<int, long long> cnt;
 
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
 
            for (int j = 0; j < 100; ++j) {
                x = f(x);
            }
 
            cnt[x]++;
        }
 
        long long ans = 0;
 
        for (auto &[x, c] : cnt) {
            ans += c * (c - 1) / 2;
        }
 
        cout << ans << '
';
    }
 
    return 0;
}