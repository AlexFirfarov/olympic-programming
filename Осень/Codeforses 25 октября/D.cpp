#include <iostream>

int main() {
    unsigned long long n, m;
    std::cin >> n >> m;
    bool ok = true;
    unsigned long long s = 0;
    for (unsigned long long i = 0; i < n; ++i) {
        unsigned long long tmp;
        std::cin >> tmp;
        s += tmp;
    }
    if (s % m) ok = false;
    if (ok) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}