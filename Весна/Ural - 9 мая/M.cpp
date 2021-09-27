//Wrong answer
#include <algorithm>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;


string inverses(string inBr) {
	string res = "";
	int sz = inBr.size();
	for (int i = 0; i < sz; ++i) {
		if (inBr[sz - 1 - i] == '(') {
			res += ')';
		}
		else if (inBr[sz - 1 - i] == ')') {
			res += '(';
		}
		else if (inBr[sz - 1 - i] == '[') {
			res += ']';
		}
		else if (inBr[sz - 1 - i] == ']') {
			res += '[';
		}
		else if (inBr[sz - 1 - i] == 'b') {
			res += 'd';
		}
		else if (inBr[sz - 1 - i] == 'd') {
			res += 'b';
		}
		else if (inBr[sz - 1 - i] == 'o') {
			res += 'o';
		}
		else if (inBr[sz - 1 - i] == 'x') {
			res += 'x';
		}
		else if (inBr[sz - 1 - i] == 'p') {
			res += 'q';
		}
		else if (inBr[sz - 1 - i] == 'q') {
			res += 'p';
		}
	}
	return res;
}

string inverses2(string inBr) {
	string res = "";
	int sz = inBr.size();
	for (int i = 0; i < sz; ++i) {
		if (inBr[i] == '[') {
			res += '[';
		}
		else if (inBr[i] == ']') {
			res += ']';
		}
		else if (inBr[i] == 'b') {
			res += 'p';
		}
		else if (inBr[i] == 'd') {
			res += 'q';
		}
		else if (inBr[i] == 'o') {
			res += 'o';
		}
		else if (inBr[i] == 'x') {
			res += 'x';
		}
		else if (inBr[i] == 'p') {
			res += 'b';
		}
		else if (inBr[i] == 'q') {
			res += 'd';
		}
	}
	return res;
}


string revInBr(string a, int i, int &end) {
	int u = 1;
	int t = 1;
	string inBr = "";
	while (u > 0) {
		if (a[i + t] == '(') {
			u += 1;
			int end = 0;
			inBr += revInBr(a, i + t, end);
			t += end;
		}
		else if (a[i + t] == ')') {
			u -= 1;
		}
		else {
			inBr += a[i + t];
			t += 1;
		}
	}
	string newInBr = inverses(inBr);
	end = t;
	return newInBr;
}

string revInBr2(string a, int i, int& end) {
	int u = 1;
	int t = 1;
	string inBr = "";
	while (u > 0) {
		if (a[i + t] == '[') {
			u += 1;
			int end = 0;
			inBr += revInBr2(a, i + t, end);
			t += end;
		}
		else if (a[i + t] == ']') {
			u -= 1;
		}
		else {
			inBr += a[i + t];
			t += 1;
		}
	}
	string newInBr = inverses2(inBr);
	end = t;
	return newInBr;
}

int main() {
	string a;
	string b = "";
	string c = "";
	cin >> a;


	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == '(') {
			int end = 0;
			b += revInBr(a, i, end);
			i += end;
		}
		else if (a[i] != ')') {
			b += a[i];
		}
	}

	for (int i = 0; i < b.size(); ++i) {
		if (b[i] == '[') {
			int end = 0;
			c += revInBr2(b, i, end);
			i += end;
		}
		else if (b[i] != ']') {
			c += b[i];
		}
	}

	cout << c;
}