#include <iostream>
#include <vector>
#include <string>

int main() {
	std::vector<std::string> v(25);
	v[0] = "ITMO";
	v[1] = "SPbSU";
	v[2] = "SPbSU";
	v[3] = "ITMO";
	v[4] = "ITMO";
	v[5] = "SPbSU";
	v[6] = "ITMO";
	v[7] = "ITMO";
	v[8] = "ITMO";
	v[9] = "ITMO";
	v[10] = "ITMO";
	v[11] = "PetrSU, ITMO";
	v[12] = "SPbSU";
	v[13] = "SPbSU";
	v[14] = "ITMO";
	v[15] = "ITMO";
	v[16] = "ITMO";
	v[17] = "ITMO";
	v[18] = "SPbSU";
	v[19] = "ITMO";
	v[20] = "ITMO";
	v[21] = "ITMO";
	v[22] = "ITMO";
	v[23] = "SPbSU";
	v[24] = "ITMO";

	int n;
	std::cin >> n;
	std::cout << v[n - 1995];

	return 0;
}