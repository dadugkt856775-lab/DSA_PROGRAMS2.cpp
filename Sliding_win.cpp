#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int &x : a)
        cin >> x;

    multiset<int> window;

    for (int i = 0; i < n; i++) {
        window.insert(a[i]);

        if (window.size() > k)
            window.erase(window.find(a[i - k]));

        if (window.size() == k) {
            auto it = next(
                window.begin(),
                (k - 1) / 2
            );

            if (k % 2 == 1) {
                cout << *it << " ";
            }
            else {
                auto it2 = next(it);

                double median =
                    (*it + *it2) / 2.0;

                cout << fixed << setprecision(1)
                     << median << " ";
            }
        }
    }

    cout << endl;

    return 0;
}
