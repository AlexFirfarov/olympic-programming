#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, max = 0, res;
    bool m = true;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) { 
        std::cin >> v[i];
        if (v[i] > max || m) {
            max = v[i];
            m = false;
        }
    }
    res = std::count(v.begin(), v.end(), max);
    std::cout << n - res << "\n";
}