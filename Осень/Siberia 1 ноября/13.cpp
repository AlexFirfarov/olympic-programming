// Wrong answer

#include <iostream>
#include <set>

int main() {
    int n, k, m;
    std::cin >> n >> k >> m;
    std::set<int> f_pob;
    for (int i = 0; i < k; ++i) {
        int idx;
        std::cin >> idx;
        f_pob.insert(idx);
    }
    std::set<int> f_pob_new(f_pob);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        if (f_pob_new.count(b)) {
            f_pob_new.insert(a);
        }
        std::cout << f_pob_new.size() << "\n";
    }
}