#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    for (int &x : h) cin >> x;

    stack<int> st;
    int maximum = 0;

    for (int i = 0; i <= n; i++) {
        int current = (i == n ? 0 : h[i]);

        while (!st.empty() && h[st.top()] > current) {
            int height = h[st.top()];
            st.pop();

            int width = st.empty()
                ? i
                : i - st.top() - 1;

            maximum = max(maximum, height * width);
        }

        st.push(i);
    }

    cout << "Largest Rectangle Area: "
         << maximum << endl;

    return 0;
}
