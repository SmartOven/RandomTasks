#include <iostream>
#include <vector>
using std::cin;
using std::cout;

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int a = 0;
        for (int i : nums)
            a ^= i;
        return a;
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
    cout << S1.singleNumber(v) << "\n";
	return 0;
}