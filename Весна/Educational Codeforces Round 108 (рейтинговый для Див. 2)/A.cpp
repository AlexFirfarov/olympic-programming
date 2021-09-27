#include <iostream>
#include <algorithm>

void solve() {
    unsigned long long r, b, d, min, max;
    std::cin >> r >> b >> d;

    if (r < b) {
        max = b;
        min = r;
    } else {
        max = r;
        min = b;
    }

    if (max > min * (d + 1))
        std::cout << "NO\n";
    else 
        std::cout << "YES\n";
}

int main() {

    int t;
    std::cin >> t;
    while (t--)
        solve();
}