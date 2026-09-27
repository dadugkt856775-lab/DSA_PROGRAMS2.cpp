#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<pair<int, int>>& a,
               vector<int>& count,
               int left, int right) {

    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(a, count, left, mid);
    mergeSort(a, count, mid + 1, right);

    vector<pair<int, int>> temp;

    int i = left;
    int j = mid + 1;
    int smaller = 0;

    while (i <= mid && j <= right) {

        if (a[j].first < a[i].first) {
            temp.push_back(a[j]);
            smaller++;
            j++;
        }
        else {
            count[a[i].second] += smaller;
            temp.push_back(a[i]);
            i++;
        }
    }

    while (i <= mid) {
        count[a[i].second] += smaller;
        temp.push_back(a[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(a[j]);
        j++;
    }

    for (int k = left; k <= right; k++)
        a[k] = temp[k - left];
}

int main() {
    vector<int> nums = {5, 2, 6, 1};

    int n = nums.size();

    vector<pair<int, int>> a;
    vector<int> count(n, 0);

    for (int i = 0; i < n; i++)
        a.push_back({nums[i], i});

    mergeSort(a, count, 0, n - 1);

    cout << "Count of Smaller Elements: ";

    for (int x : count)
        cout << x << " ";

    return 0;
}
