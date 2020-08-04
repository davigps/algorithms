#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e8
#define MAXN 100100
int dp[MAXN], numberOfCoins, value;
vector<int> coins;

// Iterative Solution O(numberOfCoins * value)
int solve() {
    // Answer for value 0 is 0 coins
    dp[0] = 0;
    
    // For each integer until value
    // calculate its minimum number of coins to reach at
    for (int x = 1; x <= value; x++) {
        // Default value is a neutral one, so INFinity
        dp[x] = INF;
        // For each coin, calculate its quantity if possible
        for (auto coin: coins) {
            if (x - coin >= 0)
                // The best quantity for current value is the
                // minimum of some previous answer or the current + 1.
                dp[x] = min(dp[x], dp[x - coin] + 1);
        }
    }
    
    // After all, return the best answer for initial value.
    return dp[value];
}

int main() {
    cin >> numberOfCoins >> value;
    
    for(int i = 0; i < numberOfCoins; i++) {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    
    cout << "Minimum number of coins: " << solve() << endl;

    return 0;
}

