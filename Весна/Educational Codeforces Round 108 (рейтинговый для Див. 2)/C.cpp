#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {

    ll n;
    std::cin >> n;
    std::vector<ll> u(n), s(n), res(n);
    std::vector<std::vector<ll>> bs(n); 

    for (int i = 0; i < n; ++i) {
        std::cin >> u[i];
        --u[i];
    }

    for (int i = 0; i < n; ++i)
        std::cin >> s[i];

    for (int i = 0; i < n; ++i) {
        bs[u[i]].push_back(s[i]);
    }

    for (int i = 0; i < n; ++i)
        std::sort(bs[i].rbegin(), bs[i].rend());

    std::vector<std::vector<ll>> pr(n, std::vector<ll>(1, 0));

    for (int i = 0; i < n; ++i) {
        for (ll el : bs[i]) {
            pr[i].push_back(pr[i].back() + el);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= bs[i].size(); ++j) {
            res[j - 1] += pr[i][bs[i].size() / j * j];
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << res[i] << " ";
    }
    std::cout << "\n";
}

int main() {

    int t;
    std::cin >> t;
    while (t--)
        solve();
}