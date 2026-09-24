#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> words(n);

    for (string &word : words)
        cin >> word;

    unordered_set<char> chars;

    for (auto &word : words)
        for (char c : word)
            chars.insert(c);

    vector<vector<int>> graph(26);
    vector<int> indegree(26, 0);

    for (int i = 0; i < n - 1; i++) {
        string a = words[i];
        string b = words[i + 1];

        int len = min(a.size(), b.size());

        for (int j = 0; j < len; j++) {
            if (a[j] != b[j]) {
                int u = a[j] - 'a';
                int v = b[j] - 'a';

                graph[u].push_back(v);
                indegree[v]++;

                break;
            }
        }
    }

    queue<int> q;

    for (char c : chars) {
        if (indegree[c - 'a'] == 0)
            q.push(c - 'a');
    }

    string order;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        order += char(u + 'a');

        for (int v : graph[u]) {
            indegree[v]--;

            if (indegree[v] == 0)
                q.push(v);
        }
    }

    if (order.size() != chars.size())
        cout << "Invalid Dictionary" << endl;
    else
        cout << "Alien Alphabet: " << order << endl;

    return 0;
}
