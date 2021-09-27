#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<cmath>
 
 
using namespace std;
 
int main() {
	int N = 1;
	while (1) {
		cin >> N;
        std::cin.ignore(1);
        if (N == 0) break;
        vector<string> text(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, text[i], '\n');
            text[i].resize(100, ' ');
		}
		int curX = 0;
		int curY = 0;
		while (curY < N) {
			if (text[curY][curX] == ' ') {
				curY += 1;
			}
			else {
				curX += 1;
			}
		}
		cout << curX + 1 << "\n";
	}
 
	return 0;
}