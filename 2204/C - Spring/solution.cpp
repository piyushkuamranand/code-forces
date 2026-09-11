#include <bits/stdc++.h>
using namespace std;
 
using int64 = long long;
 
int64 lcm_ll(int64 a, int64 b) {
    return a / gcd(a, b) * b;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int64 a, b, c, m;
        cin >> a >> b >> c >> m;
 
        int64 ab = lcm_ll(a, b);
        int64 ac = lcm_ll(a, c);
        int64 bc = lcm_ll(b, c);
        int64 abc = lcm_ll(ab, c);
 
        int64 A = m / a;
        int64 B = m / b;
        int64 C = m / c;
 
        int64 AB = m / ab;
        int64 AC = m / ac;
        int64 BC = m / bc;
        int64 ABC = m / abc;
 
        int64 alice = 6 * A - 3 * AB - 3 * AC + 2 * ABC;
        int64 bob   = 6 * B - 3 * AB - 3 * BC + 2 * ABC;
        int64 carol = 6 * C - 3 * AC - 3 * BC + 2 * ABC;
 
        cout << alice << ' ' << bob << ' ' << carol << '
';
    }
 
    return 0;
}