#include <iostream>

using namespace std;

int main() {
    int capacity, items;

    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    cout << "Enter the number of items: ";
    cin >> items;

    int price[items + 1];
    int wt[items + 1];

    cout << "Enter the prices of items:" << endl;
    for (int i = 1; i <= items; i++) {
        cin >> price[i];
    }

    cout << "Enter the weights of items:" << endl;
    for (int i = 1; i <= items; i++) {
        cin >> wt[i];
    }

    int dp[items + 1][capacity + 1];

    for (int i = 0; i <= items; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                // There's nothing to add to the knapsack
                dp[i][j] = 0;
            } else if (wt[i] <= j) {
                // Choose previously maximum or value of the current item + value of the remaining weight
                dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j - wt[i]]);
            } else {
                // Add the previously added item to the knapsack
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << "Maximum Profit Earned: " << dp[items][capacity] << "\n";
    return 0;
}
