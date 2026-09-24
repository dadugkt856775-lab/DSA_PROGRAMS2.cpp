#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> s;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    int longest = 0;

    for (int x : s) {
        if (!s.count(x - 1)) {
            int current = x;
            int length = 1;

            while (s.count(current + 1)) {
                current++;
                length++;
            }

            longest = max(longest, length);
        }
    }

    cout << "Longest Consecutive Length: "
         << longest << endl;

    return 0;
}
