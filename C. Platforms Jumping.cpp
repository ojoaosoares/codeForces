#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    long long width, plat, jump;
    cin >> width >> plat >> jump;

    vector<long long> p(plat);

    int max = 0;
    for (long long i = 0; i < plat; i++)
    {
        cin >> p[i];
        max += p[i];
    }

    vector<long long> river(width, 0);

    long long i = jump - 1, j = 0;

    bool possible = true;
    while (i < width - max)
    {
        if(j == plat)
        {
            possible = false;
            break;
        }

        for (long long k = i; k < i + p[j]; k++)
            river[k] = j + 1;


        i += (p[j] - 1) + jump;
        max -= p[j];
        j++;
    }

    if(j < plat)
        i = width - max;

    for ( ; j < plat; j++)
    {
        long long start = i;
        for ( ; i < start + p[j] ; i++)
            river[i] = j + 1;
    }

    if(possible)
    {
        cout << "YES\n";

        for (long long i = 0; i < width; i++)
            cout << river[i] << ' ';

        cout << '\n';
    }

    else cout << "NO\n";
}
