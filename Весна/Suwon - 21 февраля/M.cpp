#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<cmath>


using namespace std;

int my_abs(int N) {
	if (N < 0) {
		return -N;
	}
	else return N;
}

int main() {
	int A, B, C, D;
	while (true) {
		cin >> A >> B >> C >> D;
		if (A == 0 && B == 0 && C == 0 & D == 0) {
			break;
		}
		int iters = 0;
		int dA = A; int dB = B; int dC = C; int dD = D;
		while (!(dA == dB && dB == dC && dC == dD && dD == dA)) {
			int xA = my_abs(dA - dB);
			int xB = my_abs(dB - dC);
			int xC = my_abs(dC - dD);
			int xD = my_abs(dD - dA);
			iters += 1;
			dA = xA; dB = xB; dC = xC; dD = xD;
		}
		cout << iters << "\n";
	}


}