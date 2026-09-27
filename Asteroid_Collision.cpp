#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> asteroids = {5, 10, -5};
    vector<int> st;

    for (int x : asteroids) {
        bool destroyed = false;

        while (!st.empty() && x < 0 && st.back() > 0) {
            if (st.back() < -x) {
                st.pop_back();
            }
            else if (st.back() == -x) {
                st.pop_back();
                destroyed = true;
                break;
            }
            else {
                destroyed = true;
                break;
            }
        }

        if (!destroyed)
            st.push_back(x);
    }

    cout << "Remaining Asteroids: ";
    for (int x : st)
        cout << x << " ";

    return 0;
}
