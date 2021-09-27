#include <iostream>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        bool ok = true;
        ll n, diff = 0;
        cin >> n;
        string a, b;
        vector<char> diff_a, diff_b;
        cin >> a >> b;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                diff_a.push_back(a[i]);
                diff_b.push_back(b[i]);
                ++diff;
            }
        }
        for (int i = 0; i < diff; ++i) {
            if (diff_b[i] != diff_a[(i+1)%diff]) {
                ok = false;
                break;
            }
        }
        if (ok) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}