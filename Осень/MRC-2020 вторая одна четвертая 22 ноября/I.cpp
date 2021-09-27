#include <iostream>
#include <unordered_set>
#include <cmath>

using ll = long long;

std::pair<ll, ll> square(ll x){
	ll i, j, end = (ll)(sqrt((double)x));
	for (i = 1,j = end; i <= j; i++){
		while (i * i + j * j > x) --j;
		if (i * i + j * j == x) return {i, j};
	}
	return {-1, -1};
}

int main() {
    ll s, i, j;
    std::cin >> s;
    if (double(sqrt(s)) == ll(sqrt(s))) {
        i = sqrtl(s);
        std::cout << 0 << " " << 0 << "\n"
         << i << " " << 0 << "\n"
         << i << " " << i << "\n"
         << 0 << " " << i << "\n";
        return 0;
    }
    std::pair<ll, ll> p = square(s);
    if (p.first == -1 || p.first == 0 || p.second == 0) {
        std::cout << "Impossible\n";
        return 0;
    }
    if (p.first > p.second) {
        i = p.first;
        j = p.second;
    } else {
        j = p.first;
        i = p.second;
    }
    std::cout << 0 << " " << 0 << "\n"
        << i << " " << j << "\n"
        << i - j << " " << j + i << "\n"
        << 0 - j << " " << i << "\n";
    return 0;
}