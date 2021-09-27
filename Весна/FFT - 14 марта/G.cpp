#include <iostream>

using ll = long long;

int main() {
    ll t;
    std::cin >> t;
    while(t--) {
        ll n, x, y, w;
        std::cin >> n >> x >> y;
        w = n / 2;
        if (y < w || x < w + 1) 
            std::cout << "NO\n";
        else
            std::cout << "YES\n"; 
    }
}