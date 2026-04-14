/*

    Codeforces: Prefix Sum Primes - 1149/problem/A
    Problem Link: https://codeforces.com/contest/1149/problem/

*/


#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0);

void solve(){
    int n; cin >> n;
    int ones = 0, twos = 0;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        if(x==1) ones++;
        else twos++;
    }
    if(twos==0){
        for(int i=0;i<ones;i++) cout << "1 ";
    }else if(ones == 0){
        for(int i=0;i<twos;i++) cout << "2 ";
    }else{
        cout << "2 1 ";
        for(int i=0;i<twos-1;i++) cout << "2 ";
        for(int i=0;i<ones-1;i++) cout << "1 ";

    }
}

int32_t main(){
    fast;
    solve();
}