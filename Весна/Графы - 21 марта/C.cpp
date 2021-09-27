#include <iostream>
#include <unordered_map>
#include <vector>

using ll = long long;

int main() {
    ll n, l, r, res = 0;
    std::cin >> n;
    std::unordered_map<ll, std::vector<ll>> m;
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> l >> r;
        m[l].push_back(r);
        m[r].push_back(l);
    }
    for (int i = 2; i <= n; ++i) {
        if (m[i].size() == 1 && m[i][0] != 1) {
            ll v = m[i][0];
            if (m[v].size() == 2) ++res;
        }
    }
    std::cout << res << "\n";
}