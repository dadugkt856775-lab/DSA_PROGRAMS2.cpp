#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);

    for (long long &x : a)
        cin >> x;

    long long currentMax = a[0];
    long long currentMin = a[0];
    long long answer = a[0];

    for (int i = 1; i < n; i++) {
        long long x = a[i];

        if (x < 0)
            swap(currentMax, currentMin);

        currentMax = max(x, currentMax * x);
        currentMin = min(x, currentMin * x);

        answer = max(answer, currentMax);
    }

    cout << "Maximum Product: "
         << answer << endl;

    return 0;
}
