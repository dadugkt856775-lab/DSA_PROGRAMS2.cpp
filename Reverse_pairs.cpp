#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(vector<int>& a, int left, int mid, int right) {
    long long count = 0;
    int j = mid + 1;

    for (int i = left; i <= mid; i++) {
        while (j <= right && (long long)a[i] > 2LL * a[j])
            j++;

        count += j - (mid + 1);
    }

    vector<int> temp;
    int i = left;
    j = mid + 1;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }

    while (i <= mid)
        temp.push_back(a[i++]);

    while (j <= right)
        temp.push_back(a[j++]);

    for (int k = left; k <= right; k++)
        a[k] = temp[k - left];

    return count;
}

long long merge
