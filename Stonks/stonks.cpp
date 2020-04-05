#include <iostream>
#include <vector>
using std::cin;
using std::cout;

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        size_t ans = 0;
        for (size_t i = 1; i < prices.size(); i++)
            // Every time it goes up - we buy it yesterday and sell it today
            if (prices[i] - prices[i - 1] > 0)
                ans += prices[i] - prices[i - 1];
        return ans;
    }
};

int main() {
    // Uncomment to file input
    // freopen("input.txt", "r", stdin);

    // Uncomment to file output
    // freopen("output.txt", "r", stdout);

    Solution S1;
    size_t n;
    cin >> n;
    std::vector <int> v(n);
    for (auto& i : v)
        cin >> i;
    cout << S1.maxProfit(v) << "\n";
    return 0;
}