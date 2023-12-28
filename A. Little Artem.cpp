#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _


    int n, r, c;

    cin >> n;

    while (n--)
    {
        cin >> r >> c;

        bool row = false, col = false;

        if (!(r % 2)) row = true;
        else if (!(c % 2)) col = true;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (row)
                {
                    if(!(i % 2) || (j == 0 && i == 1)) cout << 'B';
                    else cout << 'W';
                }

                else if (col)
                {
                    if(!(j % 2) || (i == 0 && j == 1)) cout << 'B';
                    else cout << 'W';
                }

                else
                {
                    if (i == 0)
                    {
                        if (!(j % 2)) cout << 'B';
                        else cout << 'W';
                    }

                    else
                    {
                        if (i % 2) cout << 'B';
                        else cout << 'W';
                    }
                }
            }

            cout << '\n';

        }

        }
}
