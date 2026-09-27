#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> buildings = {
        {2, 9, 10},
        {3, 7, 15},
        {5, 12, 12},
        {15, 20, 10},
        {19, 24, 8}
    };

    vector<pair<int, int>> events;

    for (auto& b : buildings) {
        int left = b[0];
        int right = b[1];
        int height = b[2];

        events.push_back({left, -height});
        events.push_back({right, height});
    }

    sort(events.begin(), events.end());

    multiset<int> heights;
    heights.insert(0);

    int previousMax = 0;

    cout << "Skyline: ";

    for (int i = 0; i < events.size(); ) {
        int x = events[i].first;

        while (i < events.size() && events[i].first == x) {
            int h = events[i].second;

            if (h < 0)
                heights.insert(-h);
            else
                heights.erase(heights.find(h));

            i++;
        }

        int currentMax = *heights.rbegin();

        if (currentMax != previousMax) {
            cout << "(" << x << ", " << currentMax << ") ";
            previousMax = currentMax;
        }
    }

    return 0;
}
