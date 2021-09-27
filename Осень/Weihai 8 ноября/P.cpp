#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int guess, begin, end;
	cin >> guess >> begin >> end;
	int iters = 0;
	int gNum = -1;
	while (gNum != guess) {
		gNum = (begin + end) / 2;
		if (gNum > guess) {
			end = gNum;
		}
		if (gNum < guess) {
			begin = gNum;
		}
		iters += 1;
	}
	cout << iters;
}

