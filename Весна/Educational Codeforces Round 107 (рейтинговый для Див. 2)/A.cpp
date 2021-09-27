#include <iostream>

void solve() {
    int n, res = 0, tmp;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        if (tmp == 1 || tmp == 3) ++res;
    }

    std::cout << res << "\n";
}

int main() {

    int t;
    std::cin >> t;
    while (t--)
        solve();
}