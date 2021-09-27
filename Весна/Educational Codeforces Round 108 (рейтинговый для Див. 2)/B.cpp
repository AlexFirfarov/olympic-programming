#include <iostream>

using ll = long long;

void solve() {

    ll n, m, k;
    std::cin >> n >> m >> k;

    if (k == n * m - 1) 
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

int main() {

    int t;
    std::cin >> t;
    while (t--)
        solve();
}