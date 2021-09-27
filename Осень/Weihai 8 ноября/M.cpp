#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> pairs(N);
	for (int i = 0; i < N; ++i) {
		cin >> pairs[i];
	}
	sort(pairs.begin(), pairs.end());
	int lowestRating = -1;
	for (int u = 0; u < N / 2; ++u) {
		if (lowestRating == -1) {
			lowestRating = pairs[u] + pairs[N - 1 - u];
		}
		lowestRating = min(lowestRating, pairs[u] + pairs[N - 1 - u]);
	}
	cout << lowestRating;
}

