// Time limit

#include <iostream>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <array>


int main() {
    unsigned long long t;
    std::cin >> t;
    std::unordered_map<unsigned long long, std::unordered_set<unsigned long long>> pr;
    std::vector<unsigned long long> pr_prime;
    while(t--) {
        std::unordered_set<unsigned long long> d;
        unsigned long long n, n_f;
        std::cin >> n;
        n_f = n;
        if (n == 1) {
            std::cout << 0 << "\n";
            continue;
        }

        for (const unsigned long long& del: pr_prime) {
            if (n % del == 0 && del != 1 && del != n_f) {
                d.insert(del);
                n /= del;
            }
        }

        for (const auto& [del, v]: pr) {
            if (n % del == 0 && del != 1 && del != n_f) {
                for (const auto& el: v) {
                    d.insert(el);
                }
                n /= del;
            }
        }

        for (unsigned long long i = 2; i < std::sqrt(n)+0.0000001; ) {
            if (n % i == 0) {
                d.insert(i);
                n /= i;
            } else {
                ++i;
            }
        }
        if (n > 1) d.insert(n);
        if (d.size() == 1 && d.count(n_f)) {
            std::cout << "Prime\n";
            pr_prime.push_back(n_f);
        } else {
            unsigned long long size = d.size();
            if (d.count(n_f)) --size;
            if (d.count(1)) -- size;
            std::cout << size << "\n";
            for (const auto& el: d) {
                pr[n_f].insert(el);
            }
        }
    }
}