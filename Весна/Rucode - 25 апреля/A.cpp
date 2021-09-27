#include <iostream>

int main() {
    int n, L, t_i, d_i, res_1 = 0, res_2 = 0;
    std::cin >> n >> L;
    while(n--) {
        std::cin >> t_i >> d_i;
        if (t_i == 1) {
            if (d_i == -1) res_1 += 1;
            else if (d_i < L) res_1 += 2;
            else res_1 += 3;
        } else {
            if (d_i == -1) res_2 += 1;
            else if (d_i < L) res_2 += 2;
            else res_2 += 3;
        }
    }
    std::cout << res_1 << ":" << res_2 << "\n";
}