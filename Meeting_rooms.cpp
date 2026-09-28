#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> meetings = {
        {0, 30},
        {5, 10},
        {15, 20}
    };

    sort(meetings.begin(), meetings.end());

    priority_queue<int, vector<int>, greater<int>> rooms;

    for (auto& meeting : meetings) {
        if (!rooms.empty() && rooms.top() <= meeting[0])
            rooms.pop();

        rooms.push(meeting[1]);
    }

    cout << "Minimum Rooms Required: " << rooms.size();

    return 0;
}
