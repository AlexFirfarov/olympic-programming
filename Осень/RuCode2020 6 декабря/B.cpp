// WRONG ANSWER

#include<iostream>
#include<string>

using namespace std;

int main() {
	int n;
	cin >> n;
	string start;
	start = "80";
	for (int i = 2; i <= n; ++i) {
		start += "01"; 
	}
	cout << start;

}