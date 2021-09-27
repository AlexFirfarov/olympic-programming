#include <iostream>
#include <iomanip>

int main() {
    int n, k, tmp;
    std::cin >> n >> k;
    int sum_i = 0;
    double min, max;
    int diff = n - k;

    for (int i = 0; i < k; ++i) {
        std::cin >> tmp;
        sum_i += tmp;
    }

    min = sum_i;
    max = sum_i;

    for (int i = 0; i < diff; ++i) {
        min -= 3;
        max += 3;
    }

    std::cout << std::setprecision(10) << min / n << " " << max / n << "\n";

}