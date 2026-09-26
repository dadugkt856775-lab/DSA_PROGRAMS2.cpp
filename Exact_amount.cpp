#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, amount;
    cin >> n >> amount;

    vector<int> coins(n);

    for (int &x : coins)
        cin >> x;

    const int INF = 1e9;

    vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INF) {
                dp[i] = min(
                    dp[i],
                    dp[i - coin] + 1
                );
            }
        }
    }

    if (dp[amount] == INF)
        cout << "Amount Cannot Be Formed" << endl;
    else
        cout << "Minimum Coins: "
             << dp[amount] << endl;

    return 0;
}
