// WRONG ANSWER

#include <iostream>
#include <algorithm>
#include <cmath>

using ull = unsigned long long;

ull binpow (ull a, ull n) {
	ull res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    ull MOD = 1e9 + 7;
    ull q;
    std::cin >> q;
    while(q--) {
        ull i_1, i_2, j_1, j_2, sum = 0;
        std::cin >> i_1 >> i_2 >> j_1 >> j_2;

        for (ull i = i_1; i <= std::min(ull(34), i_2); ++i)
            for (ull j = j_1; j <= std::min(ull(23), j_2); ++j) {
                ull tmp = ((ull(pow(2, i)) % MOD) * (ull(pow(3, j)) % MOD)) % MOD;
                sum = ((sum % MOD) + (tmp % MOD)) % MOD;
            }
        std::cout << sum % MOD << "\n";
    }
}