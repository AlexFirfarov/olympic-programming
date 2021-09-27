//WRONG ANSWER

#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int main() {
    ll n, max = 0, ans;
    std::cin >> n;
    std::vector<ll> cards(n);
    for (ll i = 0; i < n; ++i) {
        std::cin >> cards[i];
    }
    std::sort(begin(cards), end(cards));
    std::vector<ll> diff(n - 1);
    for (ll i = 1; i < n; ++i) {
        diff[i - 1] = cards[i] - cards[i - 1];
        if (diff[i - 1] > max)
            max = diff[i - 1];
    }
    if (max >= cards[1] || max < cards[0]) {
        std::cout << 0 << "\n";
        return 0;
    }
    ans = max;
    for (ll i = 0; i < n - 2; ++i) {
        if (cards[i + 2] - cards[i] <= ans) {
            std::cout << 0 << "\n";
            return 0;
        }
    }
    std::cout << ans << "\n";
}