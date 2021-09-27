#include <iostream>
#include <vector>
#include <cmath>

using ll = unsigned long long;

int main() {
	ll n, x;
	while (std::cin >> n >> x) {

		std::vector<ll> a(n), b(n);
		for (ll i = 0; i < n; ++i)
			std::cin >> a[i];
		for (ll i = 0; i < n; ++i)
			std::cin >> b[i];
		ll ans = x;
		for (ll i = 0; i < n; ++i)
			ans += ((a[i] % (1000000000 + 7)) * (b[i] % (1000000000 + 7))) % (1000000000 + 7);
		for (ll i = 0; i < n - 1; ++i)
			ans = ((ans % (1000000000 + 7)) * (x % (1000000000 + 7))) % (1000000000 + 7);
		std::cout << ans % (1000000000 + 7) << std::endl;
	}
	return 0;
}