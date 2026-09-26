#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right) {
        if (a[left] <= a[right]) {
            if (a[left] >= leftMax)
                leftMax = a[left];
            else
                water += leftMax - a[left];

            left++;
        } else {
            if (a[right] >= rightMax)
                rightMax = a[right];
            else
                water += rightMax - a[right];

            right--;
        }
    }

    cout << "Trapped Water: " << water << endl;

    return 0;
}
