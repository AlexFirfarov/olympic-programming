#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int num;
		cin >> num;
		int maxMin = 0;
		int nowInBus = 0;
		for (int j = 0; j < num; ++j) {
			int a, b;
			cin >> a >> b;
			nowInBus += a - b;
			if (nowInBus < maxMin) {
				maxMin = nowInBus;
			}
		}
		cout << -maxMin << "\n";
	}

}