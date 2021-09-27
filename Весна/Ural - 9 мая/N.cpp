#include <algorithm>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;


int main() {
	string ans;
	
	ans = "";

	int a, b;
	cin >> a >> b;

	if (a == 1) {
		ans += '1';
		for (int k = 0; k < b; ++k) {
			ans += '0';
		}
	}
	else {
		int g = b - a + 1;
		int l = a - 1;
		for (int x = 0; x < g; ++x) {
			ans += '9';
		}
		for (int x = 0; x < l; ++x) {
			ans += '0';
		}
	}

	cout << ans;
}