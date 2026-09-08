#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        long long a, b, x;
        cin >> a >> b >> x;
 
        long long ans = abs(a - b);
        long long cnt = 0;
 
        while (a != b) {
 
            if (a < b)
            swap(a, b);
 
            a /= x;
            cnt++;
 
            ans = min(ans, cnt + abs(a - b));
        }
 
    cout << ans << '
';
}
 
return 0;
}