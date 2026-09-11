#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        string s;
 
        cin >> n >> s;
 
        s += s;
 
        int ans = 0;
        int cnt = 0;
 
        for (int i = 0; i < 2 * n; i++) {
            if (s[i] == '0') {
                cnt++;
                ans = max(ans, cnt);
            } else {
                cnt = 0;
            }
        }
 
        cout << min(ans, n) << '
';
    }
 
    return 0;
}