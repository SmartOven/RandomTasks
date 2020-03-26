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
    // vector <int> hair(n);
	// {1, 2, 3, 4, 5, 6}
	// {0, 0, 0, 1, 2, 3}
    std::vector <std::pair <int, int>> price_hair(n);
    for (size_t i = 0; i < n; i++) {
        cin >> price_hair[i].first;
        price_hair[i].second = i + 1;
        // hair[i] = i + 1;
    }
    sort(price_hair.begin(), price_hair.end());
    reverse(price_hair.begin(), price_hair.end());
	// продавать волосы по самой выгодной цене
	// обновлять данные о длине волос
	// продолжать
	for (size_t i = 0; i < n; i++) {
        int hl = std::max(price_hair[i].second - prodano, 0); // длина волос в i-ый день
        sum += price_hair[i].first * hl; // добавляем деньги от продажи волос в этот день
        prodano += hl; // сколько мы продали в этот день
	}
    cout << sum << "\n";
    return 0;
}