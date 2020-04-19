#include <iostream>
#include <vector>
using std::cin;
using std::cout;

class Solution {
public:
	int search(std::vector<int>& nums, int target) {
		const int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left <= right) {
	        const int middle = left - (left - right) / 2; // = left - left/2 + right/2 = (left + right) / 2 (but it fits in <int>)
            if (target == nums[middle])
                return middle;
        	
            if (nums[middle] >= nums[left]) {
                if (nums[middle] >= target && nums[left] <= target)
                    right = middle - 1;
                else
            		left = middle + 1;
            }
            else {
                if (nums[middle] <= target && target <= nums[right])
                    left = middle + 1;
                else
            		right = middle - 1;
            }
        }
        return -1;
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
	int t;
	cin >> t;
	cout << S1.search(v, t) << "\n";
	return 0;
}