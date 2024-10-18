#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void findUniqueCombinations(int amount, vector<int>& coins, vector<int>& combination, int index, set<vector<int>>& unique_combinations) {
    if (amount == 0) {
        vector<int> sorted_combination = combination;
        sort(sorted_combination.begin(), sorted_combination.end());
        unique_combinations.insert(sorted_combination);
        return;
    }

    if (amount < 0) {
        return;
    }

    for (int i = index; i < coins.size(); ++i) {
        combination.push_back(coins[i]);
        findUniqueCombinations(amount - coins[i], coins, combination, i, unique_combinations);
        combination.pop_back();
    }
}

int main() {
    int amount;
    cout << "Please enter the total amount (rial): ";
    cin >> amount;

    vector<int> coins = {2, 5, 10};
    vector<int> combination;
    set<vector<int>> unique_combinations;

    findUniqueCombinations(amount, coins, combination, 0, unique_combinations);

    cout << "Unique combinations:" << endl;
    for (const auto& comb : unique_combinations) {
        int count_2 = 0, count_5 = 0, count_10 = 0;

        for (int coin : comb) {
            if (coin == 2) count_2++;
            else if (coin == 5) count_5++;
            else if (coin == 10) count_10++;
        }

        cout << "number of 2 rial coins: " << count_2 << endl;
        cout << "number of 5 rial coins: " << count_5 << endl;
        cout << "number of 10 rial coins: " << count_10 << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}