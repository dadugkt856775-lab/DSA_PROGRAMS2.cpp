#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
    int g, f;

    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(
        n,
        vector<int>(m)
    );

    for (auto &row : grid)
        for (int &x : row)
            cin >> x;

    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    auto heuristic = [&](int x, int y) {
        return abs(x - tx) + abs(y - ty);
    };

    const int INF = 1e9;

    vector<vector<int>> dist(
        n,
        vector<int>(m, INF)
    );

    priority_queue<
        Node,
        vector<Node>,
        greater<Node>
    > pq;

    dist[sx][sy] = 0;

    pq.push({
        sx,
        sy,
        0,
        heuristic(sx, sy)
    });

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int x = current.x;
        int y = current.y;

        if (x == tx && y == ty) {
            cout << "Shortest Path Cost: "
                 << current.g << endl;
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n ||
                ny < 0 || ny >= m ||
                grid[nx][ny] == 1)
                continue;

            int newCost = current.g + 1;

            if (newCost < dist[nx][ny]) {
                dist[nx][ny] = newCost;

                pq.push({
                    nx,
                    ny,
                    newCost,
                    newCost + heuristic(nx, ny)
                });
            }
        }
    }

    cout << "Path Not Found" << endl;

    return 0;
}
