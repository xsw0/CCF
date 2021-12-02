#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<int, int> m;

    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        ++m[a];
    }

    pair<int, int> maximum = *m.cbegin();
    for (auto &p : m)
    {
        if (p.second > maximum.second)
        {
            maximum = p;
        }
    }

    cout << maximum.first << endl;

    return 0;
}
