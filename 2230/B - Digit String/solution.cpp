#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        string s;
        cin >> s;
 
        int pref2 = 0;
        int suf = 0;
 
        for (char c : s) {
            if (c == '1' || c == '3')
                suf++;
        }
 
        int best = pref2 + suf;
 
        for (char c : s) {
            if (c == '2')
                pref2++;
 
            if (c == '1' || c == '3')
                suf--;
 
            best = max(best, pref2 + suf);
        }
 
        cout << (int)s.size() - best << '
';
    }
 
    return 0;
}