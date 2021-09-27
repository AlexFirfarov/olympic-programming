#include <iostream>

int main() {
    int a, x, b, y, t;
    std::cin >> a >> x >> b >> y >> t;
    int ans1, ans2, diff1 = 0, diff2 = 0;
    if (t > 30) {
        diff1 = t - 30;
    }
    if (t > 45) {
        diff2 = t - 45;
    }
    ans1 = 21 * diff1 * x + a;
    ans2 = 21 * diff2 * y + b;
    std::cout << ans1 << " " << ans2 << "\n";
}