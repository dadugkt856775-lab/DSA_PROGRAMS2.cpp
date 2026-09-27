#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {2, -1, 2};
    int K = 3;

    int n = a.size();
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + a[i];

    deque<int> dq;
    int answer = n + 1;

    for (int i = 0; i <= n; i++) {

        while (!dq.empty() && prefix[i] - prefix[dq.front()] >= K) {
            answer = min(answer, i - dq.front());
            dq.pop_front();
        }

        while (!dq.empty() && prefix[i] <= prefix[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    if (answer == n + 1)
        answer = -1;

    cout << "Shortest Length: " << answer;

    return 0;
}
