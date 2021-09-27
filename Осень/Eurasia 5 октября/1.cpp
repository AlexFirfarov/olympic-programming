#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n, m, r, c, s;
        std::cin >> n >> m >> r >> c >> s;
        if ((r - s > 1 && m - s > c) || (c - s > 1 && n - s > r)) {
            std::cout << "Barsik\n";
        } else {
            std::cout << "Tuzik\n";
        }
    }
}