#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
 
        bool ok = true;
 
        for (int r = 0; r < k; ++r) {
            int ones = 0;
            for (int i = r; i < n; i += k) {
                ones += (s[i] == '1');
            }
            if (ones % 2 != 0) {
                ok = false;
                break;
            }
        }
 
        cout << (ok ? "YES" : "NO") << '
';
    }
 
    return 0;
}