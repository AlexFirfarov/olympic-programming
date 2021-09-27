#include <iostream>
#include <unordered_set>
#include <algorithm>

void solve() {

    int n, k, mex = 0, max = 0, tmp, ts;
    std::unordered_set<int> a(n);
    bool ok = false;
    std::cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        a.insert(tmp);
        max = std::max(max, tmp);
    }

    for (ts = k; ts > 0; --ts) {
        for (;;++mex) {
            if (!a.count(mex))
                break;
        }

        if (mex == max + 1) {
            ok = true;
            break;
        }

        tmp = (max + mex + 1) / 2;
        if (!a.count(tmp)) {
            a.insert(tmp);
            if (mex != tmp)
                break;
        } else 
            break;
    }

    std::cout << a.size() + int(ok) * ts << "\n";
} 

int main() {

    int t;
    std::cin >> t;
    while(t--)
        solve();
}