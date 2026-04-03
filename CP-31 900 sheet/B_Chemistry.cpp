/* A. Chemistry! - Codeforces 1883B

    Problem Link: https://codeforces.com/problemset/problem/1883/B
*/


#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    string str;
    cin >> str;
    vector<int> freq(26,0);
    for(int i=0;i<n;i++){
        freq[str[i]-'a']++;
    }
    int Oddfreq = 0;
    for(int i=0;i<26;i++){
        Oddfreq += freq[i] % 2;

    }
    if(Oddfreq > k+1){
        cout << "NO\n";
    }else{
        cout << "YES\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}