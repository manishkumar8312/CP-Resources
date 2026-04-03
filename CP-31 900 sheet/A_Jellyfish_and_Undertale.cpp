/*
    A. JellyFish and UnderTale Codeforces 1875 A
    Problem Link: https://codeforces.com/problemset/problem/1875/A
 */

#include <bits/stdc++.h>
using namespace std;    
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        long long a,b,n;
        cin >> a >> b >> n;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        long long maxTime = b;
        for(int i=0;i<n;i++){
            maxTime += min(arr[i],a-1);
        }
        cout << maxTime << "\n";
    }
    return 0;
}