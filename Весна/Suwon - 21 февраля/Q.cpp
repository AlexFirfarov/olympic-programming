#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> c(n + 1);
	c[0] = 0;
	for (int i = 1; i < n + 1; ++i)
		std::cin >> c[i];
	std::vector<std::vector<int>> d(k + 1);
	for (int i = 0; i < k + 1; ++i)
		d[i].resize(m + 1);
	std::vector<std::vector<std::pair<int,int>>> p(k + 1);
	for (int i = 0; i < k + 1; ++i)
		p[i].resize(m + 1);
	d[0][0] = 0;
	p[0][0] = std::pair<int, int>(0, 0);
	int maxC = 0;
	std::pair<int,int> pairC = std::pair<int, int>(0, 0);
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j <= m; ++j) {
			int pos = i * 2 + j;
			if (pos > n)
				break;
			int max = 0;
			std::pair<int, int> pair = std::pair<int, int>(0, 0);
			if (i - 1 >= 0) {
				max = d[i - 1][j];
				pair = std::pair<int, int>(i-1, j);
			}
			if (j - 1 >= 0) {
				if (max < d[i][j - 1]) {
					max = d[i][j - 1];
					pair = std::pair<int, int>(i, j - 1);
				}
			}
			d[i][j] = c[pos] + max;
			p[i][j] = pair;
			if (maxC < d[i][j]) {
				maxC = d[i][j];
				pairC = std::pair<int, int>(i, j);
			}
		}
	}
	/*for (int i = 0; i <= k; ++i) {
		for (int j = 0; j <= m; ++j)
			std::cout << d[i][j] << " ";
		std::cout << std::endl;
	}*/
	std::cout << maxC << std::endl;
	std::vector<int> v;
	for (std::pair<int, int> i = pairC; i != std::pair<int,int>(0,0);) {
		//std::cout << i.first * 2 + i.second << " ";
		v.push_back(i.first * 2 + i.second);
		i = p[i.first][i.second];
	}
	v.push_back(0);
	for (auto it = v.rbegin(); it != v.rend(); ++it)
		std::cout << *it << " ";
	return 0;
}