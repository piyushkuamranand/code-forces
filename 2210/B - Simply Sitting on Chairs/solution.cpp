#include <iostream>
#include <vector>
using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
 
using ll = long long;
using vll = vector<ll>;
 
void solve(){
 
    ll n;
    cin >> n;
 
    vll a(n);
 
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
 
    ll count = 0;
 
    for(int i = 0; i < n; i++){
        if(a[i] <= i + 1){
            count++;
        }
    }
 
    cout << count << "
";
}
 
int main(){
    fastio;
 
    int t;
    cin >> t;
 
    while(t--){
        solve();
    }
 
    return 0;
}