#include <iostream>
#include <queue>
#include <vector>
using std::cin;
using std::cout;

class Solution {
public:
	std::string stringShift(std::string s, std::vector<std::vector<int>>& shift) {
		// Input
		std::queue<char> str;
		std::string new_s;
		for (auto ch : s)
			str.push(ch);
		// Algorithm
		int amount = 0;
		for (auto& sh : shift) {
			if (sh[0])
				amount += sh[1];
			else
				amount -= sh[1];
		}
		if (amount > 0) {
			amount %= str.size();
			amount = str.size() - amount;
		}
		else {
			amount *= -1;
			amount %= str.size();
		}
		for (size_t i = 0; i < amount; i++) {
			char buffer = str.front();
			str.pop();
			str.push(buffer);
		}
		// Output
		while (!str.empty()) {
			new_s += str.front();
			str.pop();
		}
		return new_s;
	}
};

int main() {
	std::string s;
	cin >> s;
	size_t n;
	cin >> n;
	std::vector <std::vector <int>> v(n, std::vector <int>(2));
	for (auto& el : v)
		cin >> el[0] >> el[1];
	Solution S1;
	cout << S1.stringShift(s, v) << "\n";
	return 0;
}