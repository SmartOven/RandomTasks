#include <iostream>
#include <queue>
#include <vector>
using std::cin;
using std::cout;

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        for (size_t first_zero = 0, cur = 0; cur < nums.size(); cur++)
            if (nums[cur] != 0)
	            std::swap(nums[first_zero++], nums[cur]);
    }
};

int main() {
    // Uncomment to file input
    // freopen("input.txt", "r", stdin);

    // Uncomment to file output
    // freopen("output.txt", "r", stdout);

    size_t n;
    cin >> n;
    std::vector <int> v(n);
    for (int& i : v)
        cin >> i;
    Solution S1;
    S1.moveZeroes(v);
    for (int i : v)
        cout << i << ' ';
    return 0;
}