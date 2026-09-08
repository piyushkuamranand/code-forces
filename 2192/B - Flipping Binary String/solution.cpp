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
 
        vector<int> ans;
        int ones = count(s.begin(), s.end(), '1');
        int zeros = n - ones;
 
        if (ones % 2 == 0) {
            for (int i = 0; i < n; i++) {
                if (s[i] == '1')
                ans.push_back(i + 1);
            }
    }
else if (zeros % 2 == 1) {
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
        ans.push_back(i + 1);
    }
}
else {
    cout << -1 << '
';
    continue;
}
 
cout << ans.size() << '
';
 
for (int i : ans)
cout << i << ' ';
 
cout << '
';
}
 
return 0;
}