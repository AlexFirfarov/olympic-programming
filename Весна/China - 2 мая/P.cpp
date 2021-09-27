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
	string defaultS = "123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899100";
	int N;
	cin >> N;
	string copyS;
	cin >> copyS;
	int res = -1;
	int posD = -1;
	for (int i = 0; i < copyS.size(); ++i) {
		if (copyS[i] != defaultS[i]) {
			posD = i;
			break;
		}
	}
	if (posD == -1) {
		res = N;
	}
	else if (posD < 9) {
		res = posD + 1;
	}
	else if (posD < 189) {
		res = 10 + ((posD - 9) / 2);
	}
	else {
		res = 100;
	}

	cout << res;
}