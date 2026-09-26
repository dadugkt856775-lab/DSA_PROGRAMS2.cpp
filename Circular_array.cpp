#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 1, 3, 0, 2};
    int n = a.size();

    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--) {
        int index = i % n;

        while (!st.empty() && st.top() <= a[index])
            st.pop();

        if (i < n && !st.empty())
            ans[index] = st.top();

        st.push(a[index]);
    }

    cout << "Next Greater Elements: ";

    for (int x : ans)
        cout << x << " ";

    return 0;
}
