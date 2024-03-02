#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> classroom(n, vector<char>(m));

    int occupied = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> classroom[i][j];

            if (classroom[i][j] == '*') occupied++;
        }

    int sum = 0, left, right;

    if (k == 1)
        sum += (n * m) - occupied;
        
    else 
    {
        for (int i = 0; i < n; i++)
        {
            left = 0; right = 0;

            while (true)
            {
                if (right >= m)
                {
                    sum += max(right - left - k + 1, 0);
                    break;
                }

                else if (classroom[i][right] == '*')
                {
                    sum += max(right - left - k + 1, 0);
                    left = ++right;
                }

                else right++;

            }
        }

        for (int i = 0; i < m; i++)
        {
            left = 0; right = 0;

            while (true)
            {
                if (right >= n)
                {
                    sum += max(right - left - k + 1, 0);
                    break;
                }

                else if (classroom[right][i] == '*')
                {
                    sum += max(right - left - k + 1, 0);
                    left = ++right;
                }

                else right++;

            }
        }
    }
    
    cout << sum << '\n';
}
