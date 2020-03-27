#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using std::cin;
using std::cout;

int main() {
    size_t n, sum = 0;
    int prodano = 0;
    cin >> n;
    std::vector <std::pair <int, int>> price_hair(n);
    for (size_t i = 0; i < n; i++) {
        cin >> price_hair[i].first;
        price_hair[i].second = i + 1;
    }
    sort(price_hair.begin(), price_hair.end());
    for (int i = price_hair.size() - 1; i >= 0; i--) {
        int hl = std::max(price_hair[i].second - prodano, 0);
        sum += price_hair[i].first * hl;
        prodano += hl;
    }
    cout << sum << "\n";
    return 0;
}
