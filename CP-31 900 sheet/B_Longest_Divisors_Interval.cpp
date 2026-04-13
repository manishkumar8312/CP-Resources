/*  
    CodeForces: B. Longest Divisors Interval

    Problem Link: https://codeforces.com/contest/1855/problem/B
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n; cin >> n;
    ll i = 1;
    while(n%i==0){
        i++;
    } 
    cout << i-1 <<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}