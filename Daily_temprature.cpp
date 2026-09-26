#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};

    int n = temp.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {

        while (!st.empty() && temp[i] > temp[st.top()]) {
            int index = st.top();
            st.pop();

            ans[index] = i - index;
        }

        st.push(i);
    }

    cout << "Days to wait: ";

    for (int x : ans)
        cout << x << " ";

    return 0;
}
