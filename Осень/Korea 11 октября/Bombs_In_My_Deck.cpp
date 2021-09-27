#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (b * 5 < c) {
        std::cout << 1 << "\n";
        return 0;
    }
    int cards = a - b;
    double res = (double)cards / a;
    double b_pr = 1;
    for (int i = 1; c - 5 * i > 0; ++i) {
        b_pr *= (double)(b - i + 1) / (a - i + 1);
        res += b_pr * ((double)(cards) / (a - i));
    }
    std::cout << res << "\n";
}