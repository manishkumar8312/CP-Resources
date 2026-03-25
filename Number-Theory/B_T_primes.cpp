#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n){
    if(n==1|| n==0) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    if(checkPrime(n-2)){
        cout << "2 " << n-2<<"\n";
    }else{
        cout << "-1" <<"\n";
    }

}