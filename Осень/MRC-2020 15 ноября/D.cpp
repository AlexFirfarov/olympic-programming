// TIME LIMIT

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    long long n, m, num, cnt = 0, tmp, step = 1;
    std::cin >> n >> m;
    if (n % 2 == 0 && n > 2) {
        ++n;
    }
    if (n > 2) step = 2;
    for (long long i = n; i < m + 1; i += step) {
        if ((i > 9) && (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0 || i % 9 == 0)) continue;
        bool ok = true;
        tmp = i;
        while (tmp) {
            num = tmp % 10;
            if (num == 0 || num == 1 || num == 4 || num == 6 || num == 8 || num == 9) {
                ok = false;
                break;
            }
            tmp /= 10;
        }
        if (ok) {++cnt;}
        
    }
    std::cout << cnt << "\n";

}