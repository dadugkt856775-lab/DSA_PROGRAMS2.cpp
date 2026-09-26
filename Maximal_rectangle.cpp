#include <bits/stdc++.h>
using namespace std;

int largestRectangle(vector<int>& h) {
    stack<int> st;
    int ans = 0;
    int n = h.size();

    for (int i = 0; i <= n; i++) {
        int current = (i == n ? 0 : h[i]);

        while (!st.empty() && h[st.top()] > current) {
            int height = h[st.top()];
            st.pop();

            int width = st.empty()
                ? i
                : i - st.top() - 1;

            ans = max(ans, height * width);
        }

        st.push(i);
    }

    return ans;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<int> height(cols, 0);
    int answer = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int x;
            cin >> x;

            if (x == 1)
                height[j]++;
            else
                height[j] = 0;
        }

        answer = max(answer, largestRectangle(height));
    }

    cout << "Maximum Rectangle Area: "
         << answer << endl;

    return 0;
}
