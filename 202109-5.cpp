// 40

#include "bits/stdc++.h"

using namespace std;

struct Person
{
    size_t start;
    size_t end;
    uint64_t pow;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t m;
    uint64_t p;
    bool T;
    uint64_t A = 0;
    cin >> m >> p >> T;

    vector<vector<Person>> rank(m);
    size_t count = 0;
    auto search = [&](size_t r, size_t s)
    {
        auto &v = rank[r];
        auto right = upper_bound(v.begin(),
                                 v.end(),
                                 s,
                                 [](size_t value, const Person &element) -> bool
                                 { return value < element.start; });

        auto left = upper_bound(v.begin(),
                                right,
                                s,
                                [](size_t value, const Person &element) -> bool
                                { return value < element.end; });
        return left < right ? left : v.end();
    };

    for (size_t i = 0; i != m; ++i)
    {
        int op;
        cin >> op;
        switch (op)
        {
        case 1: {
            uint64_t x;
            cin >> x;
            x ^= A;
            x %= p;
            if (x)
            {
                rank[count].push_back({i, numeric_limits<size_t>::max(), x});
                ++count;
            }
            else
            {
                --count;
                rank[count].back().end = i;
            }
            break;
        }
        case 2: {
            size_t s, l, r;
            uint64_t y;
            cin >> s >> l >> r >> y;
            --s, --l;
            y ^= A;
            y %= p;

            for (size_t i = l; i != r; ++i)
            {
                auto it = search(i, s);
                assert(it != rank[i].end());
                it->pow *= y;
                it->pow %= p;
            }
            break;
        }
        case 3: {
            uint64_t sum = 0;
            size_t s, l, r;
            cin >> s >> l >> r;
            --s, --l;

            for (size_t i = l; i != r; ++i)
            {
                auto it = search(i, s);
                assert(it != rank[i].end());
                sum += it->pow;
                sum %= p;
            }

            if (T) A = sum;
            cout << sum << "\n";
            break;
        }
        default:
            break;
        }
    }

    return 0;
}
