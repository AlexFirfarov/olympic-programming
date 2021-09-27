#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) 
        std::cin >> a[i];
    while(q--) {
        int t, idx;
        std::cin >> t;

        idx = std::find(a.begin(), a.end(), t) - a.begin();
        for (int i = idx; i > 0; --i) {
            std::swap(a[i], a[i - 1]);
        }
        std::cout << idx + 1 << "\n";
    }
}