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
	cin >> ans;
	
	int vowels = 0;
	int cons = 0;
	int neither = 0;

	for (int i = 0; i < ans.size(); ++i) {
		if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') {
			vowels += 1;
		}
		else if (ans[i] == 'y') {
			neither += 1;
		}
		else {
			cons += 1;
		}
	}
	
	int step = 0;

	while (vowels <= cons) {
		if (cons > 0) {
			cons -= 1;
			vowels += 1;
			step += 1;
		}
		else if (neither > 0) {
			neither -= 1;
			vowels += 1;
			step += 1;
		}
	}

	cout << step;
}