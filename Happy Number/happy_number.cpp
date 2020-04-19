#include <iostream>
using std::cin;
using std::cout;

class Solution {
public:
	bool isHappy(int n) {
		if (n == 0)
			return false;
		int counter = 100;
		while (counter--) {
			int sum = 0;
			while (n > 0) {
				int x = n % 10;
				sum += x * x;
				n /= 10;
			}
			if (sum == 1)
				return true;
			n = sum;
		}
		return false;
	}
};

auto gucciGang = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

int main() {
	int n;
	cin >> n;
	Solution S1;
	cout << S1.isHappy(n) << "\n";
	return 0;
}