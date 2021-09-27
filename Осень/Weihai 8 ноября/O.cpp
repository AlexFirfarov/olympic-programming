#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int num;
	cin >> num;
	vector<string> words(num);
	for (int i = 0; i < num; ++i) {
		cin >> words[i];
		reverse(words[i].begin(), words[i].end());
	}

	sort(words.begin(), words.end());

	for (int i = 0; i < num; ++i) {
		cout << words[i] << "\n";
	}
}

