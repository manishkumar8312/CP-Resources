#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (n == 1) {
            cout << "NO\n";
            continue;
        }

        bool allEqual = true;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[0]) {
                allEqual = false;
                break;
            }
        }

        if (allEqual) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}