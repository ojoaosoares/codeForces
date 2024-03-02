#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() { _

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> coins(n);

        for (int i = 1; i <= n; i++)
           coins[i - 1] = (int) pow(2, i);

        int s1 = 0, s2 = 0, cont = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1) s1 += coins[i];

            if (s2 + coins[i] <= s1 && cont < n / 2)
            {
                s2 += coins[i];
                cont++;
            }
            else s1 += coins[i];

        }

        cout << abs(s1 - s2) << '\n';
    }
}
