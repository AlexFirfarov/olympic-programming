#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::set<std::vector<int>> s;
        for (int i = 0; i < n; ++i) {
            std::vector<int> v(n);
            for (int j = 0; j < n; ++j) {
                std::cin >> v[j];
            }
            s.insert(v);
        }
        int res = 0;
        for (const std::vector<int>& v: s) {
            res += std::count(begin(v), end(v), 1) - 1;
        }
        std::cout << res << "\n";
    }
}