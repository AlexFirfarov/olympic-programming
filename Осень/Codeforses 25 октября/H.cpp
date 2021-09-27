#include <iostream>

int main() {
    unsigned long long N;
    std::cin >> N;
    unsigned long long x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    unsigned long long min = 0;
    for (unsigned long long x = 0; x <= N; ++x) {
        unsigned long long t1 = 0;
        unsigned long long t2 = 0;
        if (x > 0) {
            t1 = x * x1 + y1 * (x - 1);
        }
        if (x < N) {
            t2 = (N - x) * x2 + y2 * (N - x - 1);
        }
        unsigned long long t = t1 + t2;
        if (min == 0 || t < min) min = t;
    }
    std::cout << min << "\n";
}