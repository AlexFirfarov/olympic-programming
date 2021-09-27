// TIME LIMIT

#include <iostream>
#include <string>
#include <set>

using ll = long long;
using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, k, res = 0;
        string a, b;
        cin >> n >> m >> k;
        cin >> a >> b;
        char first, last;
        set<pair<ll, ll>> st;
        for (ll i = 0; i < n - k + 1; ++i) {
            first = a[i];
            last = a[i + k - 1];
            for (ll j = 0; j < m; ++j) {
                if (b[j] == first) {
                    for (ll z = j; z < m; ++z) {
                        if (b[z] == last) {
                            if (!st.count({j, z})) {
                                ++res;
                                st.insert({j, z});
                            }
                        }
                    }
                }
            }
        }
        std::cout << res << "\n";
    }
}