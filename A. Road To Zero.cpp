#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() { _

    int t;
    cin >> t;

    while(t--)
    {
        long long x, y, a, b, m;
        cin >> x >> y >> a >> b;

        m = min((abs(x - y) * a) + (min(x,y) * b), ((x + y) * a));

        cout << m << '\n';

    }
}
