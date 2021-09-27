// WRONG ANSWER

#include <iostream>

int main() {
    unsigned long long test;
    std::cin >> test;
    while (test--) {
        unsigned long long n, x, t;
        std::cin >> n >> x >> t;
        if (t >= x) {
            std::cout << n * 4 * t << "\n";
        } else {
            unsigned long long time = t * n * 2;
            if (true) {
                unsigned long long tmp = 0;
                bool k = false;
                if (x >= n * 2 * t) {
                    tmp = x - n * 2 * t;
                    k = true;
                }
                if (k) {
                    time += tmp + t;
                    //time += (x - (n * 2 - 1) * t);
                    time += t * n * 2;
                } else {
                    unsigned long long tmp = 0;
                    unsigned long long ad = 0;
                    if (x > ((n * 2 - 2) * t)) tmp = x - (n * 2 - 2) * t;
                    if (x > n * 2 * t) ad = x - n * 2 * t;
                    if (tmp > 0) {
                        if (t + ad < tmp) {
                            time += t + ad;
                        } else {
                            time += tmp;
                        }
                        time += t * n * 2;
                    } else {
                        time += t * n * 2;
                    }
                }
            }
            std::cout << time << "\n";
        }
    }
}