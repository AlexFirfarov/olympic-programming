// WRONG ANSWER

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {

    int n, k, res = 0;
    std::cin >> n >> k;
    std::vector<std::string> v(n);

    if (n == 1) {
        std::cout << k << "\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    std::string f = v[0];
    for (int i = 0; i < k; ++i) {
        bool ok = true;
        for (int j = 1; j < n; ++j) {
            if (f[i] != v[j][i]) {
                ok = false;
                break;
            }
        }
        if (ok)
            ++res;
    }

    std::cout << res << "\n";
}