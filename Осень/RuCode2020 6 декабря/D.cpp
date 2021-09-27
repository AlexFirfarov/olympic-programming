#include <iostream>
#include <cmath>

int main() {
    int n, m, min, max, c;
    std::cin >> n >> m;

    c = (int)std::sqrt(m);
    bool ok = false;
    while(c + 1 <= n) {
        if (((2 + (c - 1)) * c) / 2 < m) {
            ++c;
        } else {
            ++c;
            ok = true;
            break;
        }
    }
    if (!ok) {
        std::cout << -1 << "\n";
        return 0;
    }
    max = 1 + (n - c);
    min = 1 + (n - (m + 1));
    if (min <= 0) {
        min = 1;
    }
    std::cout << min << " " << max << "\n";
}