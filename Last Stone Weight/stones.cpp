#include <algorithm>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
		std::sort(stones.begin(), stones.end());
    	while (stones.size() >= 2 && stones[stones.size() - 2] > 0) {
	        const size_t n = stones.size();
			stones[n - 1] -= stones[n - 2];
			stones[n - 2] = 0;
			std::sort(stones.begin(), stones.end());
		}
		return stones[stones.size() - 1];
    }
};

int main() {
	size_t n;
	cin >> n;
	std::vector <int> v(n);
	for (auto& el : v)
		cin >> el;
	Solution S1;
	cout << S1.lastStoneWeight(v) << "\n";
	return 0;
}