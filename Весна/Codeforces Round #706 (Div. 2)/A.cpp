#include <iostream>
#include <string>

using ll = long long;

void solve() {
    ll n, k;
    std::string s;
    bool ok = true;
    std::cin >> n >> k >> s;

    for (ll i = 0; i < k; ++i) 
        if (s[i] != s[n - i - 1]) {
            ok = false;
            break;
        }
    
    if (ok && k * 2 < n) 
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

int main() {

    int t;
    std::cin >> t;
    while(t--)
        solve();
}