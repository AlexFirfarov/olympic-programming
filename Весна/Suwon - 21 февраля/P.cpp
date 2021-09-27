#include <iostream>
#include <string>

int main() {
    long long n, max = 1, tmp, d = 10, cur = 1;
    std::cin >> n;

    std::string s = std::to_string(n);
    tmp = n;
    while (tmp > 0) {
        max *= tmp % 10;
        tmp /= 10;
    }

    for (int i = 0; i < s.length() - 1; ++i) {
        tmp = n - n % d - 1;
        if (tmp > 0) {
            while (tmp > 0) {
                cur *= tmp % 10;
                tmp /= 10;
            }
            if (cur > max) max = cur;
        }
        d *= 10;
        cur = 1;
    }
    std::cout << max << "\n";
}