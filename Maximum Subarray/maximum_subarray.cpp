#include <iostream>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;

class Solution {
public:
	int maxSubArray(std::vector<int>& nums) {
		int result = nums[0];
		const int size = nums.size();
        for (size_t i = 1; i < size; i++) {
            if (nums[i - 1] > 0)
                nums[i] += nums[i - 1];
        }
        for (size_t i = 1; i < size; i++) {
            result = std::max(result, nums[i]);
        }
        return result;
	}
};

auto gucciGang = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

int main() {
	size_t n;
	cin >> n;
	std::vector <int> v(n);
	for (auto& i : v)
		cin >> i;
	Solution S1;
	cout << S1.maxSubArray(v) << "\n";
	return 0;
}