#include <iostream>
#include <unordered_map>
#include <vector>

int main() {

    unsigned long long n, m, sd;
    unsigned long long cur_res = 0;
    std::cin >> n >> m;
    std::vector<unsigned long long> res(m);
    std::unordered_map<unsigned long long, unsigned long long> um;

    for (unsigned long long i = 0; i < m; ++i) {
        std::cin >> sd;

        if (i != 0 && !um.count(sd))
            um[sd] = i;

        cur_res -= um[sd];
        cur_res += (n - 1);
        for (auto& pr : um) {
            pr.second += 1;
        }
        um[sd] = 0;
        res[i] = cur_res;
    }

    std::cout << "\n";
    for (unsigned long long i = 0; i < m; ++i) {
        std::cout << res[i] << "\n";
    }
}